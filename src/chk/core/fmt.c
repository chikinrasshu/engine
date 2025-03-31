#include <chk/core/fmt.h>

#include <stdio.h>

CORE_API B32 Fmt(Str buf, size_t size, CStr msg, ...) {
  va_list args;
  va_start(args, msg);
  B32 result = FmtV(buf, size, msg, args);
  va_end(args);

  return result;
}

CORE_API B32 FmtV(Str buf, size_t size, CStr msg, va_list args) {
  va_list args_copy;
  va_copy(args_copy, args);
  size_t written = vsnprintf(buf, size, msg, args_copy);
  va_end(args_copy);

  return written > 0 && written <= size;
}
