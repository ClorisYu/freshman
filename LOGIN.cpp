// LOGIN.cpp : implementation file
//
/*
***************************************************
模块名       ：CLOGIN
文件名       ：CLOGIN
相关文件     ：无
文件实现功能 ：登陆界面
作者         ：宗震
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改日期     ：
日期       版本       修改人        修改内容
2013/7/7   1.0        宗震           无
***************************************************
*/

#include "stdafx.h"
#include "图书管理系统.h"
#include "LOGIN.h"
#include "Reader.h"
#include "flag.h"
#include "Manager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLOGIN dialog


CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialog(CLOGIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLOGIN)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLOGIN)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialog)
	//{{AFX_MSG_MAP(CLOGIN)
	ON_BN_CLICKED(IDC_RLOGIN, OnRlogin)
	ON_BN_CLICKED(IDC_MLOGIN, OnMlogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLOGIN message handlers
/*
***************************************************
<PRE>
函数名 ：CLOGIN::OnRlogin
功能   ：登陆界面
参数   ：
     [IN|OUT] 参数1: 无
     [IN|OUT] 参数2：无
返回值 ：无
抛出异常：
        类型1：无
        类型2：无
-----------------------------------------------------------------------------
备注   ：无
典型用法：无
-----------------------------------------------------------------------------
作者   ：宗震
<PRE>
***************************************************
*/

void CLOGIN::OnRlogin() 
{
	// TODO: Add your control notification handler code here
	//CLOGIN::OnOK();
	CReader Reader;
	person=0;////////////////////////记录登录者身份
	Reader.DoModal();

}

void CLOGIN::OnMlogin() 
{
	// TODO: Add your control notification handler code here
	//CLOGIN::OnOK();
	CManager Manager;
	person=1;////////////////////////记录登录者身份：
	Manager.DoModal();
}
