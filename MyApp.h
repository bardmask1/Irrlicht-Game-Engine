#pragma once

#include <wx/wx.h>

#include "MainFrame.h"


class MyApp : public wxApp
{
public:
	bool OnInit() wxOVERRIDE;
};

wxDECLARE_APP(MyApp);
wxIMPLEMENT_APP(MyApp);

