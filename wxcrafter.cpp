//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;


MainFrameBaseClass::MainFrameBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_menuFile = new wxMenu();
    m_menuBar->Append(m_menuFile, _("File"));
    
    m_menuItemOpen = new wxMenuItem(m_menuFile, wxID_OPEN, _("Open"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemOpen);
    
    m_menuItem7 = new wxMenuItem(m_menuFile, wxID_EXIT, _("Exit\tAlt-X"), _("Quit"), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItem7);
    
    m_menuEdit = new wxMenu();
    m_menuBar->Append(m_menuEdit, _("Edit"));
    
    m_menuEditClearMarks = new wxMenuItem(m_menuEdit, wxID_EDIT_CLEAR_MARKS, _("Clear Marks"), wxT(""), wxITEM_NORMAL);
    m_menuEdit->Append(m_menuEditClearMarks);
    
    m_menuView = new wxMenu();
    m_menuBar->Append(m_menuView, _("View"));
    
    m_menuItemViewMsgPane = new wxMenuItem(m_menuView, wxID_ANY, _("Show Message Pane"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemViewMsgPane);
    m_menuItemViewMsgPane->Check();
    
    m_menuItemViewSeries = new wxMenuItem(m_menuView, wxID_VIEW_SERIES, _("Original Series"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemViewSeries);
    
    m_menuItemViewResultSeries = new wxMenuItem(m_menuView, wxID_VIEW_RESULT_SERIES, _("Result Series"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemViewResultSeries);
    
    m_menuItemViewFolderImage = new wxMenuItem(m_menuView, wxID_ANY, _("Folder Image"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemViewFolderImage);
    
    m_menuItemView2D = new wxMenuItem(m_menuView, wxID_ANY, _("Show 2D data"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemView2D);
    
    m_menuItemView3D = new wxMenuItem(m_menuView, wxID_ANY, _("Show 3D data"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemView3D);
    
    m_menuItemViewMarks = new wxMenuItem(m_menuView, wxID_VIEW_MARK, _("View Marks"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemViewMarks);
    m_menuItemViewMarks->Check();
    
    m_menuItemViewBellyROI = new wxMenuItem(m_menuView, wxID_ANY, _("View Belly ROI"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemViewBellyROI);
    
    m_menuRat = new wxMenu();
    m_menuBar->Append(m_menuRat, _("Rat"));
    
    m_menuItemProcess = new wxMenuItem(m_menuRat, wxID_RAT_PROCESS, _("Process"), wxT(""), wxITEM_NORMAL);
    m_menuRat->Append(m_menuItemProcess);
    
    m_menuItemRatGenRefFrame = new wxMenuItem(m_menuRat, wxID_ANY, _("Gen. Ref. Frame Signal"), wxT(""), wxITEM_NORMAL);
    m_menuRat->Append(m_menuItemRatGenRefFrame);
    
    m_menuItemBatch = new wxMenuItem(m_menuRat, wxID_ANY, _("Batch Process"), wxT(""), wxITEM_NORMAL);
    m_menuRat->Append(m_menuItemBatch);
    
    m_menuRat->AppendSeparator();
    
    m_menuItemCheckAPB = new wxMenuItem(m_menuRat, wxID_RAT_CHECK_APB, _("Check APB"), wxT(""), wxITEM_NORMAL);
    m_menuRat->Append(m_menuItemCheckAPB);
    
    m_menuTools = new wxMenu();
    m_menuBar->Append(m_menuTools, _("Tools"));
    
    m_menuItemCleanOutput = new wxMenuItem(m_menuTools, wxID_ANY, _("Clean output folders"), wxT(""), wxITEM_NORMAL);
    m_menuTools->Append(m_menuItemCleanOutput);
    
    m_nameHelp = new wxMenu();
    m_menuBar->Append(m_nameHelp, _("Help"));
    
    m_menuItem9 = new wxMenuItem(m_nameHelp, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_nameHelp->Append(m_menuItem9);
    
    m_auimgr11 = new wxAuiManager;
    m_auimgr11->SetManagedWindow( this );
    m_auimgr11->SetFlags( wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_TRANSPARENT_HINT|wxAUI_MGR_TRANSPARENT_DRAG|wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_ALLOW_FLOATING);
    m_auimgr11->GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, wxAUI_GRADIENT_NONE);
    
    m_scrollWin = new ScrolledImageComponent(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxVSCROLL);
    m_scrollWin->SetScrollRate(5, 5);
    
    m_auimgr11->AddPane(m_scrollWin, wxAuiPaneInfo().Direction(wxAUI_DOCK_CENTER).Layer(0).Row(0).Position(0).BestSize(100,100).MinSize(100,100).MaxSize(100,100).CaptionVisible(false).MaximizeButton(false).CloseButton(false).MinimizeButton(false).PinButton(false));
    
    m_panel15 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    m_auimgr11->AddPane(m_panel15, wxAuiPaneInfo().Name(wxT("MsgPane")).Caption(_("Message Pane")).Direction(wxAUI_DOCK_BOTTOM).Layer(0).Row(0).Position(0).BestSize(100,150).MinSize(100,100).MaxSize(100,100).CaptionVisible(true).MaximizeButton(false).CloseButton(true).MinimizeButton(false).PinButton(false));
    
    wxBoxSizer* boxSizer25 = new wxBoxSizer(wxVERTICAL);
    m_panel15->SetSizer(boxSizer25);
    
    m_richTextMsg = new wxRichTextCtrl(m_panel15, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_MULTILINE|wxTE_PROCESS_TAB|wxTE_PROCESS_ENTER|wxWANTS_CHARS);
    
    boxSizer25->Add(m_richTextMsg, 1, wxALL|wxEXPAND, 0);
    
    m_auibar31 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar31->SetToolBitmapSize(wxSize(32,32));
    
    m_auimgr11->AddPane(m_auibar31, wxAuiPaneInfo().Direction(wxAUI_DOCK_TOP).Layer(0).Row(0).Position(0).BestSize(42,42).MinSize(42,42).CaptionVisible(false).MaximizeButton(false).CloseButton(false).MinimizeButton(false).PinButton(false).ToolbarPane());
    m_auimgr11->Update();
    
    m_auibar31->AddTool(wxID_OPEN, _("Open"), wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, wxDefaultSize), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_auibar31->AddTool(wxID_VIEW_RESULT_SERIES, _("View Series"), wxXmlResource::Get()->LoadBitmap(wxT("Projector")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_auibar31->AddSeparator();
    
    m_auibar31->AddTool(wxID_EDIT_CLEAR_MARKS, _("Clear Marks"), wxXmlResource::Get()->LoadBitmap(wxT("ERASE01")), wxNullBitmap, wxITEM_NORMAL, _("Clear Marks"), wxT(""), NULL);
    
    m_bmpToggleBtnViewMark = new wxBitmapToggleButton(m_auibar31, wxID_VIEW_MARK, wxXmlResource::Get()->LoadBitmap(wxT("mark")), wxDefaultPosition, wxSize(40,-1), 0);
    m_bmpToggleBtnViewMark->SetToolTip(_("View Marks"));
    m_bmpToggleBtnViewMark->SetValue(true);
    m_auibar31->AddControl(m_bmpToggleBtnViewMark);
    
    m_auibar31->AddSeparator();
    
    m_bmpToggleBtnMarkCageLine = new wxBitmapToggleButton(m_auibar31, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("cage")), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    m_bmpToggleBtnMarkCageLine->SetToolTip(_("Mark cage line"));
    m_bmpToggleBtnMarkCageLine->SetValue(false);
    m_auibar31->AddControl(m_bmpToggleBtnMarkCageLine);
    
    m_bmpToggleBtnMarkEyes = new wxBitmapToggleButton(m_auibar31, wxID_RAT_MARK_EYE, wxXmlResource::Get()->LoadBitmap(wxT("mark_eye")), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    m_bmpToggleBtnMarkEyes->SetToolTip(_("Mark eyes"));
    m_bmpToggleBtnMarkEyes->SetValue(false);
    m_auibar31->AddControl(m_bmpToggleBtnMarkEyes);
    
    m_bmpToggleBtnMarkEars = new wxBitmapToggleButton(m_auibar31, wxID_RAT_MARK_EAR, wxXmlResource::Get()->LoadBitmap(wxT("mark_ear")), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    m_bmpToggleBtnMarkEars->SetToolTip(_("Mark Ears"));
    m_bmpToggleBtnMarkEars->SetValue(false);
    m_auibar31->AddControl(m_bmpToggleBtnMarkEars);
    
    m_bmpToggleBtnMarkBelly = new wxBitmapToggleButton(m_auibar31, wxID_RAT_MARK_BELLY, wxXmlResource::Get()->LoadBitmap(wxT("mark_APB")), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    m_bmpToggleBtnMarkBelly->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    m_bmpToggleBtnMarkBelly->SetToolTip(_("Mark Belly"));
    m_bmpToggleBtnMarkBelly->SetValue(false);
    m_auibar31->AddControl(m_bmpToggleBtnMarkBelly);
    
    m_auibar31->AddSeparator();
    
    m_auibar31->AddTool(wxID_RAT_PROCESS, _("Process"), wxXmlResource::Get()->LoadBitmap(wxT("Mouse")), wxNullBitmap, wxITEM_NORMAL, _("Process"), wxT(""), NULL);
    
    m_auibar31->AddTool(wxID_RAT_CHECK_APB, _("Check APB"), wxXmlResource::Get()->LoadBitmap(wxT("result")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    m_auibar31->Realize();
    
    m_statusBar = new wxStatusBar(this, wxID_ANY, wxSTB_DEFAULT_STYLE);
    m_statusBar->SetFieldsCount(1);
    this->SetStatusBar(m_statusBar);
    
    SetName(wxT("MainFrameBaseClass"));
    SetSize(550,500);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(m_menuItemOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnFileOpen), NULL, this);
    this->Connect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Connect(m_menuEditClearMarks->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnEditClearMarks), NULL, this);
    this->Connect(m_menuItemViewMsgPane->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewMsgPane), NULL, this);
    this->Connect(m_menuItemViewMsgPane->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMsgPane), NULL, this);
    this->Connect(m_menuItemViewSeries->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewSeries), NULL, this);
    this->Connect(m_menuItemViewSeries->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewSeries), NULL, this);
    this->Connect(m_menuItemViewResultSeries->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewResultSeries), NULL, this);
    this->Connect(m_menuItemViewResultSeries->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewSeries), NULL, this);
    this->Connect(m_menuItemViewFolderImage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewFolderImage), NULL, this);
    this->Connect(m_menuItemView2D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnView2DData), NULL, this);
    this->Connect(m_menuItemView3D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnView3DData), NULL, this);
    this->Connect(m_menuItemViewMarks->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewMarks), NULL, this);
    this->Connect(m_menuItemViewMarks->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMarks), NULL, this);
    this->Connect(m_menuItemViewBellyROI->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewBellyROI), NULL, this);
    this->Connect(m_menuItemViewBellyROI->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewBellyROI), NULL, this);
    this->Connect(m_menuItemProcess->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatProcess), NULL, this);
    this->Connect(m_menuItemRatGenRefFrame->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatGenRefFrame), NULL, this);
    this->Connect(m_menuItemBatch->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnBatchProcess), NULL, this);
    this->Connect(m_menuItemCheckAPB->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatCheckAPB), NULL, this);
    this->Connect(m_menuItemCleanOutput->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnToolsCleanOutput), NULL, this);
    this->Connect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    m_scrollWin->Connect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotion), NULL, this);
    m_scrollWin->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MainFrameBaseClass::OnMouseLButtonDown), NULL, this);
    m_scrollWin->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MainFrameBaseClass::OnMouseRButtonDown), NULL, this);
    this->Connect(wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnFileOpen), NULL, this);
    m_bmpToggleBtnViewMark->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnViewMarks), NULL, this);
    m_bmpToggleBtnViewMark->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMarks), NULL, this);
    m_bmpToggleBtnMarkCageLine->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkCageline), NULL, this);
    m_bmpToggleBtnMarkEyes->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkEyes), NULL, this);
    m_bmpToggleBtnMarkEars->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkEars), NULL, this);
    m_bmpToggleBtnMarkBelly->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkBelly), NULL, this);
    
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    this->Disconnect(m_menuItemOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnFileOpen), NULL, this);
    this->Disconnect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuEditClearMarks->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnEditClearMarks), NULL, this);
    this->Disconnect(m_menuItemViewMsgPane->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewMsgPane), NULL, this);
    this->Disconnect(m_menuItemViewMsgPane->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMsgPane), NULL, this);
    this->Disconnect(m_menuItemViewSeries->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewSeries), NULL, this);
    this->Disconnect(m_menuItemViewSeries->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewSeries), NULL, this);
    this->Disconnect(m_menuItemViewResultSeries->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewResultSeries), NULL, this);
    this->Disconnect(m_menuItemViewResultSeries->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewSeries), NULL, this);
    this->Disconnect(m_menuItemViewFolderImage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewFolderImage), NULL, this);
    this->Disconnect(m_menuItemView2D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnView2DData), NULL, this);
    this->Disconnect(m_menuItemView3D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnView3DData), NULL, this);
    this->Disconnect(m_menuItemViewMarks->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewMarks), NULL, this);
    this->Disconnect(m_menuItemViewMarks->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMarks), NULL, this);
    this->Disconnect(m_menuItemViewBellyROI->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewBellyROI), NULL, this);
    this->Disconnect(m_menuItemViewBellyROI->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewBellyROI), NULL, this);
    this->Disconnect(m_menuItemProcess->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatProcess), NULL, this);
    this->Disconnect(m_menuItemRatGenRefFrame->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatGenRefFrame), NULL, this);
    this->Disconnect(m_menuItemBatch->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnBatchProcess), NULL, this);
    this->Disconnect(m_menuItemCheckAPB->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRatCheckAPB), NULL, this);
    this->Disconnect(m_menuItemCleanOutput->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnToolsCleanOutput), NULL, this);
    this->Disconnect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    m_scrollWin->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotion), NULL, this);
    m_scrollWin->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MainFrameBaseClass::OnMouseLButtonDown), NULL, this);
    m_scrollWin->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MainFrameBaseClass::OnMouseRButtonDown), NULL, this);
    this->Disconnect(wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnFileOpen), NULL, this);
    m_bmpToggleBtnViewMark->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnViewMarks), NULL, this);
    m_bmpToggleBtnViewMark->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateViewMarks), NULL, this);
    m_bmpToggleBtnMarkCageLine->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkCageline), NULL, this);
    m_bmpToggleBtnMarkEyes->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkEyes), NULL, this);
    m_bmpToggleBtnMarkEars->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkEars), NULL, this);
    m_bmpToggleBtnMarkBelly->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMarkBelly), NULL, this);
    
    m_auimgr11->UnInit();
    delete m_auimgr11;

}
