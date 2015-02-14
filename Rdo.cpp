// Rdo.cpp : implementation file
//
/*
***************************************************
模块名       ：CRdo
文件名       ：CRdo
相关文件     ：无
文件实现功能 ：弹出窗口
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/30  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Rdo.h"
#include "RCH.h"
#include "Rfor.h"
#include "flag.h"
#include "BFIND.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdo dialog


CRdo::CRdo(CWnd* pParent /*=NULL*/)
	: CDialog(CRdo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRdo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRdo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRdo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRdo, CDialog)
	//{{AFX_MSG_MAP(CRdo)
	ON_BN_CLICKED(IDC_CHCODE, OnChcode)
	ON_BN_CLICKED(IDC_BLOOK, OnBlook)
	ON_BN_CLICKED(IDC_LBLOOK, OnLblook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRdo message handlers

void CRdo::OnChcode() 
{
	// TODO: Add your control notification handler code here
	CRCH rch;
	rch.DoModal();
	
}

void CRdo::OnBlook() 
{
	// TODO: Add your control notification handler code here
    CBFIND bf;
	bf.DoModal();
	
}

void CRdo::OnLblook() 
{
	// TODO: Add your control notification handler code here
    CRfor rf;
	rf.DoModal();
	
}
