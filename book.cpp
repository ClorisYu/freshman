// book.cpp : implementation file
//

#include "stdafx.h"
#include "图书管理系统.h"
#include "book.h"
#include <string>

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cbook

IMPLEMENT_DYNCREATE(Cbook, CDocument)

Cbook::Cbook()
{
	string bname;
	string wname;
	int num;
	string bID;
	int kind;
	string flag="可借";
}

BOOL Cbook::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

Cbook::~Cbook()
{
}


BEGIN_MESSAGE_MAP(Cbook, CDocument)
	//{{AFX_MSG_MAP(Cbook)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cbook diagnostics

#ifdef _DEBUG
void Cbook::AssertValid() const
{
	CDocument::AssertValid();
}

void Cbook::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Cbook serialization

void Cbook::Serialize(CArchive& ar)
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
// Cbook commands
