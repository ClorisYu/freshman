// Chcode.cpp : implementation file
//
/*
***************************************************
模块名       ：CChcode
文件名       ：CChcode
相关文件     ：Manager.txt
文件实现功能 ：修改管理员信息
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
#include "Chcode.h"
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChcode dialog


CChcode::CChcode(CWnd* pParent /*=NULL*/)
	: CDialog(CChcode::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChcode)
	m_ncode = _T("");
	m_nname = _T("");
	//}}AFX_DATA_INIT
}


void CChcode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChcode)
	DDX_Text(pDX, IDC_NCODE, m_ncode);
	DDX_Text(pDX, IDC_NNEW, m_nname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChcode, CDialog)
	//{{AFX_MSG_MAP(CChcode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChcode message handlers
/*
***************************************************
<PRE>
函数名 ：CChcode::OnOK
功能   ：修改管理员信息
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
作者   ：喻超蓉
<PRE>
***************************************************
*/
void CChcode::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
  
    if(m_ncode==""||m_nname=="")
	{
	   AfxMessageBox("信息不完整!");
	   return;
	}
	ofstream m("Manager.txt");
	m<<m_nname.GetBuffer(0)<<" "<<m_ncode.GetBuffer(0)<<endl;
    AfxMessageBox("修改完成");
	CDialog::OnOK();
}
