#pragma once

#include <chk/core/dllbase.h>

#ifdef CHK_CODE_DLL
#ifdef CHK_CODE_DLL_EXPORTS
#define CHK_CODE_API CHK_HELPER_DLL_EXPORT
#else
#define CHK_CODE_API CHK_HELPER_DLL_IMPORT
#endif
#define CHK_CODE_LOCAL CHK_HELPER_DLL_LOCAL
#else
#define CHK_CODE_API
#define CHK_CODE_LOCAL
#endif
