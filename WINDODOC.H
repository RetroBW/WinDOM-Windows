// windodoc.h : interface of the CWindomDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CWindomDoc : public CDocument
{
protected: // create from serialization only
	CWindomDoc();
	DECLARE_DYNCREATE(CWindomDoc)

// Attributes
public:
// Operations
public:

// Implementation
public:
	virtual ~CWindomDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CWindomDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
