//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: dlg_select_folder.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "dlg_select_folder.h"


// Declare the bitmap loading function
extern void wxCEF84InitBitmapResources();

static bool bBitmapLoaded = false;


DlgSelectFolderBase::DlgSelectFolderBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCEF84InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer19 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer19);
    
    m_panel29 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer19->Add(m_panel29, 0, wxALL, 5);
    
    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    m_panel29->SetSizer(boxSizer31);
    
    m_staticText33 = new wxStaticText(m_panel29, wxID_ANY, _("Folder"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer31->Add(m_staticText33, 0, wxALL, 5);
    
    m_textCtrlFolder = new wxTextCtrl(m_panel29, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(300,-1), wxTE_RIGHT|wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFolder->SetHint(wxT(""));
    #endif
    
    boxSizer31->Add(m_textCtrlFolder, 0, wxALL, 5);
    
    m_buttonSelFolder = new wxButton(m_panel29, wxID_ANY, _("Select Folder"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer31->Add(m_buttonSelFolder, 0, wxALL, 5);
    
    m_staticLine27 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    boxSizer19->Add(m_staticLine27, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer21 = new wxStdDialogButtonSizer();
    
    boxSizer19->Add(m_stdBtnSizer21, 0, wxALL|wxALIGN_RIGHT, 5);
    
    m_button23 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer21->AddButton(m_button23);
    
    m_button25 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer21->AddButton(m_button25);
    m_stdBtnSizer21->Realize();
    
    SetName(wxT("DlgSelectFolderBase"));
    SetSizeHints(500,300);
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
    m_buttonSelFolder->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DlgSelectFolderBase::OnButtonSelectFolder), NULL, this);
    
}

DlgSelectFolderBase::~DlgSelectFolderBase()
{
    m_buttonSelFolder->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DlgSelectFolderBase::OnButtonSelectFolder), NULL, this);
    
}
