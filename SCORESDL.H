// scoresdl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ScoresDlg dialog

class ScoresDlg : public CDialog
{
// Construction
public:
	ScoresDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(ScoresDlg)
	enum { IDD = IDD_SCORES };
	CString	m_Name10;
	CString	m_Name2;
	CString	m_Name3;
	CString	m_Name4;
	CString	m_Name5;
	CString	m_Name6;
	CString	m_Name7;
	CString	m_Name8;
	CString	m_Name9;
	int		m_Score1;
	int		m_Score10;
	int		m_Score2;
	int		m_Score3;
	int		m_Score4;
	int		m_Score5;
	int		m_Score6;
	int		m_Score7;
	int		m_Score8;
	int		m_Score9;
	CString	m_Name1;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(ScoresDlg)
	virtual BOOL OnInitDialog();
	virtual HBRUSH OnCtlColor   (CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL   OnNcActivate (BOOL);
	virtual void   OnNcPaint ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
