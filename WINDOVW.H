// windovw.h : interface of the CWindomView class
//
/////////////////////////////////////////////////////////////////////////////
#include "Dom.h"
#include "Matrix.h"
#include "Border.h"
#include "name.h"
#include "scoresdl.h"

#include "register.h"

class CWindomView : public CView
{
protected: // create from serialization only
	CWindomView();
	DECLARE_DYNCREATE(CWindomView)

// Attributes
public:
	CWindomDoc* GetDocument();

// Operations
public:
	Dom MyDom;
	Matrix MyMatrix;
	Border MyBorder;
	//CWave MyWave;
	void GameOver();
	UINT DomTimer;
	int 
		PlayGame,
		Speed,
		SoundWait,
		SoundOn,
		PreviewOn;
	DWORD playWAVEFile(LPSTR lpszWAVEFileName);
	
	//dialogs
	Name NameDialog;
	ScoresDlg ScoreDialog;

	void ReadScores();
	void WriteScores();
	void CheckScore();
	void DisplayScores();
	void NameOk();
	
	struct structHiScore {
		CString hi_name;
		int hi_score;
	} HiScore[10], TempScore;
		
// Implementation
public:
	virtual ~CWindomView();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWindomView)
	afx_msg void OnFileNew();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnOptionsSound();
	afx_msg void OnOptionsPreview();
	afx_msg void OnFileScore();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in windovw.cpp
inline CWindomDoc* CWindomView::GetDocument()
   { return (CWindomDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
