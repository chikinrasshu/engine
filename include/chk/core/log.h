#pragma once

#include <chk/core/dll.h>

#include <chk/core/types.h>

typedef enum LogSev {
  LogSev_Debug = 1,
  LogSev_Trace,
  LogSev_Info,
  LogSev_Warn,
  LogSev_Error,
  LogSev_Fatal,

  LogSev_Count,
} LogSev;

CORE_API B32 Impl_Log(LogSev sev, CStr msg, CStr file, CStr fn, U32 line);
CORE_API B32 Impl_LogF(LogSev sev, CStr msg, CStr file, CStr fn, U32 line, ...);

#define Log_Debug(msg, ...)                                                    \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Debug, (msg), __FILE__, __func__,          \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Trace(msg, ...)                                                    \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Trace, (msg), __FILE__, __func__,          \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Info(msg, ...)                                                     \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Info, (msg), __FILE__, __func__,           \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Warn(msg, ...)                                                     \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Warn, (msg), __FILE__, __func__,           \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Error(msg, ...)                                                    \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Error, (msg), __FILE__, __func__,          \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Fatal(msg, ...)                                                    \
  impl_Log##__VA_OPT__(F)(ChkLogSev_Fatal, (msg), __FILE__, __func__,          \
                          __LINE__ __VA_OPT__(, ) __VA_ARGS__)
