// scoresdl.cpp : implementation file
//

#include "stdafx.h"
#include "windom.h"

#include "ctl3d.h"
#include "scoresdl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ScoresDlg dialog


ScoresDlg::ScoresDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ScoresDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ScoresDlg)
	m_Name10 = "";
	m_Name2 = "";
	m_Name3 = "";
	m_Name4 = "";
	m_Name5 = "";
	m_Name6 = "";
	m_Name7 = "";
	m_Name8 = "";
	m_Name9 = "";
	m_Score1 = 0;
	m_Score10 = 0;
	m_Score2 = 0;
	m_Score3 = 0;
	m_Score4 = 0;
	m_Score5 = 0;
	m_Score6 = 0;
	m_Score7 = 0;
	m_Score8 = 0;
	m_Score9 = 0;
	m_Name1 = "";
	//}}AFX_DATA_INIT
}

void ScoresDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ScoresDlg)
	DDX_Text(pDX, IDC_EDIT_NAME10, m_Name10);
	DDV_MaxChars(pDX, m_Name10, 10);
	DDX_Text(pDX, IDC_EDIT_NAME2, m_Name2);
	DDV_MaxChars(pDX, m_Name2, 10);
	DDX_Text(pDX, IDC_EDIT_NAME3, m_Name3);
	DDV_MaxChars(pDX, m_Name3, 10);
	DDX_Text(pDX, IDC_EDIT_NAME4, m_Name4);
	DDV_MaxChars(pDX, m_Name4, 10);
	DDX_Text(pDX, IDC_EDIT_NAME5, m_Name5);
	DDV_MaxChars(pDX, m_Name5, 10);
	DDX_Text(pDX, IDC_EDIT_NAME6, m_Name6);
	DDV_MaxChars(pDX, m_Name6, 10);
	DDX_Text(pDX, IDC_EDIT_NAME7, m_Name7);
	DDV_MaxChars(pDX, m_Name7, 10);
	DDX_Text(pDX, IDC_EDIT_NAME8, m_Name8);
	DDV_MaxChars(pDX, m_Name8, 10);
	DDX_Text(pDX, IDC_EDIT_NAME9, m_Name9);
	DDV_MaxChars(pDX, m_Name9, 10);
	DDX_Text(pDX, IDC_EDIT_SCORE1, m_Score1);
	DDX_Text(pDX, IDC_EDIT_SCORE10, m_Score10);
	DDX_Text(pDX, IDC_EDIT_SCORE2, m_Score2);
	DDX_Text(pDX, IDC_EDIT_SCORE3, m_Score3);
	DDX_Text(pDX, IDC_EDIT_SCORE4, m_Score4);
	DDX_Text(pDX, IDC_EDIT_SCORE5, m_Score5);
	DDX_Text(pDX, IDC_EDIT_SCORE6, m_Score6);
	DDX_Text(pDX, IDC_EDIT_SCORE7, m_Score7);
	DDX_Text(pDX, IDC_EDIT_SCORE8, m_Score8);
	DDX_Text(pDX, IDC_EDIT_SCORE9, m_Score9);
	DDX_Text(pDX, IDC_EDIT_NAME1, m_Name1);
	DDV_MaxChars(pDX, m_Name1, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(ScoresDlg, CDialog)
	//{{AFX_MSG_MAP(ScoresDlg)
	ON_WM_CTLCOLOR()
	ON_WM_NCACTIVATE()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ScoresDlg message handlers

BOOL ScoresDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Ctl3dSubclassDlg(m_hWnd, CTL3D_ALL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

HBRUSH ScoresDlg::OnCtlColor (CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
MSG* pMsg = (MSG *) GetCurrentMessage();

CDialog::OnCtlColor (pDC, pWnd, nCtlColor);
return (HBRUSH) Ctl3dCtlColorEx (pMsg->message, pMsg->wParam, pMsg->lParam);
}

BOOL ScoresDlg::OnNcActivate( BOOL )
{
 MSG* pMsg = ( MSG* ) GetCurrentMessage();
 return ( BOOL ) Ctl3dDlgFramePaint( pMsg->hwnd, pMsg->message,
                 pMsg->wParam, pMsg->lParam );
}

void ScoresDlg::OnNcPaint()
{
 MSG* pMsg = ( MSG* ) GetCurrentMessage();
 Ctl3dDlgFramePaint( pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam );
}
