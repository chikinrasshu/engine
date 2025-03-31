#pragma once

#include <chk/code/dll.h>

#include <chk/core/core.h>

typedef struct Code {
  void* handle;
} Code;

CODE_API B32 Code_Create(Code* code, CStr caption);
CODE_API B32 Code_Destroy(Code* code);
CODE_API B32 Code_Refresh(Code* code);
