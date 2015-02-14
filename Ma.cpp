// CMdo.cpp : implementation file
//

#include "stdafx.h"
#include "图书管理系统.h"
#include "Mdo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdo dialog


CMdo::CMdo(CWnd* pParent /*=NULL*/)
	: CDialog(CMdo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMdo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_CMdoP(CMdo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_CMdoP
}


BEGIN_MESSAGE_CMdoP(CMdo, CDialog)
	//{{AFX_MSG_CMdoP(CMdo)
		// NOTE: the ClassWizard will add message CMdop CMdocros here
	//}}AFX_MSG_CMdoP
END_MESSAGE_CMdoP()

/////////////////////////////////////////////////////////////////////////////
// CMdo message handlers
