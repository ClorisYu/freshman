// Mreader.cpp : implementation file
//
/*
***************************************************
模块名       ：CMreader
文件名       ：CMreader
相关文件     ：无
文件实现功能 ：弹出窗口
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/29  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Mreader.h"
#include "Radd.h"
#include "RDelete.h"
#include "Rfor.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMreader dialog


CMreader::CMreader(CWnd* pParent /*=NULL*/)
	: CDialog(CMreader::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMreader)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMreader::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMreader) 
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMreader, CDialog)
	//{{AFX_MSG_MAP(CMreader)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_FOR, OnFor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMreader message handlers

void CMreader::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CRadd Ra;
	Ra.DoModal();
	
}

void CMreader::OnDelete() 
{
	// TODO: Add your control notification handler code here
    CRDelete rd;
	rd.DoModal();	
}

void CMreader::OnFor() 
{
	// TODO: Add your control notification handler code here
	CRfor rf;
	rf.DoModal();	
}
