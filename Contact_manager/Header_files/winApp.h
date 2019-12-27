#pragma once

#include "wx/wx.h"
#include "winMain.h"

class winApp : public wxApp{
	public:
	 winApp();
	 ~winApp();

	private:
	 winMain* m_frame1 = nullptr;

	public:
	 virtual bool OnInit();

};