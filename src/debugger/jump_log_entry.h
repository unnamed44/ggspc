#ifndef _jump_log_entry
#define _jump_log_entry

#include "main.h"
#include "stlp_wrapper.h"

struct JumpLogRepeat {
  int  count;  // 繰り返し数
  int  len;  // 繰り返し長
};

class JumpLogEntry {
// constructor/destructor
public:
  enum {
    kGroupMaxLen = 64  // グループ化可能な繰り返し長
  };

  JumpLogEntry(u32 p_va) {
    m_va = p_va;
  }
  ~JumpLogEntry() {
    for (vector<JumpLogRepeat*>::iterator itr = m_repeat.begin();
        itr != m_repeat.end();
        ++itr) {
      delete *itr;
    }
    m_repeat.clear();
  }

// accessor
public:
  inline u32 va() { return m_va; }

// member variable
private:
public:
  u32              m_va;
  vector<JumpLogRepeat*>  m_repeat;
};

#endif // _jump_log_entry
