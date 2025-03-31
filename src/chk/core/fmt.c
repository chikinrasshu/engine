#include <chk/core/fmt.h>

#include <stdio.h>

CHK_CORE_API b32 chkFmt(str buf, size_t size, cstr msg, ...) {
  va_list args;
  va_start(args, msg);
  b32 result = chkFmtV(buf, size, msg, args);
  va_end(args);

  return result;
}

CHK_CORE_API b32 chkFmtV(str buf, size_t size, cstr msg, va_list args) {
  va_list args_copy;
  va_copy(args_copy, args);
  size_t written = vsnprintf(buf, size, msg, args_copy);
  va_end(args_copy);

  return written > 0 && written <= size;
}
