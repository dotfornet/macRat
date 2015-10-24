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
#include <wx/statline.h>
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
    wxStaticText* m_staticText33;
    wxTextCtrl* m_textCtrlFolder;
    wxButton* m_buttonSelFolder;
    wxStaticLine* m_staticLine27;
    wxStdDialogButtonSizer* m_stdBtnSizer21;
    wxButton* m_button23;
    wxButton* m_button25;

protected:
    virtual void OnButtonSelectFolder(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText33() { return m_staticText33; }
    wxTextCtrl* GetTextCtrlFolder() { return m_textCtrlFolder; }
    wxButton* GetButtonSelFolder() { return m_buttonSelFolder; }
    wxPanel* GetPanel29() { return m_panel29; }
    wxStaticLine* GetStaticLine27() { return m_staticLine27; }
    DlgSelectFolderBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select folder"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(570,300), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~DlgSelectFolderBase();
};

#endif
