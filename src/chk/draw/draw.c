#include <chk/draw/draw.h>

#include <epoxy/gl.h>

CHK_DRAW_API b32 chkDrawCreate(ChkDraw* draw) {
  // TODO(chk): create me?
  draw->_unused = 420;

  return true;
}

CHK_DRAW_API b32 chkDrawDestroy(ChkDraw* draw) {
  // TODO(chk): delete me?

  return true;
}

// Frame commands

CHK_DRAW_API b32 chkDrawBeginFrame(ChkDraw* draw) {
  // TODO(chk): implement the command list!
  return true;
}

CHK_DRAW_API b32 chkDrawEndFrame(ChkDraw* draw) {
  // TODO(chk): implement the command list!
  return true;
}

// Draw commands

CHK_DRAW_API b32 chkDrawViewport(ChkDraw* draw, f32 x, f32 y, f32 w, f32 h) {
  // TODO(chk): implement the command list!
  glViewport((GLint)x, (GLint)y, (GLsizei)w, (GLsizei)h);
  return true;
}

CHK_DRAW_API b32 chkDrawClear(ChkDraw* draw, f32 r, f32 g, f32 b) {
  // TODO(chk): implement the command list!
  glClearColor(r, g, b, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  return true;
}
