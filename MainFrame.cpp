

#include "MainFrame.h"

#pragma region event tables
wxBEGIN_EVENT_TABLE(wxSizeReportCtrl, wxControl)
	EVT_PAINT(wxSizeReportCtrl::OnPaint)
	EVT_SIZE(wxSizeReportCtrl::OnSize)
	EVT_ERASE_BACKGROUND(wxSizeReportCtrl::OnEraseBackground)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_ERASE_BACKGROUND(MainFrame::OnEraseBackground)
    EVT_SIZE(MainFrame::OnSize)
    EVT_MENU(MainFrame::ID_CreateTree, MainFrame::OnCreateTree)
    EVT_MENU(MainFrame::ID_CreateText, MainFrame::OnCreateText)
    EVT_MENU(MainFrame::ID_CreateHTML, MainFrame::OnCreateHTML)
    EVT_MENU(MainFrame::ID_CreateSizeReport, MainFrame::OnCreateSizeReport)
    EVT_MENU(MainFrame::ID_CreateIrrlicht, MainFrame::OnCreateIrrlicht)
    EVT_MENU(MainFrame::ID_CreateNotebook, MainFrame::OnCreateNotebook)
    EVT_MENU(MainFrame::ID_CreatePerspective, MainFrame::OnCreatePerspective)
    EVT_MENU(MainFrame::ID_CopyPerspectiveCode, MainFrame::OnCopyPerspectiveCode)
    EVT_MENU(ID_AllowFloating, MainFrame::OnManagerFlag)
    EVT_MENU(ID_TransparentHint, MainFrame::OnManagerFlag)
    EVT_MENU(ID_VenetianBlindsHint, MainFrame::OnManagerFlag)
    EVT_MENU(ID_RectangleHint, MainFrame::OnManagerFlag)
    EVT_MENU(ID_NoHint, MainFrame::OnManagerFlag)
    EVT_MENU(ID_HintFade, MainFrame::OnManagerFlag)
    EVT_MENU(ID_NoVenetianFade, MainFrame::OnManagerFlag)
    EVT_MENU(ID_TransparentDrag, MainFrame::OnManagerFlag)
    EVT_MENU(ID_LiveUpdate, MainFrame::OnManagerFlag)
    EVT_MENU(ID_AllowActivePane, MainFrame::OnManagerFlag)
    EVT_MENU(ID_NotebookTabFixedWidth, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookNoCloseButton, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookCloseButton, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookCloseButtonAll, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookCloseButtonActive, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookAllowTabMove, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookAllowTabExternalMove, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookAllowTabSplit, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookScrollButtons, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookWindowList, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookArtGloss, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookArtSimple, MainFrame::OnNotebookFlag)
    EVT_MENU(ID_NotebookAlignTop, MainFrame::OnTabAlignment)
    EVT_MENU(ID_NotebookAlignBottom, MainFrame::OnTabAlignment)
    EVT_MENU(ID_NoGradient, MainFrame::OnGradient)
    EVT_MENU(ID_VerticalGradient, MainFrame::OnGradient)
    EVT_MENU(ID_HorizontalGradient, MainFrame::OnGradient)
    EVT_MENU(ID_AllowToolbarResizing, MainFrame::OnToolbarResizing)
    EVT_MENU(ID_Settings, MainFrame::OnSettings)
    EVT_MENU(ID_CustomizeToolbar, MainFrame::OnCustomizeToolbar)
    EVT_MENU(ID_TreeContent, MainFrame::OnChangeContentPane)
    EVT_MENU(ID_TextContent, MainFrame::OnChangeContentPane)
    EVT_MENU(ID_SizeReportContent, MainFrame::OnChangeContentPane)
    EVT_MENU(ID_IrrlichtContent, MainFrame::OnChangeContentPane)
    EVT_MENU(ID_HTMLContent, MainFrame::OnChangeContentPane)
    EVT_MENU(ID_NotebookContent, MainFrame::OnChangeContentPane)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    // custom events
    EVT_MENU(ID_SampleItem + 1, MainFrame::OnCreateCube)
    EVT_MENU(ID_SampleItem + 2, MainFrame::OnCreateSphere)
    EVT_MENU(ID_SampleItem + 3, MainFrame::OnCreateCylinder)
    EVT_MENU(ID_SampleItem + 4, MainFrame::OnCreatePlane)
    EVT_MENU(ID_GridToggle, MainFrame::ToggleGrid)

    EVT_UPDATE_UI(ID_NotebookTabFixedWidth, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookNoCloseButton, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookCloseButton, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookCloseButtonAll, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookCloseButtonActive, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookAllowTabMove, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookAllowTabExternalMove, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookAllowTabSplit, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookScrollButtons, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NotebookWindowList, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_AllowFloating, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_TransparentHint, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_VenetianBlindsHint, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_RectangleHint, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NoHint, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_HintFade, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NoVenetianFade, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_TransparentDrag, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_LiveUpdate, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_NoGradient, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_VerticalGradient, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_HorizontalGradient, MainFrame::OnUpdateUI)
    EVT_UPDATE_UI(ID_AllowToolbarResizing, MainFrame::OnUpdateUI)
    EVT_MENU_RANGE(MainFrame::ID_FirstPerspective, MainFrame::ID_FirstPerspective + 1000,
        MainFrame::OnRestorePerspective)
    EVT_AUITOOLBAR_TOOL_DROPDOWN(ID_DropDownToolbarItem, MainFrame::OnDropDownToolbarItem)
    EVT_AUI_PANE_CLOSE(MainFrame::OnPaneClose)
    EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, MainFrame::OnAllowNotebookDnD)
    EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, MainFrame::OnNotebookPageClose)
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, MainFrame::OnNotebookPageClosed)
    EVT_AUINOTEBOOK_PAGE_CHANGING(wxID_ANY, MainFrame::OnNotebookPageChanging)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(SettingsPanel, wxPanel)
    EVT_SPINCTRL(ID_PaneBorderSize, SettingsPanel::OnPaneBorderSize)
    EVT_SPINCTRL(ID_SashSize, SettingsPanel::OnSashSize)
    EVT_SPINCTRL(ID_CaptionSize, SettingsPanel::OnCaptionSize)
    EVT_BUTTON(ID_BackgroundColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_SashColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_InactiveCaptionColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_InactiveCaptionGradientColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_InactiveCaptionTextColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_ActiveCaptionColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_ActiveCaptionGradientColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_ActiveCaptionTextColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_BorderColor, SettingsPanel::OnSetColor)
    EVT_BUTTON(ID_GripperColor, SettingsPanel::OnSetColor)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(wxIrrlicht, wxControl)
    EVT_TIMER(ID_IRR_TIMER, wxIrrlicht::OnTimer)
    EVT_SIZE(wxIrrlicht::OnSize)
    EVT_PAINT(wxIrrlicht::OnPaint)
    EVT_ERASE_BACKGROUND(wxIrrlicht::OnEraseBackground)
    EVT_MOUSE_EVENTS(wxIrrlicht::OnMouse)
    EVT_KEY_DOWN(wxIrrlicht::OnKey)
    EVT_KEY_UP(wxIrrlicht::OnKey)
wxEND_EVENT_TABLE()
#pragma endregion


MainFrame::MainFrame(wxWindow* parent, 
        wxWindowID id, 
        const wxString& title, 
        const wxPoint& pos, 
        const wxSize& size, 
        long style)
    : wxFrame(parent, id, title, pos, size, style)
{
        wxInitAllImageHandlers();


    // tell wxAuiManager to manage this frame
    m_mgr.SetManagedWindow(this);

    wxTopLevelWindow::SetIcon(wxIcon("irr_ico"));
    

    // create menu

    wxMenuBar* mb = new wxMenuBar;

    wxMenu* file_menu = new wxMenu;
    file_menu->Append(ID_Empty, "New...");
    file_menu->Append(ID_Empty, "Open");
    file_menu->AppendSeparator();
    file_menu->Append(ID_Empty, "Save");
    file_menu->Append(ID_Empty, "Save As");
    file_menu->AppendSeparator();
    file_menu->Append(ID_Empty, "Import");
    file_menu->Append(ID_Empty, "Export");
    file_menu->Append(wxID_EXIT);

    wxMenu* view_menu = new wxMenu;
    view_menu->Append(ID_CreateTree, _("Show Heirarchy"));
    view_menu->Append(ID_CreateSizeReport, _("Show Size Reporter"));

    wxMenu* options_menu = new wxMenu;
    wxMenuItem* gridOption = options_menu->AppendCheckItem(ID_GridToggle, _("Use Grid"));
    gridOption->Check(true);
    options_menu->AppendRadioItem(ID_TransparentHint, _("Transparent Hint"));
    options_menu->AppendRadioItem(ID_VenetianBlindsHint, _("Venetian Blinds Hint"));
    options_menu->AppendRadioItem(ID_RectangleHint, _("Rectangle Hint"));
    options_menu->AppendRadioItem(ID_NoHint, _("No Hint"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_HintFade, _("Hint Fade-in"));
    options_menu->AppendCheckItem(ID_AllowFloating, _("Allow Floating"));
    options_menu->AppendCheckItem(ID_NoVenetianFade, _("Disable Venetian Blinds Hint Fade-in"));
    options_menu->AppendCheckItem(ID_TransparentDrag, _("Transparent Drag"));
    options_menu->AppendCheckItem(ID_AllowActivePane, _("Allow Active Pane"));
    // Only show "live resize" toggle if it's actually functional.
    if (!wxAuiManager::AlwaysUsesLiveResize())
        options_menu->AppendCheckItem(ID_LiveUpdate, _("Live Resize Update"));
    options_menu->AppendSeparator();
    options_menu->AppendRadioItem(ID_NoGradient, _("No Caption Gradient"));
    options_menu->AppendRadioItem(ID_VerticalGradient, _("Vertical Caption Gradient"));
    options_menu->AppendRadioItem(ID_HorizontalGradient, _("Horizontal Caption Gradient"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_AllowToolbarResizing, _("Allow Toolbar Resizing"));
    options_menu->AppendSeparator();
    options_menu->Append(ID_Settings, _("Settings Pane"));

    m_perspectives_menu = new wxMenu;
    m_perspectives_menu->Append(ID_CreatePerspective, _("Create Perspective"));
    m_perspectives_menu->Append(ID_CopyPerspectiveCode, _("Copy Perspective Data To Clipboard"));
    m_perspectives_menu->AppendSeparator();
    m_perspectives_menu->Append(ID_FirstPerspective + 0, _("Default Startup"));
    m_perspectives_menu->Append(ID_FirstPerspective + 1, _("All Panes"));

    wxMenu* help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);

    mb->Append(file_menu, _("&File"));
    mb->Append(view_menu, _("&View"));
    mb->Append(m_perspectives_menu, _("&Perspectives"));
    mb->Append(options_menu, _("&Options"));
    mb->Append(help_menu, _("&Help"));

    SetMenuBar(mb);

    CreateStatusBar();
    GetStatusBar()->SetStatusText(_("Ready"));

    // min size for the frame itself isn't completely done.
    // see the end up wxAuiManager::Update() for the test
    // code. For now, just hard code a frame minimum size
    SetMinSize(FromDIP(wxSize(800, 600)));

    wxAuiToolBarItemArray prepend_items;
    wxAuiToolBarItemArray append_items;
    wxAuiToolBarItem item;
    item.SetKind(wxITEM_SEPARATOR);
    append_items.Add(item);
    item.SetKind(wxITEM_NORMAL);
    item.SetId(ID_CustomizeToolbar);
    item.SetLabel(_("Customize..."));
    append_items.Add(item);

    // create some toolbars
    wxAuiToolBar* tb1 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
    tb1->AddTool(ID_SampleItem + 1, "Cube", wxImage("Assets/Editor/icons/mesh_cube.png", wxBITMAP_TYPE_PNG));
    tb1->AddTool(ID_SampleItem + 2, "Sphere", wxImage("Assets/Editor/icons/mesh_sphere.png", wxBITMAP_TYPE_PNG));
    tb1->AddTool(ID_SampleItem + 3, "Cylinder", wxImage("Assets/Editor/icons/mesh_cylinder.png", wxBITMAP_TYPE_PNG));
    tb1->AddTool(ID_SampleItem + 4, "Plane", wxImage("Assets/Editor/icons/mesh_plane.png", wxBITMAP_TYPE_PNG));
    tb1->Realize();

    // add the toolbars to the manager
    m_mgr.AddPane(tb1, wxAuiPaneInfo().
        Name("Create").Caption("Create Object").
        ToolbarPane().Top());

    // add a bunch of panes
    m_mgr.AddPane(CreateIrrlicht(), wxAuiPaneInfo().Name("SceneWindow").Caption("Scene").
        CloseButton(true).MaximizeButton(true).CenterPane().Show());

    sceneDisplay = new SceneDisplay(irrlichtWindow);

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
        Name("Inspector").Caption("Inspector").
        Right().Row(1).
        CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
        Name("Resource").Caption("Resource Browser").
        Bottom().Layer(0).
        CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
        Name("Console").Caption("Console").
        Bottom().Layer(0).
        CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().
        Name("Hierarchy").Caption("Hierarchy").
        Left().Layer(0).Position(1).
        CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(new SettingsPanel(this, this), wxAuiPaneInfo().
        Name("settings").Caption("Dock Manager Settings").
        Dockable(false).Float().Hide());


    
    // make some default perspectives

    wxString perspective_all = m_mgr.SavePerspective();

    int i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
        if (!all_panes.Item(i).IsToolbar())
            all_panes.Item(i).Hide();
    m_mgr.GetPane("Hierarchy").Show().Left().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("Inspector").Show().Right().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("Console").Show().Bottom().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("Resource").Show().Bottom().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("SceneWindow").Show();
    wxString perspective_default = m_mgr.SavePerspective();

    m_perspectives.Add(perspective_default);
    m_perspectives.Add(perspective_all);

    // "commit" all changes made to wxAuiManager
    m_mgr.Update();

}

wxAuiDockArt* MainFrame::GetDockArt()
{
    return m_mgr.GetArtProvider();
}

void MainFrame::DoUpdate()
{
    m_mgr.Update();
}

void MainFrame::OnEraseBackground(wxEraseEvent& event)
{
    event.Skip();
}

void MainFrame::OnSize(wxSizeEvent& event)
{
    event.Skip();
}

void MainFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
    // show the settings pane, and float it
    wxAuiPaneInfo& floating_pane = m_mgr.GetPane("settings").Float().Show();

    if (floating_pane.floating_pos == wxDefaultPosition)
        floating_pane.FloatingPosition(GetStartPosition());

    m_mgr.Update();
}

void MainFrame::OnCustomizeToolbar(wxCommandEvent& WXUNUSED(evt))
{
    wxMessageBox(_("Customize Toolbar clicked"));
}

void MainFrame::OnGradient(wxCommandEvent& event)
{
    int gradient = 0;

    switch (event.GetId())
    {
    case ID_NoGradient:         gradient = wxAUI_GRADIENT_NONE; break;
    case ID_VerticalGradient:   gradient = wxAUI_GRADIENT_VERTICAL; break;
    case ID_HorizontalGradient: gradient = wxAUI_GRADIENT_HORIZONTAL; break;
    }

    m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, gradient);
    m_mgr.Update();
}

void MainFrame::OnToolbarResizing(wxCommandEvent& WXUNUSED(evt))
{
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    const size_t count = all_panes.GetCount();
    for (size_t i = 0; i < count; ++i)
    {
        wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
        if (toolbar)
        {
            all_panes[i].Resizable(!all_panes[i].IsResizable());
        }
    }

    m_mgr.Update();
}

void MainFrame::OnManagerFlag(wxCommandEvent& event)
{
    unsigned int flag = 0;

#if !defined(__WXMSW__) && !defined(__WXMAC__) && !defined(__WXGTK__)
    if (event.GetId() == ID_TransparentDrag ||
        event.GetId() == ID_TransparentHint ||
        event.GetId() == ID_HintFade)
    {
        wxMessageBox("This option is presently only available on wxGTK, wxMSW and wxMac");
        return;
    }
#endif

    int id = event.GetId();

    if (id == ID_TransparentHint ||
        id == ID_VenetianBlindsHint ||
        id == ID_RectangleHint ||
        id == ID_NoHint)
    {
        unsigned int flags = m_mgr.GetFlags();
        flags &= ~wxAUI_MGR_TRANSPARENT_HINT;
        flags &= ~wxAUI_MGR_VENETIAN_BLINDS_HINT;
        flags &= ~wxAUI_MGR_RECTANGLE_HINT;
        m_mgr.SetFlags(flags);
    }

    switch (id)
    {
    case ID_AllowFloating: flag = wxAUI_MGR_ALLOW_FLOATING; break;
    case ID_TransparentDrag: flag = wxAUI_MGR_TRANSPARENT_DRAG; break;
    case ID_HintFade: flag = wxAUI_MGR_HINT_FADE; break;
    case ID_NoVenetianFade: flag = wxAUI_MGR_NO_VENETIAN_BLINDS_FADE; break;
    case ID_AllowActivePane: flag = wxAUI_MGR_ALLOW_ACTIVE_PANE; break;
    case ID_TransparentHint: flag = wxAUI_MGR_TRANSPARENT_HINT; break;
    case ID_VenetianBlindsHint: flag = wxAUI_MGR_VENETIAN_BLINDS_HINT; break;
    case ID_RectangleHint: flag = wxAUI_MGR_RECTANGLE_HINT; break;
    case ID_LiveUpdate: flag = wxAUI_MGR_LIVE_RESIZE; break;
    }

    if (flag)
    {
        m_mgr.SetFlags(m_mgr.GetFlags() ^ flag);
    }

    m_mgr.Update();
}

void MainFrame::OnNotebookFlag(wxCommandEvent& event)
{
    int id = event.GetId();

    if (id == ID_NotebookNoCloseButton ||
        id == ID_NotebookCloseButton ||
        id == ID_NotebookCloseButtonAll ||
        id == ID_NotebookCloseButtonActive)
    {
        m_notebook_style &= ~(wxAUI_NB_CLOSE_BUTTON |
            wxAUI_NB_CLOSE_ON_ACTIVE_TAB |
            wxAUI_NB_CLOSE_ON_ALL_TABS);

        switch (id)
        {
        case ID_NotebookNoCloseButton: break;
        case ID_NotebookCloseButton: m_notebook_style |= wxAUI_NB_CLOSE_BUTTON; break;
        case ID_NotebookCloseButtonAll: m_notebook_style |= wxAUI_NB_CLOSE_ON_ALL_TABS; break;
        case ID_NotebookCloseButtonActive: m_notebook_style |= wxAUI_NB_CLOSE_ON_ACTIVE_TAB; break;
        }
    }

    if (id == ID_NotebookAllowTabMove)
    {
        m_notebook_style ^= wxAUI_NB_TAB_MOVE;
    }
    if (id == ID_NotebookAllowTabExternalMove)
    {
        m_notebook_style ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
    }
    else if (id == ID_NotebookAllowTabSplit)
    {
        m_notebook_style ^= wxAUI_NB_TAB_SPLIT;
    }
    else if (id == ID_NotebookWindowList)
    {
        m_notebook_style ^= wxAUI_NB_WINDOWLIST_BUTTON;
    }
    else if (id == ID_NotebookScrollButtons)
    {
        m_notebook_style ^= wxAUI_NB_SCROLL_BUTTONS;
    }
    else if (id == ID_NotebookTabFixedWidth)
    {
        m_notebook_style ^= wxAUI_NB_TAB_FIXED_WIDTH;
    }


    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
    {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
        {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            if (id == ID_NotebookArtGloss)
            {
                nb->SetArtProvider(new wxAuiDefaultTabArt);
                m_notebook_theme = 0;
            }
            else if (id == ID_NotebookArtSimple)
            {
                nb->SetArtProvider(new wxAuiSimpleTabArt);
                m_notebook_theme = 1;
            }


            nb->SetWindowStyleFlag(m_notebook_style);
            nb->Refresh();
        }
    }


}

void MainFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
    unsigned int flags = m_mgr.GetFlags();

    switch (event.GetId())
    {
    case ID_NoGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_NONE);
        break;
    case ID_VerticalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_VERTICAL);
        break;
    case ID_HorizontalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_HORIZONTAL);
        break;
    case ID_AllowToolbarResizing:
    {
        wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
        const size_t count = all_panes.GetCount();
        for (size_t i = 0; i < count; ++i)
        {
            wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
            if (toolbar)
            {
                event.Check(all_panes[i].IsResizable());
                break;
            }
        }
        break;
    }
    case ID_AllowFloating:
        event.Check((flags & wxAUI_MGR_ALLOW_FLOATING) != 0);
        break;
    case ID_TransparentDrag:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_DRAG) != 0);
        break;
    case ID_TransparentHint:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_HINT) != 0);
        break;
    case ID_LiveUpdate:
        event.Check((flags & wxAUI_MGR_LIVE_RESIZE) != 0);
        break;
    case ID_VenetianBlindsHint:
        event.Check((flags & wxAUI_MGR_VENETIAN_BLINDS_HINT) != 0);
        break;
    case ID_RectangleHint:
        event.Check((flags & wxAUI_MGR_RECTANGLE_HINT) != 0);
        break;
    case ID_NoHint:
        event.Check(((wxAUI_MGR_TRANSPARENT_HINT |
            wxAUI_MGR_VENETIAN_BLINDS_HINT |
            wxAUI_MGR_RECTANGLE_HINT) & flags) == 0);
        break;
    case ID_HintFade:
        event.Check((flags & wxAUI_MGR_HINT_FADE) != 0);
        break;
    case ID_NoVenetianFade:
        event.Check((flags & wxAUI_MGR_NO_VENETIAN_BLINDS_FADE) != 0);
        break;

    case ID_NotebookNoCloseButton:
        event.Check((m_notebook_style & (wxAUI_NB_CLOSE_BUTTON | wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_CLOSE_ON_ACTIVE_TAB)) != 0);
        break;
    case ID_NotebookCloseButton:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_BUTTON) != 0);
        break;
    case ID_NotebookCloseButtonAll:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ALL_TABS) != 0);
        break;
    case ID_NotebookCloseButtonActive:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ACTIVE_TAB) != 0);
        break;
    case ID_NotebookAllowTabSplit:
        event.Check((m_notebook_style & wxAUI_NB_TAB_SPLIT) != 0);
        break;
    case ID_NotebookAllowTabMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_MOVE) != 0);
        break;
    case ID_NotebookAllowTabExternalMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_EXTERNAL_MOVE) != 0);
        break;
    case ID_NotebookScrollButtons:
        event.Check((m_notebook_style & wxAUI_NB_SCROLL_BUTTONS) != 0);
        break;
    case ID_NotebookWindowList:
        event.Check((m_notebook_style & wxAUI_NB_WINDOWLIST_BUTTON) != 0);
        break;
    case ID_NotebookTabFixedWidth:
        event.Check((m_notebook_style & wxAUI_NB_TAB_FIXED_WIDTH) != 0);
        break;
    case ID_NotebookArtGloss:
        event.Check(m_notebook_style == 0);
        break;
    case ID_NotebookArtSimple:
        event.Check(m_notebook_style == 1);
        break;

    }
}

void MainFrame::OnPaneClose(wxAuiManagerEvent& evt)
{
    if (evt.pane->name == "test10")
    {
        int res = wxMessageBox("Are you sure you want to close/hide this pane?",
            "wxAUI",
            wxYES_NO,
            this);
        if (res != wxYES)
            evt.Veto();
    }
}

void MainFrame::OnCreateCube(wxCommandEvent& WXUNUSED(event))
{
    sceneDisplay->CreateCube();
    UpdateHeirarchy(heirarchyWindow);
}

void MainFrame::OnCreateSphere(wxCommandEvent& WXUNUSED(event))
{
    sceneDisplay->CreateSphere();
    UpdateHeirarchy(heirarchyWindow);
}

void MainFrame::OnCreateCylinder(wxCommandEvent& WXUNUSED(event))
{
    sceneDisplay->CreateCylinder();
    UpdateHeirarchy(heirarchyWindow);
}

void MainFrame::OnCreatePlane(wxCommandEvent& WXUNUSED(event))
{
    sceneDisplay->CreatePlane();
    UpdateHeirarchy(heirarchyWindow);
}

void MainFrame::OnCreatePerspective(wxCommandEvent& WXUNUSED(event))
{
    wxTextEntryDialog dlg(this, "Enter a name for the new perspective:",
        "wxAUI Test");

    dlg.SetValue(wxString::Format("Perspective %u", unsigned(m_perspectives.GetCount() + 1)));
    if (dlg.ShowModal() != wxID_OK)
        return;

    if (m_perspectives.GetCount() == 0)
    {
        m_perspectives_menu->AppendSeparator();
    }

    m_perspectives_menu->Append(ID_FirstPerspective + m_perspectives.GetCount(), dlg.GetValue());
    m_perspectives.Add(m_mgr.SavePerspective());
}

void MainFrame::OnCopyPerspectiveCode(wxCommandEvent& WXUNUSED(evt))
{
    wxString s = m_mgr.SavePerspective();

#if wxUSE_CLIPBOARD
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(s));
        wxTheClipboard->Close();
    }
#endif
}

void MainFrame::OnRestorePerspective(wxCommandEvent& evt)
{
    m_mgr.LoadPerspective(m_perspectives.Item(evt.GetId() - ID_FirstPerspective));
}

void MainFrame::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();
    if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow)))
    {
        int res = wxMessageBox("Are you sure you want to close/hide this notebook page?",
            "wxAUI",
            wxYES_NO,
            this);
        if (res != wxYES)
            evt.Veto();
    }
}

void MainFrame::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();
    wxUnusedVar(ctrl);

    // selection should always be a valid index
    wxASSERT_MSG(ctrl->GetSelection() < (int)ctrl->GetPageCount(),
        wxString::Format("Invalid selection %d, only %d pages left",
            ctrl->GetSelection(),
            (int)ctrl->GetPageCount()));

    evt.Skip();
}

void MainFrame::OnNotebookPageChanging(wxAuiNotebookEvent& evt)
{
    if (evt.GetOldSelection() == 3)
    {
        if (wxMessageBox("Are you sure you want to leave this page?\n"
            "(This demonstrates veto-ing)",
            "wxAUI",
            wxICON_QUESTION | wxYES_NO,
            this) != wxYES)
        {
            evt.Veto();
        }
    }
}

void MainFrame::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
    // for the purpose of this test application, explicitly
    // allow all notebook drag and drop events
    evt.Allow();
}

wxPoint MainFrame::GetStartPosition()
{
    static int x = 0;
    x += FromDIP(20);
    wxPoint pt = ClientToScreen(wxPoint(0, 0));
    return wxPoint(pt.x + x, pt.y + x);
}

void MainFrame::OnCreateTree(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().
        Caption("Heirarchy").
        Float().FloatingPosition(GetStartPosition()).
        FloatingSize(FromDIP(wxSize(150, 300))));
    m_mgr.Update();
}

void MainFrame::OnCreateHTML(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().
        Caption("HTML Control").
        Float().FloatingPosition(GetStartPosition()).
        FloatingSize(FromDIP(wxSize(300, 200))));
    m_mgr.Update();
}

void MainFrame::OnCreateNotebook(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().
        Caption("Notebook").
        Float().FloatingPosition(GetStartPosition()).
        //FloatingSize(FromDIP(wxSize(300,200))).
        CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void MainFrame::OnCreateText(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateTextCtrl(), wxAuiPaneInfo().
        Caption("Text Control").
        Float().FloatingPosition(GetStartPosition()));
    m_mgr.Update();
}

void MainFrame::OnCreateSizeReport(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
        Caption("Client Size Reporter").
        Float().FloatingPosition(GetStartPosition()).
        CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void MainFrame::OnCreateIrrlicht(wxCommandEvent& evt)
{
    m_mgr.AddPane(CreateIrrlicht(), wxAuiPaneInfo().
        Caption("Client Size Reporter").
        Float().FloatingPosition(GetStartPosition()).
        CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void MainFrame::OnChangeContentPane(wxCommandEvent& evt)
{
    m_mgr.GetPane("grid_content").Show(evt.GetId() == ID_GridContent);
    m_mgr.GetPane("text_content").Show(evt.GetId() == ID_TextContent);
    m_mgr.GetPane("tree_content").Show(evt.GetId() == ID_TreeContent);
    m_mgr.GetPane("sizereport_content").Show(evt.GetId() == ID_SizeReportContent);
    m_mgr.GetPane("Irrlicht_content").Show(evt.GetId() == ID_IrrlichtContent);
    m_mgr.GetPane("html_content").Show(evt.GetId() == ID_HTMLContent);
    m_mgr.GetPane("notebook_content").Show(evt.GetId() == ID_NotebookContent);
    m_mgr.Update();
}

void MainFrame::OnDropDownToolbarItem(wxAuiToolBarEvent& evt)
{
    if (evt.IsDropDownClicked())
    {
        wxAuiToolBar* tb = static_cast<wxAuiToolBar*>(evt.GetEventObject());

        tb->SetToolSticky(evt.GetId(), true);

        // create the popup menu
        wxMenu menuPopup;

        // TODO: Use GetBitmapBundle() when wxMenuItem is updated to use it too.
        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, FromDIP(wxSize(16, 16)));

        wxMenuItem* m1 = new wxMenuItem(&menuPopup, 10001, _("Drop Down Item 1"));
        m1->SetBitmap(bmp);
        menuPopup.Append(m1);

        wxMenuItem* m2 = new wxMenuItem(&menuPopup, 10002, _("Drop Down Item 2"));
        m2->SetBitmap(bmp);
        menuPopup.Append(m2);

        wxMenuItem* m3 = new wxMenuItem(&menuPopup, 10003, _("Drop Down Item 3"));
        m3->SetBitmap(bmp);
        menuPopup.Append(m3);

        wxMenuItem* m4 = new wxMenuItem(&menuPopup, 10004, _("Drop Down Item 4"));
        m4->SetBitmap(bmp);
        menuPopup.Append(m4);

        // line up our menu with the button
        wxRect rect = tb->GetToolRect(evt.GetId());
        wxPoint pt = tb->ClientToScreen(rect.GetBottomLeft());
        pt = ScreenToClient(pt);


        PopupMenu(&menuPopup, pt);


        // make sure the button is "un-stuck"
        tb->SetToolSticky(evt.GetId(), false);
    }
}

void MainFrame::OnTabAlignment(wxCommandEvent& evt)
{
    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
    {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
        {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            long style = nb->GetWindowStyleFlag();
            style &= ~(wxAUI_NB_TOP | wxAUI_NB_BOTTOM);
            if (evt.GetId() == ID_NotebookAlignTop)
                style |= wxAUI_NB_TOP;
            else if (evt.GetId() == ID_NotebookAlignBottom)
                style |= wxAUI_NB_BOTTOM;
            nb->SetWindowStyleFlag(style);

            nb->Refresh();
        }
    }
}

void MainFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(_("wxAUI Demo\nAn advanced window management library for wxWidgets\n(c) Copyright 2005-2006, Kirix Corporation"), _("About wxAUI Demo"), wxOK, this);
}

wxTextCtrl* MainFrame::CreateTextCtrl(const wxString& ctrl_text)
{
    static int n = 0;

    wxString text;
    if (!ctrl_text.empty())
        text = ctrl_text;
    else
        text.Printf("This is text box %d", ++n);

    return new wxTextCtrl(this, wxID_ANY, text,
        wxPoint(0, 0), FromDIP(wxSize(150, 90)),
        wxNO_BORDER | wxTE_MULTILINE);
}


wxTreeCtrl* MainFrame::CreateTreeCtrl()
{
    wxTreeCtrl* tree = new wxTreeCtrl(this, wxID_ANY,
        wxPoint(0, 0),
        FromDIP(wxSize(160, 250)),
        wxTR_DEFAULT_STYLE | wxNO_BORDER);
    tree->SetName("Heirarchy");

    wxSize size(16, 16);
    wxVector<wxBitmapBundle> images;
    images.push_back(wxArtProvider::GetBitmapBundle(wxART_FOLDER, wxART_OTHER, size));
    images.push_back(wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, size));
    tree->SetImages(images);

    wxTreeItemId root = tree->AddRoot("Scene", 0);
    wxArrayTreeItemIds items;
     
    irr::scene::ISceneNode* parentNode = sceneDisplay->smgr->getRootSceneNode();
    irr::core::list<irr::scene::ISceneNode*> children = parentNode->getChildren();
    irr::core::list<irr::scene::ISceneNode*>::ConstIterator start = children.begin();
    const irr::core::list<irr::scene::ISceneNode*>::ConstIterator& end = children.end();

    for (; start != end; ++start)
    {
        irr::scene::ISceneNode* const node = (*start);

        const irr::scene::ESCENE_NODE_TYPE& type = node->getType();
        const irr::s32 id = node->getID();
        const irr::c8* name = node->getName();

        if (type != ESNT_CAMERA && node->isDebugObject() == false)
            items.Add(tree->AppendItem(root, name, 0));

    }

    tree->Expand(root);
    heirarchyWindow = tree;
    return heirarchyWindow;
}

void MainFrame::UpdateHeirarchy(wxTreeCtrl* tree)
{
    tree->DeleteAllItems();

    wxTreeItemId root = tree->AddRoot("Scene", 0);
    wxArrayTreeItemIds items;

    irr::scene::ISceneNode* parentNode = sceneDisplay->smgr->getRootSceneNode();
    irr::core::list<irr::scene::ISceneNode*> children = parentNode->getChildren();
    irr::core::list<irr::scene::ISceneNode*>::ConstIterator start = children.begin();
    const irr::core::list<irr::scene::ISceneNode*>::ConstIterator& end = children.end();

    for (; start != end; ++start)
    {
        irr::scene::ISceneNode* const node = (*start);

        const irr::scene::ESCENE_NODE_TYPE& type = node->getType();
        const irr::s32 id = node->getID();
        const irr::c8* name = node->getName();

        if (type != ESNT_CAMERA && node->isDebugObject() == false)
            items.Add(tree->AppendItem(root, name, 0));

    }
    tree->Expand(root);
}

void MainFrame::ToggleGrid(wxCommandEvent& event)
{
    sceneDisplay->grid->setVisible(!sceneDisplay->grid->isVisible());
}

wxSizeReportCtrl* MainFrame::CreateSizeReportCtrl(const wxSize& size)
{
    wxSizeReportCtrl* ctrl = new wxSizeReportCtrl(this, wxID_ANY,
        wxDefaultPosition,
        size, &m_mgr);
    return ctrl;
}

wxIrrlicht* MainFrame::CreateIrrlicht(const wxSize& size)
{
    irrlichtWindow = new wxIrrlicht(this, wxID_ANY,
        true, wxPoint((int)(GetClientSize().x * 2 / 100), (int)(GetClientSize().y * 2 / 100)),
        wxSize((int)(GetClientSize().x * 64 / 100), ((int)GetClientSize().y * 36 / 100)));
    irrlichtWindow->SetBackgroundColour(wxColour("red"));
    irrlichtWindow->InitIrr();
    irrlichtWindow->StartRendering();
    return irrlichtWindow;
}

wxHtmlWindow* MainFrame::CreateHTMLCtrl(wxWindow* parent)
{
    if (!parent)
        parent = this;

    wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY,
        wxDefaultPosition,
        FromDIP(wxSize(400, 300)));
    ctrl->SetPage(GetIntroText());
    return ctrl;
}

wxAuiNotebook* MainFrame::CreateNotebook()
{
    // create the notebook off-window to avoid flicker
    wxSize client_size = GetClientSize();

    wxAuiNotebook* ctrl = new wxAuiNotebook(this, wxID_ANY,
        wxPoint(client_size.x, client_size.y),
        FromDIP(wxSize(430, 200)),
        m_notebook_style);
    ctrl->Freeze();

    wxBitmapBundle page_bmp = wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

    ctrl->AddPage(CreateHTMLCtrl(ctrl), "Welcome to wxAUI", false, page_bmp);
    ctrl->SetPageToolTip(0, "Welcome to wxAUI (this is a page tooltip)");

    wxPanel* panel = new wxPanel(ctrl, wxID_ANY);
    wxFlexGridSizer* flex = new wxFlexGridSizer(4, 2, 0, 0);
    flex->AddGrowableRow(0);
    flex->AddGrowableRow(3);
    flex->AddGrowableCol(1);
    flex->Add(FromDIP(5), FromDIP(5));   flex->Add(FromDIP(5), FromDIP(5));
    flex->Add(new wxStaticText(panel, -1, "wxTextCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxTextCtrl(panel, -1, "", wxDefaultPosition, FromDIP(wxSize(100, -1))),
        1, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxStaticText(panel, -1, "wxSpinCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxSpinCtrl(panel, -1, "5", wxDefaultPosition, wxDefaultSize,
        wxSP_ARROW_KEYS, 5, 50, 5), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(FromDIP(5), FromDIP(5));   flex->Add(FromDIP(5), FromDIP(5));
    panel->SetSizer(flex);
    ctrl->AddPage(panel, "wxPanel", false, page_bmp);


    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 1", false, page_bmp);

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 2");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 3");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 4");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 5");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 6");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 7 (longer title)");
    ctrl->SetPageToolTip(ctrl->GetPageCount() - 1,
        "wxTextCtrl 7: and the tooltip message can be even longer!");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 8");

    ctrl->Thaw();
    return ctrl;
}

wxString MainFrame::GetIntroText()
{
    const char* text =
        "<html><body>"
        "<h3>Welcome to wxAUI</h3>"
        "<br/><b>Overview</b><br/>"
        "<p>wxAUI is an Advanced User Interface library for the wxWidgets toolkit "
        "that allows developers to create high-quality, cross-platform user "
        "interfaces quickly and easily.</p>"
        "<p><b>Features</b></p>"
        "<p>With wxAUI, developers can create application frameworks with:</p>"
        "<ul>"
        "<li>Native, dockable floating frames</li>"
        "<li>Perspective saving and loading</li>"
        "<li>Native toolbars incorporating real-time, &quot;spring-loaded&quot; dragging</li>"
        "<li>Customizable floating/docking behaviour</li>"
        "<li>Completely customizable look-and-feel</li>"
        "<li>Optional transparent window effects (while dragging or docking)</li>"
        "<li>Splittable notebook control</li>"
        "</ul>"
        "<p><b>What's new in 0.9.4?</b></p>"
        "<p>wxAUI 0.9.4, which is bundled with wxWidgets, adds the following features:"
        "<ul>"
        "<li>New wxAuiToolBar class, a toolbar control which integrates more "
        "cleanly with wxAuiFrameManager.</li>"
        "<li>Lots of bug fixes</li>"
        "</ul>"
        "<p><b>What's new in 0.9.3?</b></p>"
        "<p>wxAUI 0.9.3, which is now bundled with wxWidgets, adds the following features:"
        "<ul>"
        "<li>New wxAuiNotebook class, a dynamic splittable notebook control</li>"
        "<li>New wxAuiMDI* classes, a tab-based MDI and drop-in replacement for classic MDI</li>"
        "<li>Maximize/Restore buttons implemented</li>"
        "<li>Better hinting with wxGTK</li>"
        "<li>Class rename.  'wxAui' is now the standard class prefix for all wxAUI classes</li>"
        "<li>Lots of bug fixes</li>"
        "</ul>"
        "<p><b>What's new in 0.9.2?</b></p>"
        "<p>The following features/fixes have been added since the last version of wxAUI:</p>"
        "<ul>"
        "<li>Support for wxMac</li>"
        "<li>Updates for wxWidgets 2.6.3</li>"
        "<li>Fix to pass more unused events through</li>"
        "<li>Fix to allow floating windows to receive idle events</li>"
        "<li>Fix for minimizing/maximizing problem with transparent hint pane</li>"
        "<li>Fix to not paint empty hint rectangles</li>"
        "<li>Fix for 64-bit compilation</li>"
        "</ul>"
        "<p><b>What changed in 0.9.1?</b></p>"
        "<p>The following features/fixes were added in wxAUI 0.9.1:</p>"
        "<ul>"
        "<li>Support for MDI frames</li>"
        "<li>Gradient captions option</li>"
        "<li>Active/Inactive panes option</li>"
        "<li>Fix for screen artifacts/paint problems</li>"
        "<li>Fix for hiding/showing floated window problem</li>"
        "<li>Fix for floating pane sizing problem</li>"
        "<li>Fix for drop position problem when dragging around center pane margins</li>"
        "<li>LF-only text file formatting for source code</li>"
        "</ul>"
        "<p>See README.txt for more information.</p>"
        "</body></html>";

    return wxString::FromAscii(text);
}
