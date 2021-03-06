#ifndef _call_stack_entry
#define _call_stack_entry

#include "main.h"

class CallStackEntry {
public:
  CallStackEntry(u32 p_va, u32 p_jva) : va_(p_va), jva_(p_jva) {}
  ~CallStackEntry() {}

  u32 va() { return va_; }
  u32 jva() { return jva_; }

private:
  // 呼び出し元
  u32 va_;
  // ジャンプ先
  u32 jva_;
};

#endif // _call_stack_entry
