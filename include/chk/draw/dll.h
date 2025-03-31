#pragma once

#include <chk/core/dllbase.h>

#ifdef DRAW_DLL
#ifdef DRAW_DLL_EXPORTS
#define DRAW_API HELPER_DLL_EXPORT
#else
#define DRAW_API HELPER_DLL_IMPORT
#endif
#define DRAW_LOCAL HELPER_DLL_LOCAL
#else
#define DRAW_API
#define DRAW_LOCAL
#endif
