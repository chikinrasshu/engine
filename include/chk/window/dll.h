#pragma once

#include <chk/core/dllbase.h>

#ifdef WINDOW_DLL
#ifdef WINDOW_DLL_EXPORTS
#define WINDOW_API HELPER_DLL_EXPORT
#else
#define WINDOW_API HELPER_DLL_IMPORT
#endif
#define WINDOW_LOCAL HELPER_DLL_LOCAL
#else
#define WINDOW_API
#define WINDOW_LOCAL
#endif
