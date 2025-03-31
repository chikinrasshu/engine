#pragma once

#include <chk/window/dll.h>

#include <chk/core/core.h>

typedef struct Window {
  F32 x, y, w, h;
  F32 fb_x, fb_y, fb_w, fb_h;
  F32 dpi_x, dpi_y;
  F32 dt, ct, lt;

  Callback* onFrame;

  void* userData;
  void* handle;
} Window;

WINDOW_API B32 Window_Create(Window* window, S32 w, S32 h, CStr title);
WINDOW_API B32 Window_Destroy(Window* window);

WINDOW_API S32 Window_Step(Window* window, B32 poll_events);
WINDOW_API S32 Window_Run(Window* window);

WINDOW_API B32 Window_SetUserData(Window* window, void* ptr);
WINDOW_API B32 Window_SetOnFrame(Window* window, Callback* fn);
