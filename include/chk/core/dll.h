#pragma once

#include <chk/core/dllbase.h>

#ifdef CORE_DLL
#ifdef CORE_DLL_EXPORTS
#define CORE_API HELPER_DLL_EXPORT
#else
#define CORE_API HELPER_DLL_IMPORT
#endif
#define CORE_LOCAL HELPER_DLL_LOCAL
#else
#define CORE_API
#define CORE_LOCAL
#endif
