//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: dlg_optical_input_base.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef MACRAT_DLG_OPTICAL_INPUT_BASE_BASE_CLASSES_H
#define MACRAT_DLG_OPTICAL_INPUT_BASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class DlgOpticalInputBase : public wxDialog
{
protected:
    wxPanel* m_panel163;
    wxCheckBox* m_checkBoxLED;
    wxCheckBox* m_checkBoxVerLine;
    wxTextCtrl* m_textCtrlVerLine;
    wxCheckBox* m_checkBoxEyeMove;
    wxCheckBox* m_checkBoxEar;
    wxCheckBox* m_checkBoxBelly;
    wxCheckBox* m_checkBoxBigHead;
    wxCheckBox* m_checkBoxLED2;
    wxTextCtrl* m_textCtrlLED2;
    wxPanel* m_panel171;
    wxCheckBox* m_checkBoxOpticalPDF;
    wxCheckBox* m_checkBoxGrayDiff;
    wxStaticLine* m_staticLine261;
    wxStaticText* m_staticText181;
    wxRadioButton* m_radioOpV1;
    wxRadioButton* m_radioOpV2;
    wxCheckBox* m_checkBoxSaveFlow;
    wxCheckBox* m_checkBoxSaveSignalPlot;
    wxCheckBox* m_checkBoxShowPeak;
    wxStaticLine* m_staticLine781;
    wxPanel* m_panel38;
    wxStaticText* m_staticText718;
    wxTextCtrl* m_textCtrlFrameSteps;
    wxStaticText* m_staticText1320;
    wxStaticText* m_staticText1923;
    wxTextCtrl* m_textCtrlThreshold;
    wxStaticText* m_staticText132;
    wxTextCtrl* m_textCtrlHeadGain;
    wxStaticText* m_staticText136;
    wxTextCtrl* m_textCtrlBellyGain;
    wxStaticLine* m_staticLine78;
    wxPanel* m_panel187;
    wxStaticText* m_staticText100;
    wxTextCtrl* m_textCtrlAmpYmin;
    wxStaticText* m_staticText104;
    wxTextCtrl* m_textCtrlAmpYmax;
    wxStaticText* m_staticText273;
    wxTextCtrl* m_textCtrlSoundYAmp;
    wxStaticText* m_staticText1002;
    wxTextCtrl* m_textCtrlIntervalYmin;
    wxStaticText* m_staticText1044;
    wxTextCtrl* m_textCtrlIntervalYmax;
    wxStaticText* m_staticText2736;
    wxTextCtrl* m_textCtrlSoundYInterval;
    wxStaticText* m_staticText124;
    wxTextCtrl* m_textCtrlROIEar;
    wxStaticText* m_staticTextSmooth;
    wxTextCtrl* m_textCtrlSmoothEar;
    wxStaticText* m_staticText1241;
    wxTextCtrl* m_textCtrlROIBelly;
    wxStaticText* m_staticText305;
    wxTextCtrl* m_textCtrlSmoothBelly;
    wxStaticText* m_staticText203;
    wxRadioButton* m_radioButtonRefBelly;
    wxRadioButton* m_radioButtonRefHead;
    wxRadioButton* m_radioButtonRefEar;
    wxStaticText* m_staticText126;
    wxTextCtrl* m_textCtrlReferFrame;
    wxStaticText* m_staticText130;
    wxTextCtrl* m_textCtrlXSD;
    wxCheckBox* m_checkBoxShowAxisLabel;
    wxStaticLine* m_staticLine108;
    wxStdDialogButtonSizer* m_stdBtnSizer243;
    wxButton* m_button245;
    wxButton* m_button247;

protected:

public:
    wxCheckBox* GetCheckBoxLED() { return m_checkBoxLED; }
    wxCheckBox* GetCheckBoxVerLine() { return m_checkBoxVerLine; }
    wxTextCtrl* GetTextCtrlVerLine() { return m_textCtrlVerLine; }
    wxCheckBox* GetCheckBoxEyeMove() { return m_checkBoxEyeMove; }
    wxCheckBox* GetCheckBoxEar() { return m_checkBoxEar; }
    wxCheckBox* GetCheckBoxBelly() { return m_checkBoxBelly; }
    wxCheckBox* GetCheckBoxBigHead() { return m_checkBoxBigHead; }
    wxCheckBox* GetCheckBoxLED2() { return m_checkBoxLED2; }
    wxTextCtrl* GetTextCtrlLED2() { return m_textCtrlLED2; }
    wxPanel* GetPanel163() { return m_panel163; }
    wxCheckBox* GetCheckBoxOpticalPDF() { return m_checkBoxOpticalPDF; }
    wxCheckBox* GetCheckBoxGrayDiff() { return m_checkBoxGrayDiff; }
    wxStaticLine* GetStaticLine261() { return m_staticLine261; }
    wxStaticText* GetStaticText181() { return m_staticText181; }
    wxRadioButton* GetRadioOpV1() { return m_radioOpV1; }
    wxRadioButton* GetRadioOpV2() { return m_radioOpV2; }
    wxCheckBox* GetCheckBoxSaveFlow() { return m_checkBoxSaveFlow; }
    wxCheckBox* GetCheckBoxSaveSignalPlot() { return m_checkBoxSaveSignalPlot; }
    wxCheckBox* GetCheckBoxShowPeak() { return m_checkBoxShowPeak; }
    wxPanel* GetPanel171() { return m_panel171; }
    wxStaticLine* GetStaticLine781() { return m_staticLine781; }
    wxStaticText* GetStaticText718() { return m_staticText718; }
    wxTextCtrl* GetTextCtrlFrameSteps() { return m_textCtrlFrameSteps; }
    wxStaticText* GetStaticText1320() { return m_staticText1320; }
    wxStaticText* GetStaticText1923() { return m_staticText1923; }
    wxTextCtrl* GetTextCtrlThreshold() { return m_textCtrlThreshold; }
    wxStaticText* GetStaticText132() { return m_staticText132; }
    wxTextCtrl* GetTextCtrlHeadGain() { return m_textCtrlHeadGain; }
    wxStaticText* GetStaticText136() { return m_staticText136; }
    wxTextCtrl* GetTextCtrlBellyGain() { return m_textCtrlBellyGain; }
    wxPanel* GetPanel38() { return m_panel38; }
    wxStaticLine* GetStaticLine78() { return m_staticLine78; }
    wxStaticText* GetStaticText100() { return m_staticText100; }
    wxTextCtrl* GetTextCtrlAmpYmin() { return m_textCtrlAmpYmin; }
    wxStaticText* GetStaticText104() { return m_staticText104; }
    wxTextCtrl* GetTextCtrlAmpYmax() { return m_textCtrlAmpYmax; }
    wxStaticText* GetStaticText273() { return m_staticText273; }
    wxTextCtrl* GetTextCtrlSoundYAmp() { return m_textCtrlSoundYAmp; }
    wxStaticText* GetStaticText1002() { return m_staticText1002; }
    wxTextCtrl* GetTextCtrlIntervalYmin() { return m_textCtrlIntervalYmin; }
    wxStaticText* GetStaticText1044() { return m_staticText1044; }
    wxTextCtrl* GetTextCtrlIntervalYmax() { return m_textCtrlIntervalYmax; }
    wxStaticText* GetStaticText2736() { return m_staticText2736; }
    wxTextCtrl* GetTextCtrlSoundYInterval() { return m_textCtrlSoundYInterval; }
    wxStaticText* GetStaticText124() { return m_staticText124; }
    wxTextCtrl* GetTextCtrlROIEar() { return m_textCtrlROIEar; }
    wxStaticText* GetStaticTextSmooth() { return m_staticTextSmooth; }
    wxTextCtrl* GetTextCtrlSmoothEar() { return m_textCtrlSmoothEar; }
    wxStaticText* GetStaticText1241() { return m_staticText1241; }
    wxTextCtrl* GetTextCtrlROIBelly() { return m_textCtrlROIBelly; }
    wxStaticText* GetStaticText305() { return m_staticText305; }
    wxTextCtrl* GetTextCtrlSmoothBelly() { return m_textCtrlSmoothBelly; }
    wxStaticText* GetStaticText203() { return m_staticText203; }
    wxRadioButton* GetRadioButtonRefBelly() { return m_radioButtonRefBelly; }
    wxRadioButton* GetRadioButtonRefHead() { return m_radioButtonRefHead; }
    wxRadioButton* GetRadioButtonRefEar() { return m_radioButtonRefEar; }
    wxStaticText* GetStaticText126() { return m_staticText126; }
    wxTextCtrl* GetTextCtrlReferFrame() { return m_textCtrlReferFrame; }
    wxStaticText* GetStaticText130() { return m_staticText130; }
    wxTextCtrl* GetTextCtrlXSD() { return m_textCtrlXSD; }
    wxCheckBox* GetCheckBoxShowAxisLabel() { return m_checkBoxShowAxisLabel; }
    wxPanel* GetPanel187() { return m_panel187; }
    wxStaticLine* GetStaticLine108() { return m_staticLine108; }
    DlgOpticalInputBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Optical Input Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~DlgOpticalInputBase();
};

#endif
