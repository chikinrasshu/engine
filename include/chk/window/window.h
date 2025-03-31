#pragma once

#include <chk/window/dll.h>

#include <chk/core/core.h>

typedef struct ChkWindow {
  f32 x, y, w, h;
  f32 fb_x, fb_y, fb_w, fb_h;
  f32 dpi_x, dpi_y;
  f32 dt, ct, lt;

  ChkCallback* onFrame;

  void* userData;
  void* handle;
} ChkWindow;

CHK_WINDOW_API b32 chkWindowCreate(ChkWindow* window, s32 w, s32 h, cstr title);
CHK_WINDOW_API b32 chkWindowDestroy(ChkWindow* window);

CHK_WINDOW_API s32 chkWindowStep(ChkWindow* window, b32 poll_events);
CHK_WINDOW_API s32 chkWindowRun(ChkWindow* window);

CHK_WINDOW_API b32 chkWindowSetUserData(ChkWindow* window, void* ptr);
CHK_WINDOW_API b32 chkWindowSetOnFrame(ChkWindow* window, ChkCallback* fn);
