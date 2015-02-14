// Manager.cpp : implementation file
//
/*
***************************************************
模块名       ：CManager
文件名       ：CManager
相关文件     ：Manager.txt
文件实现功能 ：管理员登陆
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/20  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Manager.h"
#include "Mdo.h"
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
// CManager dialog


CManager::CManager(CWnd* pParent /*=NULL*/)
	: CDialog(CManager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManager)
	m_Mnum = _T("");
	m_Mcode = _T("");
	//}}AFX_DATA_INIT
}


void CManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManager)
	DDX_Text(pDX, IDC_EDIT1, m_Mnum);
	DDX_Text(pDX, IDC_EDIT2, m_Mcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManager, CDialog)
	//{{AFX_MSG_MAP(CManager)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManager message handlers
/*
***************************************************
<PRE>
函数名 ：CManager::OnOK
功能   ：管理员登陆
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
void CManager::OnOK() 
{
		UpdateData(TRUE);
			string m_Mn,m_Mc;

	if(m_Mnum=="")//////////////////////////////////判断输入信息是否完整
	{
		MessageBox("您未输入账号!","登录结果");
		return;
	}
    if(m_Mcode=="")
	{
		MessageBox("您未输入密码!","登录结果");
		return;
	}
		ifstream m("Manager.txt");
	if (m.fail())
	{
		AfxMessageBox("Error!");
	}
	// TODO: Add extra validation here
	int find=0;///////////////////////////////////////////是否存在该用户
	while(!m.eof())
	{
		m>>m_Mn>>m_Mc;
        CString n,c;
		n=m_Mn.c_str();
		c=m_Mc.c_str();
		if(m_Mnum==n && m_Mcode!=c)
		{
			AfxMessageBox("密码错误!");
		    return;
		}
        if(m_Mnum!=n&& m_Mcode==c)
		{
			AfxMessageBox("用户不存在!");
		    return;
		}
		if(m_Mnum==n && m_Mcode==c)
		{
			m.close();
			find=1;
			CDialog::OnOK();
			CMdo mdo;
			mdo.DoModal();
		}
	}
	if(find==0)//////////////////////////////////////////////不存在，则弹出提示信息
	{
		AfxMessageBox("账号和密码都错误!");
		return;
	}
	
}
