// Radd.cpp : implementation file
//
/*
***************************************************
模块名       ：CRadd
文件名       ：CRadd
相关文件     ：Reader.txt
文件实现功能 ：添加读者信息
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/2   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Radd.h"
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
// CRadd dialog


CRadd::CRadd(CWnd* pParent /*=NULL*/)
	: CDialog(CRadd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRadd)
	m_Reader = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CRadd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRadd)
	DDX_Text(pDX, IDC_EDIT1, m_Reader);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRadd, CDialog)
	//{{AFX_MSG_MAP(CRadd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadd message handlers
/*
***************************************************
<PRE>
函数名 ：CRadd::OnOK
功能   ：添加读者信息
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
void CRadd::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	string reader,code;
	if(m_Reader==""||m_password=="")
	{
		AfxMessageBox("请输入完整信息!");
		return;
	}
	ifstream R("Reader.txt");
	if(R.fail())
	{
		AfxMessageBox("error");
		return;
	}
	while(R>>reader>>code)
	{ 
		if(reader.c_str()==m_Reader)
		{
			AfxMessageBox("此读者已存在!");
	    	R.close();
			return;
		}		
	}
	ofstream add("Reader.txt",ios::app);
	if(add.fail())
	{
		AfxMessageBox("error");
		return;
	}
	add<<m_Reader.GetBuffer(0)<<" "<<m_password.GetBuffer(0)<<endl;
	AfxMessageBox("添加成功!");

	CDialog::OnOK();
}
