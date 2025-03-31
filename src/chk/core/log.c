#include <chk/core/fmt.h>
#include <chk/core/log.h>
#include <chk/core/utils.h>

#include <cwalk.h>

#include <stdio.h>
#include <stdlib.h>

CHK_CORE_LOCAL cstr chkLogSevToCStr(ChkLogSev sev) {
  switch (sev) {
    case ChkLogSev_Debug: return "Debug";
    case ChkLogSev_Trace: return "Trace";
    case ChkLogSev_Info:  return "Info";
    case ChkLogSev_Warn:  return "Warn";
    case ChkLogSev_Error: return "Error";
    case ChkLogSev_Fatal: return "Fatal";
  }

  return "Unkn";
}

CHK_CORE_LOCAL cstr chkLogSevToAnsi(ChkLogSev sev) {
  switch (sev) {
    case ChkLogSev_Debug: return "\x1b[2;39m";
    case ChkLogSev_Trace: return "\x1b[2;34m";
    case ChkLogSev_Info:  return "\x1b[34m";
    case ChkLogSev_Warn:  return "\x1b[33m";
    case ChkLogSev_Error: return "\x1b[31m";
    case ChkLogSev_Fatal: return "\x1b[1;31m";
  }

  return NULL;
}

CHK_CORE_API b32 impl_chkLog(ChkLogSev sev, cstr msg, cstr file, cstr func,
                             u32 line) {
  cstr sev_name = chkLogSevToCStr(sev);
  cstr sev_ansi = chkLogSevToAnsi(sev);
  cstr msg_beg  = sev_ansi ? sev_ansi : "";
  cstr msg_end  = sev_ansi ? "\x1b[0m" : "";

  cstr file_name = file;

  struct cwk_segment seg;
  if (cwk_path_get_last_segment(file, &seg)) {
    if (cwk_path_get_previous_segment(&seg)) { file_name = seg.begin; }
  }

  static char buf[1024];
  chkFmt(buf, chkCountOf(buf), "%s[%s] [%s:%d:%s] %s%s\n", //
         msg_beg, sev_name, file_name, line, func, msg, msg_end);
  fputs(buf, stderr);

  if (sev == ChkLogSev_Fatal) { exit(1); }
  return true;
}

CHK_CORE_API b32 impl_chkLogF(ChkLogSev sev, cstr msg, cstr file, cstr func,
                              u32 line, ...) {
  static char buf[1024];

  va_list args;
  va_start(args, line);
  b32 result = chkFmtV(buf, chkCountOf(buf), msg, args);
  va_end(args);

  return result && impl_chkLog(sev, buf, file, func, line);
}
