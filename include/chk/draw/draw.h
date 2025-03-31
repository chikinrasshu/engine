#pragma once

#include <chk/draw/dll.h>

#include <chk/core/core.h>

// #include <chk/draw/cmd.h>

typedef struct ChkDraw {
  s32 _unused;
} ChkDraw;

CHK_DRAW_API b32 chkDrawCreate(ChkDraw* draw);
CHK_DRAW_API b32 chkDrawDestroy(ChkDraw* draw);

CHK_DRAW_API b32 chkDrawBeginFrame(ChkDraw* draw);
CHK_DRAW_API b32 chkDrawEndFrame(ChkDraw* draw);

CHK_DRAW_API b32 chkDrawViewport(ChkDraw* draw, f32 x, f32 y, f32 w, f32 h);
CHK_DRAW_API b32 chkDrawClear(ChkDraw* draw, f32 r, f32 g, f32 b);
