#pragma once

#include <chk/core/dllbase.h>

#ifdef CODE_DLL
#ifdef CODE_DLL_EXPORTS
#define CODE_API HELPER_DLL_EXPORT
#else
#define CODE_API HELPER_DLL_IMPORT
#endif
#define CODE_LOCAL HELPER_DLL_LOCAL
#else
#define CODE_API
#define CODE_LOCAL
#endif
