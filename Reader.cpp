// Reader.cpp : implementation file
//
/*
***************************************************
模块名       ：CReader
文件名       ：CReader
相关文件     ：Reader.txt
文件实现功能 ：读者登陆
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/6   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Reader.h"
#include "Rdo.h"
#include "flag.h"
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
// CReader dialog


CReader::CReader(CWnd* pParent /*=NULL*/)
	: CDialog(CReader::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReader)
	m_Rcode = _T("");
	m_Rnum = _T("");
	//}}AFX_DATA_INIT
}


void CReader::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReader)
	DDX_Text(pDX, IDC_RCODE, m_Rcode);
	DDX_Text(pDX, IDC_RUSER, m_Rnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReader, CDialog)
	//{{AFX_MSG_MAP(CReader)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReader message handlers
/*
***************************************************
<PRE>
函数名 ：CReader::OnOK
功能   ：读者登陆
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
void CReader::OnOK() 
{
		UpdateData(TRUE);
		string m_Rn,m_Rc;

	if(m_Rnum=="")//////////////////////////////////判断输入信息是否完整
	{
		MessageBox("您未输入账号!","登录结果");
		return;
	}
    if(m_Rcode=="")
	{
		MessageBox("您未输入密码!","登录结果");
		return;
	}
	flag=m_Rnum;
		ifstream r("Reader.txt");
	if (r.fail())
	{
		AfxMessageBox("Error!");
	}
	// TODO: Add extra validation here
		int find=0;///////////////////////////////////////////是否存在该用户
	while(!r.eof())
	{
		r>>m_Rn>>m_Rc;
        CString n,c;
		n=m_Rn.c_str();
		c=m_Rc.c_str();
		if(m_Rnum==n && m_Rcode==c)
		{
			r.close();
			find=1;
			CDialog::OnOK();
			CRdo rdo;
			rdo.DoModal();
		}
	}
	if(find==0)//////////////////////////////////////////////不存在，则弹出提示信息
	{
		AfxMessageBox("账号或密码错误!");
		return;
	}

}



