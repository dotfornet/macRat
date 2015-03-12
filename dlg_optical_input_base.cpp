//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: dlg_optical_input_base.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "dlg_optical_input_base.h"


// Declare the bitmap loading function
extern void wxC3A76InitBitmapResources();

static bool bBitmapLoaded = false;


DlgOpticalInputBase::DlgOpticalInputBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3A76InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer315 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer315);
    
    m_panel516 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel516, 0, wxALL, 5);
    
    wxBoxSizer* boxSizer1117 = new wxBoxSizer(wxHORIZONTAL);
    m_panel516->SetSizer(boxSizer1117);
    
    m_staticText718 = new wxStaticText(m_panel516, wxID_ANY, _("Frame steps"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer1117->Add(m_staticText718, 0, wxALL, 5);
    
    m_textCtrlFrameSteps = new wxTextCtrl(m_panel516, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(50,-1), wxTE_RIGHT);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFrameSteps->SetHint(wxT(""));
    #endif
    
    boxSizer1117->Add(m_textCtrlFrameSteps, 0, wxALL, 5);
    
    m_staticText1320 = new wxStaticText(m_panel516, wxID_ANY, _("0: use single reference frame"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer1117->Add(m_staticText1320, 0, wxALL, 5);
    
    m_panel1521 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel1521, 0, wxALL, 5);
    
    wxBoxSizer* boxSizer1722 = new wxBoxSizer(wxHORIZONTAL);
    m_panel1521->SetSizer(boxSizer1722);
    
    m_staticText1923 = new wxStaticText(m_panel1521, wxID_ANY, _("Probability threshold"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer1722->Add(m_staticText1923, 0, wxALL, 5);
    
    m_textCtrlThreshold = new wxTextCtrl(m_panel1521, wxID_ANY, wxT("0.005"), wxDefaultPosition, wxSize(90,-1), wxTE_RIGHT);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlThreshold->SetHint(wxT(""));
    #endif
    
    boxSizer1722->Add(m_textCtrlThreshold, 0, wxALL, 5);
    
    m_panel2325 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel2325, 0, wxALL|wxALIGN_RIGHT, 5);
    
    wxBoxSizer* boxSizer2526 = new wxBoxSizer(wxHORIZONTAL);
    m_panel2325->SetSizer(boxSizer2526);
    
    m_buttonOk = new wxButton(m_panel2325, wxID_OK, _("Ok"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonOk->SetDefault();
    
    boxSizer2526->Add(m_buttonOk, 0, wxALL, 5);
    
    m_buttonCancel = new wxButton(m_panel2325, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer2526->Add(m_buttonCancel, 0, wxALL, 5);
    
    SetSizeHints(400,200);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
}

DlgOpticalInputBase::~DlgOpticalInputBase()
{
}