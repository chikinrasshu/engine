#include <chk/draw/draw.h>

#include <epoxy/gl.h>

DRAW_API B32 Draw_PushViewport(Draw* draw, DrawCmd_Viewport cmd) {
  // TODO(chk): implement the command list!
  glViewport((GLint)cmd.x, (GLint)cmd.y, (GLsizei)cmd.w, (GLsizei)cmd.h);
  return true;
}

DRAW_API B32 Draw_PushClear(Draw* draw, DrawCmd_Clear cmd) {
  // TODO(chk): implement the command list!
  glClearColor(cmd.r, cmd.g, cmd.b, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  return true;
}

DRAW_API B32 Draw_PushRect(Draw* draw, DrawCmd_Rect cmd) {
  // TODO(chk): implement the command list!
  return true;
}
