// RDelete.cpp : implementation file
//
/*
***************************************************
模块名       ：CRDelete
文件名       ：CRDelete
相关文件     ：Reader.txt backups.txt
文件实现功能 ：删除读者信息
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/4   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "RDelete.h"
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
// CRDelete dialog


CRDelete::CRDelete(CWnd* pParent /*=NULL*/)
	: CDialog(CRDelete::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRDelete)
	m_Reader = _T("");
	//}}AFX_DATA_INIT
}


void CRDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRDelete)
	DDX_Text(pDX, IDC_EDIT1, m_Reader);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRDelete, CDialog)
	//{{AFX_MSG_MAP(CRDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRDelete message handlers
/*
***************************************************
<PRE>
函数名 ：CRDelete::OnOK
功能   ：删除读者信息
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
void CRDelete::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	string reader,code;
	int find=0;
	if(m_Reader=="")
	{
	   AfxMessageBox("信息不完整!");
	   return;
	}
	ifstream re("Reader.txt");
	ofstream ba("backups.txt");
	while(re>>reader>>code)
	{
		if(m_Reader==reader.c_str())
		{
			find=1;
		}
		else
			ba<<reader<<" "<<code<<endl;
	}
	if(!find)
	{
	   AfxMessageBox("此读者不存在!");
	   return;
	}
	re.close();
	ba.close();
	ofstream r("Reader.txt");
	ifstream b("backups.txt");
	while(b>>reader>>code)
	{
		r<<reader<<" "<<code<<endl;
	}
    r.close();
	b.close();
	AfxMessageBox("此读者已删除!");
	ofstream clear("backups.txt",ios::trunc);
	clear.close(); 
	CDialog::OnOK();
}
