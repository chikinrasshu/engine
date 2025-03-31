#include <chk/draw/draw.h>

#include <epoxy/gl.h>

#include <assert.h>

void Draw_Apply_Viewport(Draw* draw, DrawCmd_Viewport* cmd) {
  assert(cmd->kind == DrawCmdKind_Viewport);
  glViewport(cmd->x, cmd->y, cmd->w, cmd->h);
}

void Draw_Apply_Clear(Draw* draw, DrawCmd_Clear* cmd) {
  assert(cmd->kind == DrawCmdKind_Clear);
  glClearColor(cmd->r, cmd->g, cmd->b, 1.0f);
}

void Draw_Apply_Rect(Draw* draw, DrawCmd_Rect* cmd) {
  assert(cmd->kind == DrawCmdKind_Rect);
  // glClearColor(cmd->r, cmd->g, cmd->b, 1.0f);
}
