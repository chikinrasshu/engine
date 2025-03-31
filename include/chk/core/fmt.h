#pragma once

#include <chk/core/dll.h>

#include <chk/core/types.h>

CHK_CORE_API b32 chkFmt(str buf, size_t size, cstr msg, ...);
CHK_CORE_API b32 chkFmtV(str buf, size_t size, cstr msg, va_list args);
