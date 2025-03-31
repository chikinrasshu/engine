#pragma once

#include <chk/core/dllbase.h>

#ifdef CHK_WINDOW_DLL
#ifdef CHK_WINDOW_DLL_EXPORTS
#define CHK_WINDOW_API CHK_HELPER_DLL_EXPORT
#else
#define CHK_WINDOW_API CHK_HELPER_DLL_IMPORT
#endif
#define CHK_WINDOW_LOCAL CHK_HELPER_DLL_LOCAL
#else
#define CHK_WINDOW_API
#define CHK_WINDOW_LOCAL
#endif
