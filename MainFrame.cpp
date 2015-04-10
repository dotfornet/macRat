#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/bitmap.h>
#include <wx/log.h>
#include <wx/config.h>

#include <wx/dcclient.h>
#include <wx/dirdlg.h> 
#include <wx/msgdlg.h> 
#include <wx/filename.h>
#include <wx/utils.h> 
#include <wx/dir.h>

#include <opencv2/opencv.hpp>
#include "KDE.h"
#include "MyUtil.h"
#include "gnuplot_i.h"


using namespace std;
using namespace cv;

vector <Mat> gvecMat;

MainFrame *	MainFrame::m_pThis=NULL;

MainFrame::MainFrame(wxWindow* parent)
	: MainFrameBaseClass(parent)
{
#if defined(__WXMAC__)
/*
	wxIcon  icon;
	wxBitmap bitmap(wxT("ratty32.png"), wxBITMAP_TYPE_PNG); 
	icon.CopyFromBitmap(bitmap); 
	SetIcon(icon);
*/
#else
	SetIcon(wxICON(frame_icon));
#endif

	m_pThis = this;
	m_menuItemViewMsgPane->Check(true);

	int statusWidth[4] = {250, 110, 40, 140};
	m_statusBar->SetFieldsCount(4, statusWidth);
	
	wxConfigBase *pConfig = wxConfigBase::Get();
	m_FileHistory = new wxFileHistory(9);
	m_FileHistory->UseMenu(m_menuFile);
	m_FileHistory->AddFilesToMenu(m_menuFile);
	m_FileHistory->Load(*pConfig);
	
	////////////////////////////
	m_configData.m_frameStep = pConfig->ReadLong("/optical/frameStep", 5);
	m_configData.m_threshold = pConfig->ReadDouble("/optical/threshold", 0.001);
	m_configData.m_bLED = pConfig->ReadBool("/optical/bLED", false);    
    m_configData.m_bRefLine = pConfig->ReadBool("/optical/bRefLine", true);
	m_configData.m_bPinna = pConfig->ReadBool("/optical/bPinna", false);
	m_configData.m_bVerLine = pConfig->ReadBool("/optical/bVerLine", false);
	
	m_configData.m_bEyeMove = pConfig->ReadBool("/optical/bEyeMove", false);
	m_configData.m_bGrayDiff = pConfig->ReadBool("/optical/bGrayDiff", false);
    m_configData.m_bEar = pConfig->ReadBool("/optical/bEar", false);
	m_configData.m_bAbdo = pConfig->ReadBool("/optical/bAbdo", false);
	m_configData.m_bOpticalPDF = pConfig->ReadBool("/optical/bOpticalPDF", true);
	m_configData.m_bAccumulate = pConfig->ReadBool("/optical/bAccumulate", true);
	m_configData.m_bSaveFile = pConfig->ReadBool("/optical/bSaveFile", false);
	
	m_configData.m_verLine = pConfig->ReadDouble("/optical/verLine", 190);
	m_configData.m_ymin = pConfig->ReadDouble("/optical/ymin", 0);
	m_configData.m_ymax = pConfig->ReadDouble("/optical/ymax", 5);
	m_configData.m_szROI = pConfig->ReadLong("/optical/ROISize", 80);
    m_configData.m_referFrame = pConfig->ReadLong("/optical/referFrame", 0);
	m_configData.m_gainEye = pConfig->ReadDouble("/optical/gainEye", 2.5);
	m_configData.m_gainPDF = pConfig->ReadDouble("/optical/gainPDF", 4);
	

	this->Connect(wxID_FILE1, wxID_FILE9, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnMRUFile), NULL, this);
	
	SetSize(800, 650);
	Center();
	

	
	DeleteContents();

}

MainFrame::~MainFrame()
{
	DeleteContents();
	
	wxConfigBase *pConfig = wxConfigBase::Get();
	m_FileHistory->Save(*pConfig);
	delete m_FileHistory;	
	delete wxConfigBase::Set((wxConfigBase *) NULL);
}

void MainFrame::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	wxConfigBase *pConfig = wxConfigBase::Get();
	pConfig->Write("/optical/frameStep", m_configData.m_frameStep);
	pConfig->Write("/optical/threshold", m_configData.m_threshold);
	pConfig->Write("/optical/bLED", m_configData.m_bLED);
    pConfig->Write("/optical/bRefLine", m_configData.m_bRefLine);
	pConfig->Write("/optical/bPinna", m_configData.m_bPinna);
	pConfig->Write("/optical/bVerLine", m_configData.m_bVerLine);
	
	pConfig->Write("/optical/bEyeMove", m_configData.m_bEyeMove);
    pConfig->Write("/optical/bEar", m_configData.m_bEar);
	pConfig->Write("/optical/bAbdo", m_configData.m_bAbdo);
   	pConfig->Write("/optical/bGrayDiff", m_configData.m_bGrayDiff); 
	pConfig->Write("/optical/bOpticalPDF", m_configData.m_bOpticalPDF);
	pConfig->Write("/optical/bAccumulate", m_configData.m_bAccumulate);
	pConfig->Write("/optical/bSaveFile", m_configData.m_bSaveFile);
	
	pConfig->Write("/optical/verLine", m_configData.m_verLine);
	pConfig->Write("/optical/ymin", m_configData.m_ymin);
	pConfig->Write("/optical/ymax", m_configData.m_ymax);
	pConfig->Write("/optical/ROISize", m_configData.m_szROI);
    pConfig->Write("/optical/referFrame", m_configData.m_referFrame);
	
	pConfig->Write("/optical/gainEye", m_configData.m_gainEye);
    pConfig->Write("/optical/gainPDF", m_configData.m_gainPDF);	
	
	m_nSlices = 0;
	m_nCageLine = -1;
	m_bCutTop = false;
	m_bHasCrop = false;
	
	m_bMarkEye = false;
	m_bMarkEar = false;
	m_bMarkAbdomen = false;
	m_bMarkCageline = false;
	
	m_dqEyePts.clear();
	m_dqEarPts.clear();
	m_dqAbdoPts.clear();
	
	m_ptAbdoRed = m_ptAbdoCyan = m_ptEyeL = m_ptEyeR = m_ptEarL = m_ptEarR = Point(0,0);
	
	m_bmpToggleBtnMarkEyes->SetValue(false);
	m_bmpToggleBtnMarkEars->SetValue(false);	
	m_bmpToggleBtnMarkAbdo->SetValue(false);
}
void MainFrame::OnMRUFile(wxCommandEvent& event)
{
	wxString f(m_FileHistory->GetHistoryFile(event.GetId() - wxID_FILE1));
	if (!f.empty())  openFile(f);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	wxUnusedVar(event);
	Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxUnusedVar(event);
	wxAboutDialogInfo info;
	info.SetCopyright(_("My MainFrame"));
	info.SetLicence(_("GPL v2 or later"));
	info.SetDescription(_("Short description goes here"));
	::wxAboutBox(info);
}
void MainFrame::OnFileOpen(wxCommandEvent& event)
{	
	wxString  strHistoryFile = wxEmptyString;
	if(m_FileHistory->GetCount() >0) 
		strHistoryFile= m_FileHistory->GetHistoryFile(0);
	
	static wxString strInitDir (strHistoryFile);
	wxString dirName = wxDirSelector("Choose a folder", strInitDir); //"E:\\Image_Data\\Mouse\\");
	if(dirName.empty())  return;
	m_FileHistory->AddFileToHistory(dirName);	
	strInitDir = dirName;
	openFile(dirName);	
	wxBell();
}

void MainFrame::readMarks(wxString &dirName)
{
	wxFileName fileName = dirName;
	wxFileName dataName(dirName, "_Marks.txt");
	if(dataName.IsFileReadable() ==false) return;
	
			
	Point ptEyeL, ptEyeR, ptEarL, ptEarR;
	Point ptAbdoRed, ptAbdoCyan;
	int n, line;
	char  type;
	FILE* fp = fopen(dataName.GetFullPath(), "r");
	do{
		fscanf(fp, "%c", &type);
		switch(type) {
			case 'E': 
				n = fscanf(fp, "%d %d %d %d\n", &ptEarL.x, &ptEarL.y, &ptEarR.x, &ptEarR.y);
				if(n==4) {
					m_dqEarPts.push_back(ptEarL);
					m_dqEarPts.push_back(ptEarR);
					m_ptEarL = m_dqEarPts[0];
					m_ptEarR = m_dqEarPts[1];
				}	
				myMsgOutput("E %d %d %d\n", ptEarL.x, ptEarL.y, ptEarR.x, ptEarR.y);
				break;	
			case 'Y':
				n = fscanf(fp, "%d %d %d %d\n", &ptEyeL.x, &ptEyeL.y, &ptEyeR.x, &ptEyeR.y );
				if(n==4) {
					m_dqEyePts.push_back(ptEyeL);
					m_dqEyePts.push_back(ptEyeR);
					m_ptEyeL = m_dqEyePts[0];
					m_ptEyeR = m_dqEyePts[1];
				}
				myMsgOutput("Y %d %d %d %d\n", ptEyeL.x, ptEyeL.y, ptEyeR.x, ptEyeR.y );
				break;
			case 'A':
				n = fscanf(fp, "%d %d %d %d\n", &ptAbdoRed.x, &ptAbdoRed.y, &ptAbdoCyan.x, &ptAbdoCyan.y );
				if(n==4) {
					m_dqAbdoPts.push_back(ptAbdoRed);
					m_dqAbdoPts.push_back(ptAbdoCyan);
					m_ptAbdoRed = m_dqAbdoPts[0];
					m_ptAbdoCyan = m_dqAbdoPts[1];
				}		
				myMsgOutput("A Red[%d %d], Cyan[%d %d]\n", ptAbdoRed.x, ptAbdoRed.y, ptAbdoCyan.x, ptAbdoCyan.y );
				break;	
			case 'C':
				n = fscanf(fp, "%d\n", &line);
				if(n==1)  m_nCageLine = line;
				else m_nCageLine = -1;
				myMsgOutput("C %d\n", line);
				break;
		}
		
	}while(!feof(fp));

	fclose(fp);
	
}
void MainFrame::openFile(wxString &dirName)
{
	DeleteContents();

	m_strSourcePath = dirName;
	myMsgOutput("++++++++++++++++++++++++++++++++++++++++++++++++\n");
	myMsgOutput( "Load " + dirName + "\n");

	bool  bRet = false;
	if(m_Rat.readData(dirName) <=0) 
		return;
		
	readMarks(dirName);
	
	m_nSlices = m_Rat.getNumFrames();
	m_szOriSize = m_Rat.getImgSize();
	updateOutData(m_Rat.getSrcImg(0));

	wxString title = dirName.AfterLast('\\');
	SetTitle(wxString("Dataset: ") << title);
	
}
void MainFrame::updateOutData(Mat& mOut)
{
	mOut.copyTo(m_mOut);

	m_nDepth = m_mOut.depth();
	m_nChannel = m_mOut.channels();
    m_nBpp = m_mOut.elemSize() * 8;
	m_szOutImg = Size(m_mOut.cols, m_mOut.rows);

	m_scrollWin->setImage(mOut);

	wxString strSize;
	strSize.Printf("%d x %d", mOut.cols, mOut.rows);
	
	m_statusBar->SetStatusText(strSize, 1);

	wxString strFormat;
	wxString strDepth;
	switch (m_nDepth) {
		case CV_8U: strDepth = "8U";  break;
		case CV_8S: strDepth = "8S";  break;
		case CV_16U: strDepth = "16U";  break;
		case CV_16S: strDepth = "16S";  break;
		case CV_32S: strDepth = "32S";  break;
		case CV_32F: strDepth = "32F";  break;
		case CV_64F: strDepth = "64F";  break;
		default: strDepth = "unknown"; break;
	}
	strFormat.Printf("%sC%d", strDepth, m_nChannel);
	m_statusBar->SetStatusText(strFormat, 2);

}

/*
void MainFrame::OnMouseLDown(wxMouseEvent& event)
{
//	wxPoint pt = m_staticBitmap->GetLogicalPosition

}
 * */
void MainFrame::OnViewMsgPane(wxCommandEvent& event)
{

	wxAuiPaneInfo &pane =  m_auimgr11->GetPane(wxT("MsgPane"));
	pane.Show(!pane.IsShown());

	m_auimgr11->Update();
}

void MainFrame::OnUpdateViewMsgPane(wxUpdateUIEvent& event)
{
	wxAuiPaneInfo &pane =  m_auimgr11->GetPane(wxT("MsgPane"));
	event.Check(pane.IsShown());
}

void MainFrame::OnMouseMotion(wxMouseEvent& event)
{
	if (getNumSlices() <= 0)  {
		return;
	}
	
	wxClientDC *pDC = new wxClientDC(this);
	wxPoint pt1 = event.GetLogicalPosition(*pDC);
	wxPoint pt;
	m_scrollWin->CalcUnscrolledPosition(pt1.x, pt1.y, &pt.x, &pt.y);	

	Mat mat = getCurrentMat(0);
	
	if (pt.x >= mat.cols || pt.y >= mat.rows)
		return;
	
	int type = mat.type();
	wxString str;

	if(type ==CV_8UC3) {
		cv::Vec3b c;
		c = mat.at<cv::Vec3b>(pt.y, pt.x);
		uchar b = c.val[0];
		uchar g = c.val[1];
		uchar r = c.val[2];
		str.Printf("(%d, %d)  [%d %d %d]", pt.x, pt.y, r & 0xFF, g & 0xFF, b & 0xFF);
	}else if(type ==CV_8UC4) {
		cv::Vec4b c;
		c = mat.at<cv::Vec4b>(pt.y, pt.x);
		uchar b = c.val[0];
		uchar g = c.val[1];
		uchar r = c.val[2];
		uchar u = c.val[3];
		str.Printf("(%d, %d)  [%d %d %d %d]", pt.x, pt.y, r&0xFF, g&0xFF, b&0xFF, u&0xFF);
	}else if (type == CV_8UC1) {
		short v1 =  mat.at<uchar>(pt.y, pt.x);
		str.Printf("(%d, %d) idx %d", pt.x, pt.y, v1);
	}
	
	m_statusBar->SetStatusText(str, 3);
}
void MainFrame::OnEditClearMarks(wxCommandEvent& event)
{
	m_bMarkEar = false;
	m_bMarkEye = false;
	m_bMarkAbdomen = false;
	m_bmpToggleBtnMarkEars->SetValue(false);
	m_bmpToggleBtnMarkEyes->SetValue(false);
	m_bmpToggleBtnMarkAbdo->SetValue(false);
	
	m_dqEyePts.clear();
	m_dqEarPts.clear();
	m_dqAbdoPts.clear();
	Refresh();
}
void MainFrame::OnMarkEyes(wxCommandEvent& event)
{
	if(event.IsChecked()) {
		if(m_bMarkEar)  {
			m_bmpToggleBtnMarkEars->SetValue(false);
			m_bMarkEar = false;
		}
		if(m_bMarkAbdomen)  {
			m_bmpToggleBtnMarkAbdo->SetValue(false);
			m_bMarkAbdomen = false;
		}	
		if(m_bMarkCageline)  {
			m_bmpToggleBtnMarkCageLine->SetValue(false);
			m_bMarkCageline = false;
		}	
		m_bMarkEye = true;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_CROSS ));
	}else {
		m_bMarkEye = false;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_ARROW ));
	}	
}
void MainFrame::OnMarkEars(wxCommandEvent& event)
{
	if(event.IsChecked()) {
		if(m_bMarkEye) { 
			m_bmpToggleBtnMarkEyes->SetValue(false);
			m_bMarkEye = false;
		}
		if(m_bMarkAbdomen)  {
			m_bmpToggleBtnMarkAbdo->SetValue(false);
			m_bMarkAbdomen = false;
		}	
		if(m_bMarkCageline)  {
			m_bmpToggleBtnMarkCageLine->SetValue(false);
			m_bMarkCageline = false;
		}	
		m_bMarkEar = true;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_CROSS ));
	}else {
		m_bMarkEar = false;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_ARROW ));
	}		
}
void MainFrame::OnMarkAbdomen(wxCommandEvent& event)
{
	if(event.IsChecked()) {
		if(m_bMarkEye) { 
			m_bmpToggleBtnMarkEyes->SetValue(false);
			m_bMarkEye = false;
		}
		if(m_bMarkEar)  {
			m_bmpToggleBtnMarkEars->SetValue(false);
			m_bMarkEar = false;
		}	
		if(m_bMarkCageline)  {
			m_bmpToggleBtnMarkCageLine->SetValue(false);
			m_bMarkCageline = false;
		}
		m_bMarkAbdomen = true;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_CROSS ));
	}else {
		m_bMarkAbdomen = false;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_ARROW ));
	}	
}
void MainFrame::OnMarkCageline(wxCommandEvent& event)
{
	if(event.IsChecked()) {
		if(m_bMarkEye) { 
			m_bmpToggleBtnMarkEyes->SetValue(false);
			m_bMarkEye = false;
		}
		if(m_bMarkEar)  {
			m_bmpToggleBtnMarkEars->SetValue(false);
			m_bMarkEar = false;
		}	
		if(m_bMarkAbdomen)  {
			m_bmpToggleBtnMarkAbdo->SetValue(false);
			m_bMarkAbdomen = false;
		}	
		m_bMarkCageline = true;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_CROSS ));
	}else {
		m_bMarkCageline = false;
		m_scrollWin->SetCursor(wxCursor(wxCURSOR_ARROW ));
	}		
}

void MainFrame::recognizeLeftRight(Point& ptEyeL, Point& ptEyeR, Point& ptEarL, Point& ptEarR)
{
	Point eyeCenter = (ptEyeL + ptEyeR) *0.5;
	Point earCenter = (ptEarL + ptEarR) *0.5;

	cv::Point u, v;
	float angle;

	// for ear
	u = earCenter - eyeCenter;
	v = ptEarL - eyeCenter;
	angle = asin(u.cross(v) / (norm(u)*norm(v)));
	if (angle < 0) {
		Point t = ptEarR;
		ptEarR = ptEarL;
		ptEarL = t;
	}

	// for eyes
	v = ptEyeL - earCenter;
	angle = asin(u.cross(v) / (norm(u)*norm(v)));
	if (angle < 0) {
		Point t = ptEyeR;
		ptEyeR = ptEyeL;
		ptEyeL = t;
	}
//	gpOutput->ShowMessage("angle %.2f\n", angle);
}

bool MainFrame::preprocessing()
{
	if(m_nCageLine<=0) {
		wxMessageBox("set cage horizontal line", "error");
		return false;
	}	
    myMsgOutput("-------------------------------------------------\n");	
    
	wxFileName dataName(m_strSourcePath, "_Marks.txt");
	FILE* fp = fopen(dataName.GetFullPath(), "w");
	if(fp!=NULL) {
		if(m_dqEyePts.size()>=2) {
			fprintf(fp, "Y%d %d %d %d\n", m_dqEyePts[0].x, m_dqEyePts[0].y, m_dqEyePts[1].x, m_dqEyePts[1].y );
			myMsgOutput("Left Eye: [%d, %d], Right Eye: [%d, %d]\n", m_dqEyePts[0].x, m_dqEyePts[0].y, m_dqEyePts[1].x, m_dqEyePts[1].y );
		}
		if(m_dqEarPts.size()>=2) {
			fprintf(fp, "E%d %d %d %d\n", m_dqEarPts[0].x, m_dqEarPts[0].y, m_dqEarPts[1].x, m_dqEarPts[1].y );
			myMsgOutput("Left Ear: [%d, %d], Right Ear: [%d, %d]\n", m_dqEarPts[0].x, m_dqEarPts[0].y, m_dqEarPts[1].x, m_dqEarPts[1].y);
		}
		if(m_dqAbdoPts.size()>=2) {
			fprintf(fp, "A%d %d %d %d\n", m_dqAbdoPts[0].x, m_dqAbdoPts[0].y, m_dqAbdoPts[1].x, m_dqAbdoPts[1].y );
			myMsgOutput("Abdomen [%d, %d], [%d, %d]\n",m_dqAbdoPts[0].x, m_dqAbdoPts[0].y, m_dqAbdoPts[1].x, m_dqAbdoPts[1].y );
		}
		if(m_nCageLine >0)
			fprintf(fp, "C%d\n", m_nCageLine );
		fclose(fp);
	}

    if(m_bHasCrop ==false) {
        if(m_Rat.detectLED(m_nCageLine)==false) {
            wxString str;
            str.Printf("detectLED error, LED1 %d, LED2 %d, LED end %d", m_Rat.m_nLED1, m_Rat.m_nLED2, m_Rat.m_nLED_End);
            wxLogMessage(str);
            //return false;
        }
    }
	if(!m_bHasCrop ) {
		m_Rat.cropImage(m_bCutTop);
		updateOutData(m_Rat.getSrcImg(0));	
		m_bHasCrop = true;
	}
	
//	myMsgOutput("After preprocessing, %d frames are used, cage size w%d, h%d\n",
//		m_nSlices, m_Rat.m_szImg.width, m_Rat.m_szImg.height );	
	
	return true;
}
void MainFrame::OnRatProcessEar(wxCommandEvent& event)
{
	if(m_dqEyePts.size()!=2) {
		wxMessageBox("Select eye points", "error");
		return;
	}
	if(m_dqEarPts.size()!=2) {
		wxMessageBox("Select ear points", "error");
		return;
	}
	if(m_dqAbdoPts.size()!=2) {
		wxMessageBox("Select abdomen points", "error");
		return;
	}	
	m_ptEyeL = m_dqEyePts[0];
	m_ptEyeR = m_dqEyePts[1];
	m_ptEarL = m_dqEarPts[0];
	m_ptEarR = m_dqEarPts[1];
	m_ptAbdoRed = m_dqAbdoPts[0];
	m_ptAbdoCyan = m_dqAbdoPts[1];
	
	recognizeLeftRight(m_ptEyeL, m_ptEyeR, m_ptEarL, m_ptEarR);	
	
	if(preprocessing()==false)  {
		//wxLogMessage("preprocessing error");
		return;
	}
	if(m_bCutTop) {
 		m_ptEyeL.y -= m_nCageLine;
		m_ptEyeR.y -= m_nCageLine;
		m_ptEarL.y -= m_nCageLine;
		m_ptEarR.y -= m_nCageLine;	 
        m_ptAbdoRed.y -= m_nCageLine;
		m_ptAbdoCyan.y -= m_nCageLine;	      
    }
	//bool bRet = m_Rat.processEar(m_ptEyeL, m_ptEyeR, m_ptEarL, m_ptEarR);
	bool bRet = m_Rat.process(m_ptEyeL, m_ptEyeR, m_ptEarL, m_ptEarR, m_ptAbdoRed, m_ptAbdoCyan);
	if(bRet ==false) return;
	
	updateOutData(m_Rat.getResultImg(0));
	wxBell();	
}

void MainFrame::OnRatAbdomen(wxCommandEvent& event)
{
	if(m_dqAbdoPts.size()!=2) {
		wxMessageBox("Select abdomen points", "error");
		return;
	}	
   
	m_ptAbdoRed = m_dqAbdoPts[0];
	m_ptAbdoCyan = m_dqAbdoPts[1];

	
	if(m_dqEyePts.size()>0 && m_dqEarPts.size()>0) {          
		m_ptEyeL = m_dqEyePts[0];
		m_ptEyeR = m_dqEyePts[1];
		m_ptEarL = m_dqEarPts[0];
		m_ptEarR = m_dqEarPts[1];
		recognizeLeftRight(m_ptEyeL, m_ptEyeR, m_ptEarL, m_ptEarR);
	}
		
	if(preprocessing()==false)  {
		//wxLogMessage("preprocessing error");
		return;
	}
	if(m_bCutTop) {
        m_ptAbdoRed.y -= m_nCageLine;
		m_ptAbdoCyan.y -= m_nCageLine;	
	    if(m_dqEyePts.size()>0 && m_dqEarPts.size()>0) {
   			m_ptEyeL.y -= m_nCageLine;
			m_ptEyeR.y -= m_nCageLine;
			m_ptEarL.y -= m_nCageLine;
			m_ptEarR.y -= m_nCageLine;	
		}
    }
    
//	bool bRet = m_Rat.processAbdomen(m_ptAbdoRed, m_ptAbdoCyan);
//	if(bRet ==false) return;
	
//	updateOutData(m_Rat.getResultImg(0));

	wxBell();		
}


void MainFrame::OnRatShowResults(wxCommandEvent& event)
{
/*
	if (m_Rat.m_vecLEarGrayDiff0.empty()) {
		wxMessageBox("no data", "Error");
		return;
	}
	
	Gnuplot gnuPlot("lines");
	wxFileName fileName = m_strSourcePath;
	_gnuplotLED(gnuPlot, fileName.GetName(), m_Rat.m_idxLightBegin, m_Rat.m_idxTwoLight);
	_gnuplotLine(gnuPlot, "Left Ear", m_Rat.m_vecLEarGrayDiff0);
	//m_Rat.m_vecLEarGrayDiff, m_Rat.m_vecREarGrayDiff, m_Rat.m_vecLEyeGrayDiff);
	 */ 
}
void MainFrame::OnRatLoadResult(wxCommandEvent& event)
{
	wxString wildcard  = "csv files (*.csv)|*.csv";
	wxString filename = wxFileSelector("Choose a file to open",wxEmptyString, wxEmptyString, wxEmptyString, wildcard, wxFD_FILE_MUST_EXIST|wxFD_OPEN);
	if ( filename.empty() )  return;
	

	int nBeginLight, nTwoLight, numRec;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return;
	int r = fscanf(fp, "%d, %d, %d", &numRec, &nBeginLight, &nTwoLight);
	if (r != 3) {
		fclose(fp);		
		wxMessageBox("read lantern info error", "Error");
		return;
	}

	int num = 0;
	float a, b, c;
	while (!feof(fp)) {
		int r = fscanf(fp, "%f, %f, %f", &a, &b, &c);
		if (r != 3) break;
		num++;
	}

	myMsgOutput("read %d records\n", num);
	if (num != numRec)  {
		fclose(fp);
		wxMessageBox("read motion data error", "Error");
		return;
	}

	vector <float> earLM, earRM, eye;

	rewind(fp);
	fscanf(fp, "%d, %d, %d", &numRec, &nBeginLight, &nTwoLight);
	num = 0;
	for (int i = 0; i<numRec; i++) {
		int r = fscanf(fp, "%f, %f, %f", &a, &b, &c);
		if (r != 3) break;
		earLM.push_back(a);
		earRM.push_back(b);
		eye.push_back(c);
		num++;
	}
	fclose(fp);
	if (num != numRec)  {
		fclose(fp);
		wxMessageBox("read motion data error", "Error");
		return;
	}

	Gnuplot gnuPlot("lines");
	wxFileName fileName = filename;	
	_gnuplotInit(gnuPlot, fileName.GetName());
	_gnuplotLED(gnuPlot,  nBeginLight, nTwoLight);
	_gnuplotLine(gnuPlot, "Left Ear", earLM);
	_gnuplotLine(gnuPlot, "Right Ear", earRM);
}


void VolumeSlice(int pos, void *param)
{
	MainFrame *pMainFrame = (MainFrame*)param;
	Mat &mSrc = pMainFrame->getCurrentMat(pos);	
	Mat mShow ;
	cvtColor(mSrc, mShow, CV_GRAY2BGR);
	
	Point 	ptEyeL, ptEyeR, ptEarL, ptEarR;
	Point 	ptAbdoBo, ptAbdoIn;
	
	pMainFrame->getEyePts(ptEyeL, ptEyeR);
	if(ptEyeL.x > 0) {
		circle(mShow, Point(ptEyeL.x, ptEyeL.y), 3, Scalar(0, 0, 255), -1);
		circle(mShow, Point(ptEyeR.x, ptEyeR.y), 3, Scalar(0, 0, 255), -1);
	}
	
	pMainFrame->getEarPts(ptEarL, ptEarR);
	if(ptEarL.x > 0) {
		circle(mShow, Point(ptEarL.x, ptEarL.y), 3, Scalar(0, 255, 0), -1);
		circle(mShow, Point(ptEarR.x, ptEarR.y), 3, Scalar(0, 255, 0), -1);
	}		
	cv::imshow("OriginalData", mShow);
}
void onCVMouse(int event, int x, int y, int flags, void* param)
{
	MainFrame *pMainFrame = (MainFrame*)param;

	if (event == CV_EVENT_RBUTTONDOWN) {
		int pos = cv::getTrackbarPos("slice", "OriginalData");
		Mat &mSrc = pMainFrame->getCurrentMat(pos);
		pMainFrame->updateOutData(mSrc);
		
		MainFrame::myMsgOutput("extract slice [0-%d]: %d\n", pMainFrame->getNumSlices()-1, pos);
	}
}
void MainFrame::OnViewSeries(wxCommandEvent& event)
{
	if(m_nSlices <=0) {
		wxLogMessage("no data\n");
		return;
	}

	cv::namedWindow("OriginalData");
	Mat &mSrc = getCurrentMat(0);
	cv::imshow("OriginalData", mSrc);
	int pos = 0;

	cv::createTrackbar("slice", "OriginalData", &pos, m_nSlices-1, VolumeSlice, this);
	cv::setMouseCallback("OriginalData", onCVMouse, this);
	
}
void MainFrame::OnUpdateViewSeries(wxUpdateUIEvent& event)
{
	event.Enable(m_nSlices >0);
}

void ResultSlice(int pos, void *param)
{
	MainFrame *pMainFrame = (MainFrame*)param;
	Mat &mSrc = pMainFrame->getResultMat(pos);	
		
	cv::imshow("ResultSeries", mSrc);
}

void MainFrame::OnViewResultSeries(wxCommandEvent& event)
{
	if(m_nSlices <=0) {
		wxLogMessage("no data\n");
		return;
	}

	cv::namedWindow("ResultSeries");
	Mat &mSrc = getResultMat(0);
	cv::imshow("ResultSeries", mSrc);
	int pos = 0;
	cv::createTrackbar("slice", "ResultSeries", &pos, m_nSlices-1, ResultSlice, this);
	//cv::setMouseCallback("ResultSeries", onCVMouse, this);
    
    cv::namedWindow("xxx");
	for(int i=0; i<m_nSlices; i++)	{
        Mat &mSrc = getResultMat(i);
        cv::imshow("xxx", mSrc);  
        waitKey(16);     
    }
	wxBell(); 
}


void FolderImageSlice(int pos, void *param)
{
	Mat &mSrc = gvecMat[pos];	
	cv::imshow("ImageSeries", mSrc);
}
void MainFrame::OnViewFolderImage(wxCommandEvent& event)
{
	wxString  strHistoryFile = wxEmptyString;
	if(m_FileHistory->GetCount() >0) 
		strHistoryFile= m_FileHistory->GetHistoryFile(0);
	
	static wxString strInitDir (strHistoryFile);
	wxString dirName = wxDirSelector("Choose a folder", strInitDir); //"E:\\Image_Data\\Mouse\\");
	if(dirName.empty())  return;

	myMsgOutput( "Load " + dirName + "\n");

	wxString fileSpec = _T("*.*");
	wxArrayString  	files;
	wxDir::GetAllFiles(dirName, &files,  fileSpec, wxDIR_FILES  );
	
	gvecMat.clear();
	for(unsigned int i=0; i<files.size(); i++ ) {
		wxFileName fileName = files[i];
		wxString  fName = fileName.GetName();
		wxString  fExtName = fileName.GetExt();
		if(!fExtName.IsSameAs("bmp", false) && !fExtName.IsSameAs("png", false))  continue;
		char secondChar = fName[1];
		if(secondChar !='_') continue;	
		
		//MainFrame::myMsgOutput(files[i]+ "\n");
		std::string strStd = files[i].ToStdString();
		cv::Mat	cvMat = cv::imread(strStd, CV_LOAD_IMAGE_UNCHANGED);
		//gpOutput->ShowMessage("%s", castr);
		if(cvMat.data == NULL) {
			wxString str;
			str.Printf("read file %s ERROR\n", strStd);
			myMsgOutput(str);
			break;
		}
		try	{
			gvecMat.push_back(cvMat);		
		}catch(std::exception &e){
			wxString str;
			str.Printf("Bad allocation: %s", e.what() );
			wxLogMessage( str);
		}
	}
	int nSlices = gvecMat.size();

	if(nSlices <=0) {
		wxLogMessage("no data\n");
		return;
	}

	cv::namedWindow("ImageSeries");
	Mat &mSrc = gvecMat[0];
	int pos = 0;
	cv::imshow("ImageSeries", mSrc);	
	cv::createTrackbar("slice", "ImageSeries", &pos, nSlices-1, FolderImageSlice, this);
	
}

void MainFrame::OnView2DData(wxCommandEvent& event)
{
	wxFileDialog openFileDialog(this, _("Open csv file"), "", "",
					"csv files (*.csv)|*.csv", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return; // the user changed idea...
	// proceed loading the file chosen by the user;
	// this can be done with e.g. wxWidgets input streams:
	wxString fname = openFileDialog.GetPath();	
	
	std::ostringstream cmdstr;
	cmdstr << "plot '" << fname.ToAscii() << "' " << "with dots";
	Gnuplot gPlot2D("dots");
	gPlot2D.set_grid();
    gPlot2D.cmd(cmdstr.str());
	wxMessageBox("Hit Enter to continue", "continue...");
}
void MainFrame::OnView3DData(wxCommandEvent& event)
{
	wxFileDialog openFileDialog(this, _("Open csv file"), "", "",
					"csv files (*.csv)|*.csv", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return; // the user changed idea...
	// proceed loading the file chosen by the user;
	// this can be done with e.g. wxWidgets input streams:
	wxString fname = openFileDialog.GetPath();	
	
	std::ostringstream cmdstr;
	cmdstr << "splot '" << fname.ToAscii() << "' " << "matrix using 1:2:3 with lines";
	
	Gnuplot gPlot3D("lines");
    gPlot3D.cmd(cmdstr.str());	
	wxMessageBox("Hit Enter to continue", "continue...");
}
void MainFrame::OnMouseLButtonDown(wxMouseEvent& event)
{
	if(m_bMarkEye==false && m_bMarkEar == false && m_bMarkAbdomen == false && m_bMarkCageline == false)  return;
	if (getNumSlices() <= 0)  return;
	
	wxClientDC *pDC = new wxClientDC(this);
	wxPoint pt1 = event.GetLogicalPosition(*pDC);
	wxPoint pt;
	m_scrollWin->CalcUnscrolledPosition(pt1.x, pt1.y, &pt.x, &pt.y);
	
	Mat mat = getCurrentMat(0);
//	int imgH = m_szOriSize.height;
	
	if (pt.x >= mat.cols || pt.y >= mat.rows)
		return;
        
	if(m_bCutTop) {
		pt.y += m_nCageLine;
	}
    
	if(m_bMarkEye) {
		Point ptEye = Point(pt.x, pt.y);
		m_dqEyePts.push_back(ptEye);
		int sz = m_dqEyePts.size();
        if(sz>2) 	{
            m_dqEyePts.pop_front();	
            sz--;
        }
        for(int i=0; i<sz; i++) {
            if(i==0)	{
                m_ptEyeL = m_dqEyePts[0];
                if(m_bCutTop)  m_ptEyeL.y -= m_nCageLine;
            }
            if(i==1)	{
                m_ptEyeR = m_dqEyePts[1];	
                if(m_bCutTop)  m_ptEyeR.y -= m_nCageLine;		
            }
		}
	}else if(m_bMarkEar) {
		Point ptEar = Point(pt.x, pt.y);
		m_dqEarPts.push_back(ptEar);
		int sz = m_dqEarPts.size();
        if(sz>2) 	{
            m_dqEarPts.pop_front();	
            sz--;
        }
        for(int i=0; i<sz; i++) {
            if(i==0){
                m_ptEarL = m_dqEarPts[0];
                if(m_bCutTop)  m_ptEarL.y -= m_nCageLine;
            }
            if(i==1) {
                m_ptEarR = m_dqEarPts[1];	
                if(m_bCutTop)  m_ptEarR.y -= m_nCageLine;
            }
		}	
	}else if(m_bMarkAbdomen) {
		Point ptEar = Point(pt.x, pt.y);
		m_dqAbdoPts.push_back(ptEar);
		int sz = m_dqAbdoPts.size();
        if(sz>2)  {	
            m_dqAbdoPts.pop_front();
            sz--;
        }
        for(int i=0; i<sz; i++) {
            if(i==0)	{
                m_ptAbdoRed = m_dqAbdoPts[0];
                if(m_bCutTop)  m_ptAbdoRed.y -= m_nCageLine;
            }
            if(i==1)	{
                m_ptAbdoCyan = m_dqAbdoPts[1];
                if(m_bCutTop)  m_ptAbdoCyan.y -= m_nCageLine;
            }
        }
	}else if(m_bMarkCageline) {
		m_nCageLine = pt.y;
		myMsgOutput("cage line %d\n", m_nCageLine);
	}
	
	Refresh();    
}
void MainFrame::OnMouseRButtonDown(wxMouseEvent& event)
{
}
