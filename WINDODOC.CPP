// windodoc.cpp : implementation of the CWindomDoc class
//

#include "stdafx.h"
#include "windom.h"

#include "windodoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindomDoc

IMPLEMENT_DYNCREATE(CWindomDoc, CDocument)

BEGIN_MESSAGE_MAP(CWindomDoc, CDocument)
	//{{AFX_MSG_MAP(CWindomDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindomDoc construction/destruction

CWindomDoc::CWindomDoc()
{
	// TODO: add one-time construction code here
}

CWindomDoc::~CWindomDoc()
{
}

BOOL CWindomDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWindomDoc serialization

void CWindomDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWindomDoc diagnostics

#ifdef _DEBUG
void CWindomDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWindomDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWindomDoc commands
