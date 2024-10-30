// name.cpp : implementation file
//

#include "stdafx.h"
#include "windom.h"

#include "ctl3d.h"
#include "name.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Name dialog


Name::Name(CWnd* pParent /*=NULL*/)
	: CDialog(Name::IDD, pParent)
{
	//{{AFX_DATA_INIT(Name)
	m_Name = "";
	//}}AFX_DATA_INIT
}

void Name::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Name)
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDV_MaxChars(pDX, m_Name, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(Name, CDialog)
	//{{AFX_MSG_MAP(Name)
	ON_WM_SHOWWINDOW()
	ON_WM_CTLCOLOR()
	ON_WM_NCACTIVATE()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Name message handlers

void Name::OnCancel()
{
	//clear name if canceled
	m_Name = "\0";
		
	CDialog::OnCancel();
}

void Name::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	//set focus to edit box allowing the user to enter their name
	GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME));
}

BOOL Name::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Ctl3dSubclassDlg(m_hWnd, CTL3D_ALL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

HBRUSH Name::OnCtlColor (CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
MSG* pMsg = (MSG *) GetCurrentMessage();

CDialog::OnCtlColor (pDC, pWnd, nCtlColor);
return (HBRUSH) Ctl3dCtlColorEx (pMsg->message, pMsg->wParam, pMsg->lParam);
}

BOOL Name::OnNcActivate( BOOL )
{
 MSG* pMsg = ( MSG* ) GetCurrentMessage();
 return ( BOOL ) Ctl3dDlgFramePaint( pMsg->hwnd, pMsg->message,
                 pMsg->wParam, pMsg->lParam );
}

void Name::OnNcPaint()
{
 MSG* pMsg = ( MSG* ) GetCurrentMessage();
 Ctl3dDlgFramePaint( pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam );
}
