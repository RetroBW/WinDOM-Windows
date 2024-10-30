// name.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Name dialog

class Name : public CDialog
{
// Construction
public:
	Name(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(Name)
	enum { IDD = IDD_DIALOG_NAME };
	CString	m_Name;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(Name)
	virtual void OnCancel();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	virtual HBRUSH OnCtlColor   (CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL   OnNcActivate (BOOL);
	virtual void   OnNcPaint ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
