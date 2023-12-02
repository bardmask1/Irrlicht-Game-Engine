#pragma once
#include <windows.h>
#include <irrlicht.h>
#include <wx/wx.h>
#include <wx/toolbar.h>

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif


using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;


class wxIrrlicht : public wxControl {
public:
    wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs = true, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr);
    ~wxIrrlicht();

    void InitIrr(irr::SIrrlichtCreationParameters* init_params = 0);
    void StartRendering(int milliseconds = 10);
    void StopRendering();
    void Render();
    virtual void OnCreateScene();
    virtual void OnPreRender() {}
    virtual void OnRender();
    virtual void OnPostRender();

    irr::IrrlichtDevice* GetDevice() const { return m_pDevice; }
    irr::video::IVideoDriver* GetVideoDriver() const { return m_pDriver; }
    irr::scene::ISceneManager* GetSceneManager() const { return m_pSceneManager; }
    irr::scene::ICameraSceneNode* GetCameraNode() const { return m_pCameraNode; }
    irr::gui::IGUIEnvironment* GetGuiEnvironment() const { return m_pGuiEnvironment; }

public:
    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event) {}
    void OnTimer(wxTimerEvent& event);
    void OnMouse(wxMouseEvent& event);
    void OnKey(wxKeyEvent& event);

    irr::IrrlichtDevice* m_pDevice;
    irr::video::IVideoDriver* m_pDriver;
    irr::scene::ISceneManager* m_pSceneManager;
    irr::gui::IGUIEnvironment* m_pGuiEnvironment;
    irr::scene::ICameraSceneNode* m_pCameraNode;
    wxTimer m_Timer;
    irr::gui::IGUIStaticText* m_pFPSText;
    bool m_showFPS;

    enum {
        ID_IRR_TIMER = 1000
    };

private:
    DECLARE_EVENT_TABLE();

};//wxIrrlicht
