#include <chk/window/window.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static s32 chkWindowCount = 0;

CHK_WINDOW_LOCAL b32 chkWindowPush(void) {
  if (chkWindowCount == 0 && !glfwInit()) return false;
  ++chkWindowCount;
  return true;
}

CHK_WINDOW_LOCAL b32 chkWindowPop(void) {
  if (chkWindowCount == 1) { glfwTerminate(); }
  --chkWindowCount;
  return true;
}

CHK_WINDOW_LOCAL void chkWindowCbOnFrame(GLFWwindow* handle);
CHK_WINDOW_LOCAL void chkWindowCbOnPos(GLFWwindow* handle, s32 x, s32 y);
CHK_WINDOW_LOCAL void chkWindowCbOnSize(GLFWwindow* handle, s32 w, s32 h);
CHK_WINDOW_LOCAL void chkWindowCbOnFbSize(GLFWwindow* handle, s32 w, s32 h);
CHK_WINDOW_LOCAL void chkWindowCbOnDpi(GLFWwindow* handle, s32 x, s32 y);

CHK_WINDOW_LOCAL b32 chkWindowBindCallbacks(ChkWindow* window) {
  GLFWwindow* handle = window->handle;

  glfwSetWindowUserPointer(handle, window);
  glfwSetWindowRefreshCallback(handle, chkWindowCbOnFrame);
  glfwSetWindowPosCallback(handle, chkWindowCbOnPos);
  glfwSetWindowSizeCallback(handle, chkWindowCbOnSize);
  glfwSetFramebufferSizeCallback(handle, chkWindowCbOnFbSize);
  glfwSetWindowContentScaleCallback(handle, chkWindowCbOnDpi);

  return true;
}

CHK_WINDOW_LOCAL b32 chkWindowGetDefaults(ChkWindow* window) {
  GLFWwindow* handle = window->handle;

  s32 tmp_a, tmp_b;
  f32 tmp_c, tmp_d;

  glfwGetWindowPos(handle, &tmp_a, &tmp_b);
  window->x = (f32)tmp_a, window->y = (f32)tmp_b;
  glfwGetWindowSize(handle, &tmp_a, &tmp_b);
  window->w = (f32)tmp_a, window->h = (f32)tmp_b;
  glfwGetFramebufferSize(handle, &tmp_a, &tmp_b);
  window->fb_x = (f32)0, window->fb_y = (f32)0;
  window->fb_w = (f32)tmp_a, window->fb_h = (f32)tmp_b;
  glfwGetWindowContentScale(handle, &tmp_c, &tmp_d);
  window->dpi_x = (f32)tmp_c, window->dpi_y = (f32)tmp_d;

  return true;
}

CHK_WINDOW_API b32 chkWindowCreate(ChkWindow* window, s32 w, s32 h,
                                   cstr caption) {
  if (!chkWindowPush()) return false;

  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

  GLFWwindow* handle = glfwCreateWindow(w, h, caption, NULL, NULL);
  if (!handle) return false;
  glfwMakeContextCurrent(handle);

  window->handle = handle;
  chkWindowBindCallbacks(window);
  chkWindowGetDefaults(window);

  return true;
}

CHK_WINDOW_API b32 chkWindowDestroy(ChkWindow* window) {
  glfwDestroyWindow(window->handle);

  if (!chkWindowPop()) return false;
  return true;
}

CHK_WINDOW_API s32 chkWindowStep(ChkWindow* window, s32 poll_events) {
  if (poll_events) glfwPollEvents();
  if (glfwWindowShouldClose(window->handle)) return 0;

  if (window->onFrame) window->onFrame(window->userData);

  glfwSwapBuffers(window->handle);
  window->ct = (f32)glfwGetTime();
  if (window->ct >= 120.0f) {
    window->ct -= 60.0f;
    window->lt -= 60.0f;
    glfwSetTime((f64)window->ct);
  }

  window->dt = window->ct - window->lt;
  window->lt = window->ct;

  return 0;
}

CHK_WINDOW_API s32 chkWindowRun(ChkWindow* window) {
  s32 exitCode = 1;

  glfwShowWindow(window->handle);
  while (!glfwWindowShouldClose(window->handle))
    exitCode = chkWindowStep(window, true);

  return exitCode;
}

CHK_WINDOW_API b32 chkWindowSetUserData(ChkWindow* window, void* ptr) {
  if (!window) return false;

  window->userData = ptr;

  return true;
}

CHK_WINDOW_API b32 chkWindowSetOnFrame(ChkWindow* window, ChkCallback* fn) {
  if (!window) return false;

  window->onFrame = fn;

  return true;
}

// Callbacks

CHK_WINDOW_LOCAL void chkWindowCbOnFrame(GLFWwindow* handle) {
  ChkWindow* window = glfwGetWindowUserPointer(handle);
  chkWindowStep(window, false);
}

CHK_WINDOW_LOCAL void chkWindowCbOnPos(GLFWwindow* handle, s32 x, s32 y) {
  ChkWindow* window = glfwGetWindowUserPointer(handle);
  window->x = (f32)x, window->y = (f32)y;
}

CHK_WINDOW_LOCAL void chkWindowCbOnSize(GLFWwindow* handle, s32 w, s32 h) {
  ChkWindow* window = glfwGetWindowUserPointer(handle);
  window->w = (f32)w, window->h = (f32)h;
}

CHK_WINDOW_LOCAL void chkWindowCbOnFbSize(GLFWwindow* handle, s32 w, s32 h) {
  ChkWindow* window = glfwGetWindowUserPointer(handle);
  window->fb_w = (f32)w, window->fb_h = (f32)h;
}

CHK_WINDOW_LOCAL void chkWindowCbOnDpi(GLFWwindow* handle, s32 x, s32 y) {
  ChkWindow* window = glfwGetWindowUserPointer(handle);
  window->dpi_x = (f32)x, window->dpi_y = (f32)y;
}