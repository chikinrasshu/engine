#pragma once

#include <chk/draw/dll.h>

#include <chk/core/core.h>

typedef enum DrawCmdKind {
  DrawCmdKind_Viewport = 1,
  DrawCmdKind_Clear,
  DrawCmdKind_Rect,

  DrawCmdKind_Count,
} DrawCmdKind;

typedef struct DrawCmd_Viewport {
  DrawCmdKind kind;

  F32 x, y, w, h;
} DrawCmd_Viewport;

typedef struct DrawCmd_Clear {
  DrawCmdKind kind;

  F32 r, g, b;
} DrawCmd_Clear;

typedef struct DrawCmd_Rect {
  DrawCmdKind kind;

  F32 r, g, b;
  F32 x, y, w, h;
} DrawCmd_Rect;

typedef struct Draw {
  S32 _unused;
} Draw;

DRAW_API B32 Draw_Create(Draw* draw);
DRAW_API B32 Draw_Destroy(Draw* draw);

DRAW_API B32 Draw_BeginFrame(Draw* draw);
DRAW_API B32 Draw_EndFrame(Draw* draw);

DRAW_API B32 Draw_PushViewport(Draw* draw, DrawCmd_Viewport cmd);
DRAW_API B32 Draw_PushClear(Draw* draw, DrawCmd_Clear cmd);
DRAW_API B32 Draw_PushRect(Draw* draw, DrawCmd_Rect cmd);

DRAW_API void Draw_Apply_Viewport(Draw* draw, DrawCmd_Viewport* cmd);
DRAW_API void Draw_Apply_Clear(Draw* draw, DrawCmd_Clear* cmd);
DRAW_API void Draw_Apply_Rect(Draw* draw, DrawCmd_Rect* cmd);
