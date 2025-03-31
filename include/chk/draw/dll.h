#pragma once

#include <chk/core/dllbase.h>

#ifdef CHK_DRAW_DLL
#ifdef CHK_DRAW_DLL_EXPORTS
#define CHK_DRAW_API CHK_HELPER_DLL_EXPORT
#else
#define CHK_DRAW_API CHK_HELPER_DLL_IMPORT
#endif
#define CHK_DRAW_LOCAL CHK_HELPER_DLL_LOCAL
#else
#define CHK_DRAW_API
#define CHK_DRAW_LOCAL
#endif
