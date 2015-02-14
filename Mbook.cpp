// Mbook.cpp : implementation file
//
/*
***************************************************
模块名       ：CMbook
文件名       ：CMbook
相关文件     ：无
文件实现功能 ：弹出窗口
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/27  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Mbook.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Lend.h"
#include "BFIND.h"
#include "Badd.h"
#include "Bdelete.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMbook dialog
//int bnum;
//CString m_bname,m_wname;
//CString m_Mnum,m_Mcode,m_Rnum,m_Rcode;
CMbook::CMbook(CWnd* pParent /*=NULL*/)
	: CDialog(CMbook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMbook)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMbook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMbook)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMbook, CDialog)
	//{{AFX_MSG_MAP(CMbook)
	ON_BN_CLICKED(IDC_BFIND, OnBfind)
	ON_BN_CLICKED(IDC_BADD, OnBadd)
	ON_BN_CLICKED(IDC_BDELETE, OnBdelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMbook message handlers

 

void CMbook::OnBfind() 
{
	// TODO: Add your control notification handler code here
   CBFIND  bf;
   bf.DoModal();	
}





void CMbook::OnBadd() 
{
	// TODO: Add your control notification handler code here
	CBadd ba;
	ba.DoModal();
	
}

void CMbook::OnBdelete() 
{
	// TODO: Add your control notification handler code here
	CBdelete bd;
	bd.DoModal();
}
