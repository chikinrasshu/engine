#pragma once

#include <chk/code/dll.h>

#include <chk/core/core.h>

typedef struct ChkCode {
  void* handle;
} ChkCode;

CHK_CODE_API b32 chkCodeCreate(ChkCode* code, cstr caption);
CHK_CODE_API b32 chkCodeDestroy(ChkCode* code);
CHK_CODE_API b32 chkCodeRefresh(ChkCode* code);