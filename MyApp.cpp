#include "MyApp.h"


bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    wxFrame* frame = new MainFrame(NULL,
        wxID_ANY,
        "wxAUI Sample Application",
        wxDefaultPosition,
        wxWindow::FromDIP(wxSize(800, 600), NULL));
    frame->Show();

    return true;
}