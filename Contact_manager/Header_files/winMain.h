#pragma once

#include "wx/wx.h"

class winMain : public wxFrame {
	public:
	 winMain();
	 ~winMain();
	public:
	 wxButton *make_btn = nullptr;
	 wxButton *find_btn = nullptr;
	 wxButton *delete_btn = nullptr;
	 wxTextCtrl *input_txt = nullptr;
	 wxListBox *output_list = nullptr;

	 void make_btnClicked(wxCommandEvent &evt);
	 void find_btnClicked(wxCommandEvent &evt);
	 void delete_btnClicked(wxCommandEvent &evt);

	 wxDECLARE_EVENT_TABLE();
};
