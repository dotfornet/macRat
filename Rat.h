#pragma once

#include <vector>
#include <string>
#include <algorithm> 
#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/video/tracking.hpp>

#include <itkImage.h>
#include "itkImportImageFilter.h"
#include "itkRGBPixel.h"
#include "itkMetaImageIO.h"

#define NUM_FEATURE	 6
#define EAR_RECT	40

using namespace std;
using namespace cv;

typedef unsigned char charPixelType;
typedef itk::Image< charPixelType, 2 > charImageType;

typedef float floatPixelType;
typedef itk::Image< floatPixelType, 2 > floatImageType;

typedef Vec<float, NUM_FEATURE+1> TrainPattern;

class CEarCandidate{

public:
	CEarCandidate(void) { bEar = false; }

	void copyContourFrom(vector<cv::Point> con) {
		int szContour = con.size();
		contour.resize(szContour);
		std::copy(con.begin(), con.end(), contour.begin());
	}
	void setcentroid(cv::Point c) { centroid = c; }
	void setDist(float d) { dist = d; }

public:
	vector<cv::Point> contour;
	cv::Point centroid;
	float dist;
	bool  bEar;
	double area;
};

struct TwoPts{
	cv::Point ptL;
	cv::Point ptR;
};

class CRat
{
public:
	CRat();
	~CRat(void);

	void	clearData();
	int		readData(wxString path);
	Size	getImgSize()  { return m_szImg; }
	Mat &   getSrcImg(int idx) { return m_vecMat[idx]; }
	Mat &   getResultImg(int idx) { return m_vecDest[idx]; }

	int		getNumFrames()  { return m_nSlices; }
	void	saveResult(const char *subpath, vector <Mat> &vecDest);
	bool	detectTwoLight();
	Point	aspectRatio(vector<cv::Point> &con, double &ratio, double &angle );
	void	prepareData();
	void	getLightRange(int& from, int& to) { from = m_idxLightBegin; to = m_idxLightEnd; }

	bool	horizontalLine();
	bool	verticalLine();
	
	void	process1(Point& ptEyeL, Point& ptEyeR, Point& ptEarL, Point& ptEarR);
	void	recognizeLeftRight(Point& ptEyeL, Point& ptEyeR, Point& ptEarL, Point& ptEarR);
	void 	findEyeCenter(Point& ptEye0, vector <Point>& vecEye, vector <double>&  vecEyeMove);
	void  	findNewEarCenter(vector <Point>& vecEye, Point ptEar0, vector <Point>& vecEar);
	
	void 	smoothData(vector<double>& inData, vector<double>& outData, int bw=5);
	double 	errorSum(Mat &mDiff, Point ptEarL);
	int		findReferenceFrame(Point& pt);
	int 	findMaxMotionPoint(vector<double>& inData);
	void	graylevelDiff(int refer, Point ptEar, vector <Point>& vecEye, vector <double>& vecEarGrayDiff);
	void 	earDiffByFixedLoc(int refer, Point& ptEarL, Point& ptEarR);
	void 	saveEarROI(int stable, int motion, Point& pt);
	void 	saveEyeTrajectory();

	void	opticalFlow();
	void 	opticalFlowDistribution();
	void 	saveFlowData(Mat& mFlow, Mat& mGaus, Point pt, wxString& strOutName);
	void	drawOptFlowMap(Mat& cflowmap, const Mat& flow, int step, const Scalar& color);
	void	opticalFlowAnalysis(Point ptEar, vector <Point>& vecEye, vector <double>& vecEarFlow, bool bOffset, vector <double>&  vecEyeMove);
	float	findMaxMotion(Mat& mROI, cv::Point& ptDiff);
	float	findAvgMotion(Mat& mFlowROI, cv::Point ptEyeOffset);
	float	findAvgMotion(Mat& mFlowROI);
	
	void 	createGaussianMask(double& sigma, int& ksize, Mat& mKernel);
	
	void	findMouseEyes(int numFrame, Point ptEyeL, Point ptEyeR);
	int 	detectEyes(Mat &mROI, vector<vector<cv::Point> >& vecContour, Point& ptL, Point& ptR, bool bShow = false);
	void	setROIRect(Rect& rectEye, Point pt1, Point pt2);
	void	correctEyePos();
	void	correctEyeDisp();
	void    modifyEyeLocation(Mat& mEye, Point& ptEye1, Point& ptEye2, double area1, double area2);
	void	itkLaplacianOfGaussian(Mat& mSrc, Mat& mDest, double sigma);

	void	locateEarPosition(Point& pt1, Point& pt2);

	void	findMouseEars(int numFrame, Point ptEarL, Point ptEarR);
	int 	detectEars(Mat &mIn, vector<vector<cv::Point> >& vecContour, Point& ptL, Point& ptR, bool bShow = false);
	int		detectOneEars(Mat &mIn, vector<vector<cv::Point> >& vecContour, Point& pt, Point& twoEarCenter, Mat& mEarOut);
	bool	mergeEarRegions(vector<vector<cv::Point> >& vecContour, int idx1, int idx2);
	bool	checkEarRegion(Mat &mROI, vector<vector<cv::Point> >& vecContour, int idx1, int k);

	void	ContourSmooth(vector<cv::Point> & contour, int sigma);
	void	BresLine(int Ax, int Ay, int Bx, int By, vector<cv::Point> & contour);
	double	lineSquareError(vector<cv::Point>& contour, cv::Point& pt);
	void	removeUnlikeBendingPts(vector<int> &vecBendingIdx, vector<float>& curvature, int k);

	Mat		accumulate();
	void 	saveEarImage();
	
public:
	vector <Mat> m_vecMat;
	vector <Mat> m_vecDest;
	
	vector <Mat> m_vecFlow;
	
	
	vector <Point>  m_vecEyeL;
	vector <Point>  m_vecEyeR;
	vector <double>  m_vecEyeLMove;
	vector <double>  m_vecEyeRMove;
	vector <Point>  m_vecEarL;
	vector <Point>  m_vecEarR;
	
	vector <TwoPts>  m_vecEyePair;
	vector <TwoPts>  m_vecEarPair;
	Point	m_offsetEar; //(50, 50);
	Point	m_offsetEye;

	Point 	m_ptEyeL;
	Point	m_ptEyeR;
	Point	m_ptEarL;
	Point	m_ptEarR;

	bool	m_bFirstEyeIsLeft;
	bool	m_bFirstEarIsLeft;
	
	vector <double>  m_vecLEyeGrayDiff;
	vector <double>  m_vecREyeGrayDiff;

	vector <double>  m_vecLEarGrayDiff;
	vector <double>  m_vecREarGrayDiff;
	
	vector <double>  m_vecLEarGrayDiff0;
	vector <double>  m_vecREarGrayDiff0;

	vector <double>  m_vecLEarFlow;
	vector <double>  m_vecREarFlow;
	vector <double>  m_vecLEarFlow_eye;
	vector <double>  m_vecREarFlow_eye;
	
	int		m_nSlices ;
	Size	m_szImg;
	wxString  m_strSrcPath;
	vector <string> m_vFilenames;
	int		m_idxLightBegin;
	int		m_idxLightEnd;
	int		m_idxTwoLight;
	int		m_nCageLineY;
	int		m_nCageLineX;

	int 	m_referFrame;
	
	float	m_mean;
	float	m_stddev;
	int		m_nProcessFrame;
	int		m_classifier;
};

