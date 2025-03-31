#include <chk/core/core.h>

#include <chk/code/code.h>
#include <chk/draw/draw.h>
#include <chk/window/window.h>

typedef struct ChkEngine {
  int32_t exitCode;

  // ChkMemory     memory;
  ChkCode   code;
  ChkDraw   draw;
  ChkWindow window;
} ChkEngine;

void onFrame(void* userPtr) {
  ChkEngine* engine = userPtr;
  if (!engine) return;

  ChkCode*   code   = &engine->code;
  ChkDraw*   draw   = &engine->draw;
  ChkWindow* window = &engine->window;

  // Do something...
  b32 reloaded = chkCodeRefresh(code);
  (void)reloaded;

  chkDrawBeginFrame(draw);

  chkDrawViewport(draw, 0, 0, window->fb_w, window->fb_h);
  chkDrawClear(draw, 0.1f, 0.2f, 0.3f);

  chkDrawEndFrame(draw);
}

int32_t main() {
  ChkEngine engine = {0};
  engine.exitCode  = 1;

  if (chkCodeCreate(&engine.code, "plugins/base/menu")) {
    if (chkWindowCreate(&engine.window, 800, 600, "chk_engine")) {
      if (chkDrawCreate(&engine.draw)) {
        chkWindowSetUserData(&engine.window, &engine);
        chkWindowSetOnFrame(&engine.window, onFrame);

        engine.exitCode = chkWindowRun(&engine.window);

        chkDrawDestroy(&engine.draw);
      }
      chkWindowDestroy(&engine.window);
    }
    chkCodeDestroy(&engine.code);
  }

  return engine.exitCode;
}
