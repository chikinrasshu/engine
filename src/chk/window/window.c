#include <chk/window/window.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static S32 Window_Count = 0;

WINDOW_LOCAL B32 Window_Push(void) {
  if (Window_Count == 0 && !glfwInit()) return false;
  ++Window_Count;
  return true;
}

WINDOW_LOCAL B32 Window_Pop(void) {
  if (Window_Count == 1) { glfwTerminate(); }
  --Window_Count;
  return true;
}

WINDOW_LOCAL void WindowCb_OnFrame(GLFWwindow* handle);
WINDOW_LOCAL void WindowCb_OnPos(GLFWwindow* handle, S32 x, S32 y);
WINDOW_LOCAL void WindowCb_OnSize(GLFWwindow* handle, S32 w, S32 h);
WINDOW_LOCAL void WindowCb_OnFbSize(GLFWwindow* handle, S32 w, S32 h);
WINDOW_LOCAL void WindowCb_OnDpi(GLFWwindow* handle, F32 x, F32 y);

WINDOW_LOCAL B32 Window_BindCallbacks(Window* window) {
  GLFWwindow* handle = window->handle;

  glfwSetWindowUserPointer(handle, window);
  glfwSetWindowRefreshCallback(handle, WindowCb_OnFrame);
  glfwSetWindowPosCallback(handle, WindowCb_OnPos);
  glfwSetWindowSizeCallback(handle, WindowCb_OnSize);
  glfwSetFramebufferSizeCallback(handle, WindowCb_OnFbSize);
  glfwSetWindowContentScaleCallback(handle, WindowCb_OnDpi);

  return true;
}

WINDOW_LOCAL B32 Window_GetDefaults(Window* window) {
  GLFWwindow* handle = window->handle;

  S32 tmp_a, tmp_b;
  F32 tmp_c, tmp_d;

  glfwGetWindowPos(handle, &tmp_a, &tmp_b);
  window->x = (F32)tmp_a, window->y = (F32)tmp_b;
  glfwGetWindowSize(handle, &tmp_a, &tmp_b);
  window->w = (F32)tmp_a, window->h = (F32)tmp_b;
  glfwGetFramebufferSize(handle, &tmp_a, &tmp_b);
  window->fb_x = (F32)0, window->fb_y = (F32)0;
  window->fb_w = (F32)tmp_a, window->fb_h = (F32)tmp_b;
  glfwGetWindowContentScale(handle, &tmp_c, &tmp_d);
  window->dpi_x = (F32)tmp_c, window->dpi_y = (F32)tmp_d;

  return true;
}

WINDOW_API B32 Window_Create(Window* window, S32 w, S32 h, CStr caption) {
  if (!Window_Push()) return false;

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
  Window_BindCallbacks(window);
  Window_GetDefaults(window);

  return true;
}

WINDOW_API B32 Window_Destroy(Window* window) {
  glfwDestroyWindow(window->handle);

  if (!Window_Pop()) return false;
  return true;
}

WINDOW_API S32 Window_Step(Window* window, S32 poll_events) {
  if (poll_events) glfwPollEvents();
  if (glfwWindowShouldClose(window->handle)) return 0;

  if (window->onFrame) window->onFrame(window->userData);

  glfwSwapBuffers(window->handle);
  window->ct = (F32)glfwGetTime();
  if (window->ct >= 120.0f) {
    window->ct -= 60.0f;
    window->lt -= 60.0f;
    glfwSetTime((F64)window->ct);
  }

  window->dt = window->ct - window->lt;
  window->lt = window->ct;

  return 0;
}

WINDOW_API S32 Window_Run(Window* window) {
  S32 exitCode = 1;

  glfwShowWindow(window->handle);
  while (!glfwWindowShouldClose(window->handle))
    exitCode = Window_Step(window, true);

  return exitCode;
}

WINDOW_API B32 Window_SetUserData(Window* window, void* ptr) {
  if (!window) return false;

  window->userData = ptr;

  return true;
}

WINDOW_API B32 Window_SetOnFrame(Window* window, Callback* fn) {
  if (!window) return false;

  window->onFrame = fn;

  return true;
}

// Callbacks

WINDOW_LOCAL void WindowCb_OnFrame(GLFWwindow* handle) {
  Window* window = glfwGetWindowUserPointer(handle);
  Window_Step(window, false);
}

WINDOW_LOCAL void WindowCb_OnPos(GLFWwindow* handle, S32 x, S32 y) {
  Window* window = glfwGetWindowUserPointer(handle);
  window->x = (F32)x, window->y = (F32)y;
}

WINDOW_LOCAL void WindowCb_OnSize(GLFWwindow* handle, S32 w, S32 h) {
  Window* window = glfwGetWindowUserPointer(handle);
  window->w = (F32)w, window->h = (F32)h;
}

WINDOW_LOCAL void WindowCb_OnFbSize(GLFWwindow* handle, S32 w, S32 h) {
  Window* window = glfwGetWindowUserPointer(handle);
  window->fb_w = (F32)w, window->fb_h = (F32)h;
}

WINDOW_LOCAL void WindowCb_OnDpi(GLFWwindow* handle, F32 x, F32 y) {
  Window* window = glfwGetWindowUserPointer(handle);
  window->dpi_x = (F32)x, window->dpi_y = (F32)y;
}