// mainfrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "windom.h"
#include "ctl3d.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SYSCOLORCHANGE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if(!CFrameWnd::PreCreateWindow(cs))
   		return FALSE;
   	
	cs.style = WS_OVERLAPPED | WS_CAPTION |WS_SYSMENU | WS_MINIMIZEBOX | 
				  WS_BORDER;
	
	return TRUE;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	int LeftX = (GetSystemMetrics(SM_CXSCREEN) - 640) / 2;
	int TopY = (GetSystemMetrics(SM_CYSCREEN) - 480) / 2;

	SetWindowPos(
		NULL, 			//window z order
		LeftX,          //left position of window
		TopY,			//top position of window
		640, 			//window width
		480,		 	//window height
		0);				//window flags
		
	return 0;
}

void CMainFrame::OnSysColorChange()
{
	CFrameWnd::OnSysColorChange();
	
	// TODO: Add your message handler code here
	Ctl3dColorChange();	
}
