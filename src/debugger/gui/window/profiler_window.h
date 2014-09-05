#ifndef _debugger_gui_profiler
#define _debugger_gui_profiler

#include "debugger/gui/list_window_base.h"

class ProfilerWindow : public ListWindowBase {
public:
  enum {
    kLabelHeight = 16,
#ifdef _ENV2
    kViewX = 710 + 150,
    kViewY = 820 + 40,
    kViewW = 320,
    kViewH = 0,
#else
    kViewX = 1206,
    kViewY = 50,
    kViewW = 341,
    kViewH = 260,
#endif
  };

  enum {
    kPopupMenu_OpenDialog = WM_USER,
    kPopupMenu_ToggleState,
    kPopupMenu_Delete,
  };

// constructor/destructor
public:
  ProfilerWindow();
  ~ProfilerWindow();

// override
public:
  virtual void Init();
  virtual bool PreTranslateMessage(MSG* p_msg);
  virtual void Draw();

protected:
  virtual int  GetListHeaderTop() { return 0; }
  virtual int  GetListTop() { return kLabelHeight; }
  virtual int  GetAllLine();
  //virtual int  GetPageLine();
  //virtual void InitScroll();
  //virtual void SetScrollMax(int p_line_count);
  virtual void SortListData(QSORT_FUNC p_sort_func);

// event handler
public:
  //void OnInitDialog(HWND p_hwnd);
  //void OnActivate(int p_active, int p_minimized, int p_hwnd_pre);
  void OnCommand(int p_ctrlID, int p_notify);
  void OnShowWindow(WPARAM p_wp, LPARAM p_lp);
  //void OnSize(WPARAM p_wp, LPARAM p_lp);
  //void OnVScroll(WPARAM p_wp, LPARAM p_lp);
  //void OnPaint(WPARAM p_wp, LPARAM p_lp);
  //void OnMouseWheel(WPARAM p_wp, LPARAM p_lp);
  //void OnMouseMove(int p_x, int p_y);
  //void OnLButtonDown(int p_x, int p_y);
  //void OnLButtonDblClk(int p_x, int p_y);
  //void OnLButtonUp(int p_x, int p_y);
  void OnRButtonDown(int p_x, int p_y);
  void OnKeyDown(u32 p_vk, bool p_ctrl, bool p_shift);
  //void OnDrawItem(int p_ctrlID, DRAWITEMSTRUCT* p_di);
  //void OnMenuSelect(int p_menu_id, int p_menu_flag, HMENU p_menu_handle);

  //void OnClear();

// member funtion
public:
  void add_entry(ProfileEntry* p_data);
  void remove_entry(ProfileEntry* p_data);
  void update_list();

private:

// member variable
private:
  vector<ProfileEntry*>  m_sorted_ary;
};

#endif _debugger_gui_profiler
