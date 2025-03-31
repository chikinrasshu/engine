#include <chk/core/fmt.h>
#include <chk/core/log.h>
#include <chk/core/utils.h>

#include <cwalk.h>

#include <stdio.h>
#include <stdlib.h>

CORE_LOCAL CStr LogSevToCStr(LogSev sev) {
  switch (sev) {
    case LogSev_Count: return "Unkn";

    case LogSev_Debug: return "Debug";
    case LogSev_Trace: return "Trace";
    case LogSev_Info:  return "Info";
    case LogSev_Warn:  return "Warn";
    case LogSev_Error: return "Error";
    case LogSev_Fatal: return "Fatal";
  }

  return "Unkn";
}

CORE_LOCAL CStr LogSevToAnsi(LogSev sev) {
  switch (sev) {
    case LogSev_Count: return NULL;

    case LogSev_Debug: return "\x1b[2;39m";
    case LogSev_Trace: return "\x1b[2;34m";
    case LogSev_Info:  return "\x1b[34m";
    case LogSev_Warn:  return "\x1b[33m";
    case LogSev_Error: return "\x1b[31m";
    case LogSev_Fatal: return "\x1b[1;31m";
  }

  return NULL;
}

CORE_API B32 impl_Log(LogSev sev, CStr msg, CStr file, CStr fn, U32 line) {
  CStr sev_name = LogSevToCStr(sev);
  CStr sev_ansi = LogSevToAnsi(sev);
  CStr msg_beg  = sev_ansi ? sev_ansi : "";
  CStr msg_end  = sev_ansi ? "\x1b[0m" : "";

  CStr file_name = file;

  struct cwk_segment seg;
  if (cwk_path_get_last_segment(file, &seg)) {
    if (cwk_path_get_previous_segment(&seg)) { file_name = seg.begin; }
  }

  static char buf[1024];
  Fmt(buf, CountOf(buf), "%s[%s] [%s:%d:%s] %s%s\n", //
      msg_beg, sev_name, file_name, line, fn, msg, msg_end);
  fputs(buf, stderr);

  if (sev == LogSev_Fatal) { exit(1); }
  return true;
}

CORE_API B32 impl_LogF(LogSev sev, CStr msg, CStr file, CStr fn, U32 line,
                       ...) {
  static char buf[1024];

  va_list args;
  va_start(args, line);
  B32 result = FmtV(buf, CountOf(buf), msg, args);
  va_end(args);

  return result && impl_Log(sev, buf, file, fn, line);
}
