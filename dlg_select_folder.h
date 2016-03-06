//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: dlg_select_folder.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef MACRAT_DLG_SELECT_FOLDER_BASE_CLASSES_H
#define MACRAT_DLG_SELECT_FOLDER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class DlgSelectFolderBase : public wxDialog
{
protected:
    wxPanel* m_panel29;
    wxPanel* m_panel85;
    wxStaticText* m_staticText33;
    wxTextCtrl* m_textCtrlFolder;
    wxButton* m_buttonSelFolder;
    wxPanel* m_panel39;
    wxStaticText* m_staticText43;
    wxTextCtrl* m_textCtrlSmooth;
    wxCheckBox* m_checkBoxSymbol;
    wxCheckBox* m_checkBoxFirst;
    wxStdDialogButtonSizer* m_stdBtnSizer75;
    wxButton* m_button77;
    wxButton* m_button79;

protected:
    virtual void OnButtonSelectFolder(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText33() { return m_staticText33; }
    wxTextCtrl* GetTextCtrlFolder() { return m_textCtrlFolder; }
    wxButton* GetButtonSelFolder() { return m_buttonSelFolder; }
    wxPanel* GetPanel85() { return m_panel85; }
    wxStaticText* GetStaticText43() { return m_staticText43; }
    wxTextCtrl* GetTextCtrlSmooth() { return m_textCtrlSmooth; }
    wxCheckBox* GetCheckBoxSymbol() { return m_checkBoxSymbol; }
    wxCheckBox* GetCheckBoxFirst() { return m_checkBoxFirst; }
    wxPanel* GetPanel39() { return m_panel39; }
    wxPanel* GetPanel29() { return m_panel29; }
    DlgSelectFolderBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select folder"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~DlgSelectFolderBase();
};

#endif
