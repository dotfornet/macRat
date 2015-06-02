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
    
    m_panel163 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel163, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer165 = new wxStaticBoxSizer( new wxStaticBox(m_panel163, wxID_ANY, _("Display signals")), wxVERTICAL);
    m_panel163->SetSizer(staticBoxSizer165);
    
    wxGridSizer* gridSizer167 = new wxGridSizer(0, 3, 0, 0);
    
    staticBoxSizer165->Add(gridSizer167, 1, wxALL|wxEXPAND, 5);
    
    m_checkBoxLED = new wxCheckBox(m_panel163, wxID_ANY, _("Ver Lines (LED+Ref.)"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxLED->SetValue(false);
    
    gridSizer167->Add(m_checkBoxLED, 0, wxALL, 5);
    
    m_checkBoxVerLine = new wxCheckBox(m_panel163, wxID_ANY, _("Ver. Line (0-based)"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxVerLine->SetValue(false);
    
    gridSizer167->Add(m_checkBoxVerLine, 0, wxLEFT|wxRIGHT|wxTOP, 5);
    
    m_textCtrlVerLine = new wxTextCtrl(m_panel163, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlVerLine->SetHint(wxT(""));
    #endif
    
    gridSizer167->Add(m_textCtrlVerLine, 0, wxLEFT|wxRIGHT|wxTOP, 5);
    
    m_checkBoxEyeMove = new wxCheckBox(m_panel163, wxID_ANY, _("Head"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxEyeMove->SetValue(false);
    
    gridSizer167->Add(m_checkBoxEyeMove, 0, wxALL, 5);
    
    m_checkBoxEar = new wxCheckBox(m_panel163, wxID_ANY, _("Ear"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxEar->SetValue(false);
    
    gridSizer167->Add(m_checkBoxEar, 0, wxALL, 5);
    
    m_checkBoxBelly = new wxCheckBox(m_panel163, wxID_ANY, _("Belly"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxBelly->SetValue(false);
    
    gridSizer167->Add(m_checkBoxBelly, 0, wxALL, 5);
    
    m_checkBoxBigHead = new wxCheckBox(m_panel163, wxID_ANY, _("Use Big Head"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxBigHead->SetValue(false);
    
    gridSizer167->Add(m_checkBoxBigHead, 0, wxALL, 5);
    
    m_checkBoxLED2 = new wxCheckBox(m_panel163, wxID_ANY, _("LED2 (1-based)"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxLED2->SetValue(false);
    
    gridSizer167->Add(m_checkBoxLED2, 0, wxALL, 5);
    
    m_textCtrlLED2 = new wxTextCtrl(m_panel163, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlLED2->SetHint(wxT(""));
    #endif
    
    gridSizer167->Add(m_textCtrlLED2, 0, wxALL, 5);
    
    m_panel171 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel171, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer173 = new wxStaticBoxSizer( new wxStaticBox(m_panel171, wxID_ANY, _("Signal types")), wxVERTICAL);
    m_panel171->SetSizer(staticBoxSizer173);
    
    wxGridSizer* gridSizer175 = new wxGridSizer(0, 3, 0, 0);
    
    staticBoxSizer173->Add(gridSizer175, 1, wxALL|wxEXPAND, 5);
    
    m_checkBoxOpticalPDF = new wxCheckBox(m_panel171, wxID_ANY, _("Opticalflow w/ PDF"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxOpticalPDF->SetValue(false);
    
    gridSizer175->Add(m_checkBoxOpticalPDF, 0, wxALL, 5);
    
    m_checkBoxGrayDiff = new wxCheckBox(m_panel171, wxID_ANY, _("Graylevel Diff"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxGrayDiff->SetValue(false);
    
    gridSizer175->Add(m_checkBoxGrayDiff, 0, wxALL, 5);
    
    m_checkBoxSaveFlow = new wxCheckBox(m_panel171, wxID_ANY, _("Save OpFlow"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxSaveFlow->SetValue(false);
    
    gridSizer175->Add(m_checkBoxSaveFlow, 0, wxALL, 5);
    
    m_staticText181 = new wxStaticText(m_panel171, wxID_ANY, _("OpticalFlow Type"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer175->Add(m_staticText181, 0, wxALL, 5);
    
    m_radioOpV1 = new wxRadioButton(m_panel171, wxID_ANY, _("V1 (stable)"), wxDefaultPosition, wxSize(-1,-1), wxRB_GROUP);
    m_radioOpV1->SetValue(1);
    
    gridSizer175->Add(m_radioOpV1, 0, wxALL, 5);
    
    m_radioOpV2 = new wxRadioButton(m_panel171, wxID_ANY, _("V2 (drastic)"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_radioOpV2->SetValue(1);
    
    gridSizer175->Add(m_radioOpV2, 0, wxALL, 5);
    
    m_staticLine781 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    boxSizer315->Add(m_staticLine781, 0, wxALL|wxEXPAND, 5);
    
    m_panel38 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_panel38->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    m_panel38->SetToolTip(_("set"));
    
    boxSizer315->Add(m_panel38, 0, wxLEFT|wxRIGHT|wxBOTTOM, 5);
    
    wxGridBagSizer* gridBagSizer40 = new wxGridBagSizer(0, 0);
    m_panel38->SetSizer(gridBagSizer40);
    
    m_staticText718 = new wxStaticText(m_panel38, wxID_ANY, _("Frame steps"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_staticText718->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    
    gridBagSizer40->Add(m_staticText718, wxGBPosition(0,0), wxGBSpan(1,1), wxALL, 5);
    
    m_textCtrlFrameSteps = new wxTextCtrl(m_panel38, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(50,-1), wxTE_RIGHT);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFrameSteps->SetHint(wxT(""));
    #endif
    
    gridBagSizer40->Add(m_textCtrlFrameSteps, wxGBPosition(0,1), wxGBSpan(1,1), wxALL, 5);
    
    m_staticText1320 = new wxStaticText(m_panel38, wxID_ANY, _("0: use single reference frame"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridBagSizer40->Add(m_staticText1320, wxGBPosition(0,2), wxGBSpan(1,2), wxALL, 5);
    
    m_staticText1923 = new wxStaticText(m_panel38, wxID_ANY, _("Probability threshold"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridBagSizer40->Add(m_staticText1923, wxGBPosition(1,0), wxGBSpan(1,1), wxALL, 5);
    
    m_textCtrlThreshold = new wxTextCtrl(m_panel38, wxID_ANY, wxT("0.005"), wxDefaultPosition, wxSize(60,-1), wxTE_RIGHT);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlThreshold->SetHint(wxT(""));
    #endif
    
    gridBagSizer40->Add(m_textCtrlThreshold, wxGBPosition(1,1), wxGBSpan(1,1), wxALL, 5);
    
    m_staticText132 = new wxStaticText(m_panel38, wxID_ANY, _("head gain *"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridBagSizer40->Add(m_staticText132, wxGBPosition(2,0), wxGBSpan(1,1), wxALL, 5);
    
    m_textCtrlHeadGain = new wxTextCtrl(m_panel38, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlHeadGain->SetHint(wxT(""));
    #endif
    
    gridBagSizer40->Add(m_textCtrlHeadGain, wxGBPosition(2,1), wxGBSpan(1,1), wxALL, 5);
    
    m_staticText136 = new wxStaticText(m_panel38, wxID_ANY, _("Belly gain *"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridBagSizer40->Add(m_staticText136, wxGBPosition(2,2), wxGBSpan(1,1), wxALL, 5);
    
    m_textCtrlBellyGain = new wxTextCtrl(m_panel38, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlBellyGain->SetHint(wxT(""));
    #endif
    
    gridBagSizer40->Add(m_textCtrlBellyGain, wxGBPosition(2,3), wxGBSpan(1,1), wxALL, 5);
    
    m_staticLine78 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    boxSizer315->Add(m_staticLine78, 0, wxALL|wxEXPAND, 5);
    
    m_panel187 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel187, 0, wxALL, 5);
    
    wxGridSizer* gridSizer189 = new wxGridSizer(3, 4, 0, 0);
    m_panel187->SetSizer(gridSizer189);
    
    m_staticText100 = new wxStaticText(m_panel187, wxID_ANY, _("Y range, min"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer189->Add(m_staticText100, 0, wxALL, 5);
    
    m_textCtrlYmin = new wxTextCtrl(m_panel187, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlYmin->SetHint(wxT(""));
    #endif
    
    gridSizer189->Add(m_textCtrlYmin, 0, wxALL, 5);
    
    m_staticText104 = new wxStaticText(m_panel187, wxID_ANY, _("max"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer189->Add(m_staticText104, 0, wxALL|wxALIGN_RIGHT, 5);
    
    m_textCtrlYmax = new wxTextCtrl(m_panel187, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlYmax->SetHint(wxT(""));
    #endif
    
    gridSizer189->Add(m_textCtrlYmax, 0, wxALL, 5);
    
    m_staticText124 = new wxStaticText(m_panel187, wxID_ANY, _("ROI Size, Ear"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer189->Add(m_staticText124, 0, wxALL, 5);
    
    m_textCtrlROIEar = new wxTextCtrl(m_panel187, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlROIEar->SetHint(wxT(""));
    #endif
    
    gridSizer189->Add(m_textCtrlROIEar, 0, wxALL, 5);
    
    m_staticText1241 = new wxStaticText(m_panel187, wxID_ANY, _("Belly"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer189->Add(m_staticText1241, 0, wxALL|wxALIGN_RIGHT, 5);
    
    m_textCtrlROIBelly = new wxTextCtrl(m_panel187, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlROIBelly->SetHint(wxT(""));
    #endif
    
    gridSizer189->Add(m_textCtrlROIBelly, 0, wxALL, 5);
    
    m_staticText203 = new wxStaticText(m_panel187, wxID_ANY, _("Refer. signal"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer189->Add(m_staticText203, 0, wxALL, 5);
    
    m_radioButtonRefBelly = new wxRadioButton(m_panel187, wxID_ANY, _("Belly"), wxDefaultPosition, wxSize(-1,-1), wxRB_GROUP);
    m_radioButtonRefBelly->SetValue(1);
    
    gridSizer189->Add(m_radioButtonRefBelly, 0, wxALL, 5);
    
    m_radioButtonRefHead = new wxRadioButton(m_panel187, wxID_ANY, _("Head"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_radioButtonRefHead->SetValue(1);
    
    gridSizer189->Add(m_radioButtonRefHead, 0, wxALL, 5);
    
    m_radioButtonRefEar = new wxRadioButton(m_panel187, wxID_ANY, _("Ear"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_radioButtonRefEar->SetValue(1);
    
    gridSizer189->Add(m_radioButtonRefEar, 0, wxALL, 5);
    
    m_panel116 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer315->Add(m_panel116, 0, wxLEFT|wxRIGHT, 5);
    
    wxBoxSizer* boxSizer118 = new wxBoxSizer(wxHORIZONTAL);
    m_panel116->SetSizer(boxSizer118);
    
    m_staticText126 = new wxStaticText(m_panel116, wxID_ANY, _("Refer. Frame"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer118->Add(m_staticText126, 0, wxALL, 5);
    
    m_textCtrlReferFrame = new wxTextCtrl(m_panel116, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(50,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlReferFrame->SetHint(wxT(""));
    #endif
    
    boxSizer118->Add(m_textCtrlReferFrame, 0, wxALL, 5);
    
    m_staticText130 = new wxStaticText(m_panel116, wxID_ANY, _("0: automatic"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer118->Add(m_staticText130, 0, wxALL, 5);
    
    m_staticLine108 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    boxSizer315->Add(m_staticLine108, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer52 = new wxStdDialogButtonSizer();
    
    boxSizer315->Add(m_stdBtnSizer52, 0, wxALL|wxALIGN_RIGHT, 5);
    
    m_button56 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button56->SetDefault();
    m_stdBtnSizer52->AddButton(m_button56);
    
    m_button58 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer52->AddButton(m_button58);
    m_stdBtnSizer52->Realize();
    
    SetName(wxT("DlgOpticalInputBase"));
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
}

DlgOpticalInputBase::~DlgOpticalInputBase()
{
}
