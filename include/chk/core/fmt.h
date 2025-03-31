#pragma once

#include <chk/core/dll.h>

#include <chk/core/types.h>

CORE_API B32 Fmt(Str buf, Size size, CStr msg, ...);
CORE_API B32 FmtV(Str buf, Size size, CStr msg, Args args);
