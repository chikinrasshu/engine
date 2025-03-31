#pragma once

#include <chk/core/dllbase.h>

#ifdef CHK_CORE_DLL
#ifdef CHK_CORE_DLL_EXPORTS
#define CHK_CORE_API CHK_HELPER_DLL_EXPORT
#else
#define CHK_CORE_API CHK_HELPER_DLL_IMPORT
#endif
#define CHK_CORE_LOCAL CHK_HELPER_DLL_LOCAL
#else
#define CHK_CORE_API
#define CHK_CORE_LOCAL
#endif
