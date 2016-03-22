#ifndef DLGCYCLEOCCUR_H
#define DLGCYCLEOCCUR_H
#include "dlg_cycleOccur_base.h"

class DlgCycleOccur : public DlgCycleOccurBase
{
public:
    DlgCycleOccur(wxWindow* parent, wxString& strInitFilename);
    virtual ~DlgCycleOccur();
	
	wxString	m_strFilename;

protected:
    virtual void OnGroupAmpIntvl(wxCommandEvent& event);
    virtual void OnGroupIncDec(wxCommandEvent& event);
    virtual void OnGroupSound(wxCommandEvent& event);
    virtual void OnButtonBrowse(wxCommandEvent& event);
};
#endif // DLGCYCLEOCCUR_H
