#include <chk/draw/draw.h>

#include <epoxy/gl.h>

DRAW_API B32 Draw_Create(Draw* draw) {
  // TODO(chk): create me?
  draw->_unused = 420;

  return true;
}

DRAW_API B32 Draw_Destroy(Draw* draw) {
  // TODO(chk): delete me?

  return true;
}

// Frame commands

DRAW_API B32 Draw_BeginFrame(Draw* draw) {
  // TODO(chk): implement the command list!
  return true;
}

DRAW_API B32 Draw_EndFrame(Draw* draw) {
  // TODO(chk): implement the command list!
  return true;
}
