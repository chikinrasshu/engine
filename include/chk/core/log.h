#pragma once

#include <chk/core/dll.h>

#include <chk/core/types.h>

typedef enum ChkLogSev {
  ChkLogSev_Debug,
  ChkLogSev_Trace,
  ChkLogSev_Info,
  ChkLogSev_Warn,
  ChkLogSev_Error,
  ChkLogSev_Fatal,
} ChkLogSev;

CHK_CORE_API b32 impl_chkLog(ChkLogSev sev, cstr msg, cstr file, cstr func,
                             u32 line);
CHK_CORE_API b32 impl_chkLogF(ChkLogSev sev, cstr msg, cstr file, cstr func,
                              u32 line, ...);

#define chkLogDebug(msg, ...)                                                  \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Debug, (msg), __FILE__, __func__,       \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define chkLogTrace(msg, ...)                                                  \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Trace, (msg), __FILE__, __func__,       \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define chkLogInfo(msg, ...)                                                   \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Info, (msg), __FILE__, __func__,        \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define chkLogWarn(msg, ...)                                                   \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Warn, (msg), __FILE__, __func__,        \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define chkLogError(msg, ...)                                                  \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Error, (msg), __FILE__, __func__,       \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define chkLogFatal(msg, ...)                                                  \
  impl_chkLog##__VA_OPT__(F)(ChkLogSev_Fatal, (msg), __FILE__, __func__,       \
                             __LINE__ __VA_OPT__(, ) __VA_ARGS__)
