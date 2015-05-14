//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef WXCRAFTER_BASE_CLASSES_H
#define WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/menu.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/dockart.h>
#include <wx/scrolwin.h>
#include "scrolled_image_component.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <map>
#include <wx/toolbar.h>
#include <wx/tglbtn.h>
#include <wx/button.h>
#include <wx/statusbr.h>

class MainFrameBaseClass : public wxFrame
{
public:
    enum {
        wxID_EDIT_CLEAR_MARKS = 1001,
        wxID_LOAD_RESULT = 1002,
        wxID_RAT_ABDOMEN = 1003,
        wxID_RAT_MARK_BELLY = 1004,
        wxID_RAT_MARK_EAR = 1005,
        wxID_RAT_MARK_EYE = 1006,
        wxID_RAT_PROCESS = 1007,
        wxID_SHOW_RESULT = 1008,
        wxID_VIEW_RESULT_SERIES = 1009,
        wxID_VIEW_SERIES = 1010,
    };
protected:
    wxMenuBar* m_menuBar;
    wxMenu* m_menuFile;
    wxMenuItem* m_menuItemOpen;
    wxMenuItem* m_menuItem7;
    wxMenu* m_menuEdit;
    wxMenuItem* m_menuEditClearMarks;
    wxMenu* m_menuView;
    wxMenuItem* m_menuItemViewMsgPane;
    wxMenuItem* m_menuItemViewSeries;
    wxMenuItem* m_menuItemViewResultSeries;
    wxMenuItem* m_menuItemViewFolderImage;
    wxMenuItem* m_menuItemView2D;
    wxMenuItem* m_menuItemView3D;
    wxMenu* m_menuRat;
    wxMenuItem* m_menuItemProcess;
    wxMenuItem* m_menuItemAbdomen;
    wxMenuItem* m_menuItemShowResults;
    wxMenuItem* m_menuItemLoadResult;
    wxMenu* m_menuTools;
    wxMenuItem* m_menuItemCleanOutput;
    wxMenu* m_nameHelp;
    wxMenuItem* m_menuItem9;
    wxAuiManager* m_auimgr11;
    ScrolledImageComponent* m_scrollWin;
    wxPanel* m_panel15;
    wxRichTextCtrl* m_richTextMsg;
    wxAuiToolBar* m_auibar31;
    wxBitmapToggleButton* m_bmpToggleBtnMarkCageLine;
    wxBitmapToggleButton* m_bmpToggleBtnMarkEyes;
    wxBitmapToggleButton* m_bmpToggleBtnMarkEars;
    wxBitmapToggleButton* m_bmpToggleBtnMarkBelly;
    wxStatusBar* m_statusBar;

protected:
    virtual void OnFileOpen(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEditClearMarks(wxCommandEvent& event) { event.Skip(); }
    virtual void OnViewMsgPane(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateViewMsgPane(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnViewSeries(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateViewSeries(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnViewResultSeries(wxCommandEvent& event) { event.Skip(); }
    virtual void OnViewFolderImage(wxCommandEvent& event) { event.Skip(); }
    virtual void OnView2DData(wxCommandEvent& event) { event.Skip(); }
    virtual void OnView3DData(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRatProcessEar(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRatAbdomen(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRatShowResults(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRatLoadResult(wxCommandEvent& event) { event.Skip(); }
    virtual void OnToolsCleanOutput(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMouseMotion(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMouseLButtonDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMouseRButtonDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMarkCageline(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMarkEyes(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMarkEars(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMarkBelly(wxCommandEvent& event) { event.Skip(); }

public:
    MainFrameBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("My Frame"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(700,500), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~MainFrameBaseClass();
};

#endif
