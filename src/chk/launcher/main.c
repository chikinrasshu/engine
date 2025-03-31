#include <chk/core/core.h>

#include <chk/code/code.h>
#include <chk/draw/draw.h>
#include <chk/window/window.h>

typedef struct Engine {
  int32_t exitCode;

  // Memory     memory;
  Code   code;
  Draw   draw;
  Window window;
} Engine;

void onFrame(void* userPtr) {
  Engine* engine = userPtr;
  if (!engine) return;

  Code*   code   = &engine->code;
  Draw*   draw   = &engine->draw;
  Window* window = &engine->window;

  // Do something...
  B32 reloaded = Code_Refresh(code);
  (void)reloaded;

  F32 ww = window->fb_w;
  F32 wh = window->fb_h;

  Draw_BeginFrame(draw);

  Draw_PushViewport(draw, (DrawCmd_Viewport){.w = ww, .h = wh});
  Draw_PushClear(draw, (DrawCmd_Clear){.r = 0.1f, .g = 0.2f, .b = 0.3f});

  Draw_EndFrame(draw);
}

int32_t main() {
  Engine engine   = {0};
  engine.exitCode = 1;

  if (Code_Create(&engine.code, "plugins/base/menu")) {
    if (Window_Create(&engine.window, 800, 600, "chk_engine")) {
      if (Draw_Create(&engine.draw)) {
        Window_SetUserData(&engine.window, &engine);
        Window_SetOnFrame(&engine.window, onFrame);

        engine.exitCode = Window_Run(&engine.window);

        Draw_Destroy(&engine.draw);
      }
      Window_Destroy(&engine.window);
    }
    Code_Destroy(&engine.code);
  }

  return engine.exitCode;
}
