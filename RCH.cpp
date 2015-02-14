// RCH.cpp : implementation file
//
/*
***************************************************
模块名       ：CRCH
文件名       ：CRCH
相关文件     ：backups.txt Reader.txt
文件实现功能 ：修改读者信息
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/3   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "RCH.h"
#include "Reader.h"
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
// CRCH dialog


CRCH::CRCH(CWnd* pParent /*=NULL*/)
	: CDialog(CRCH::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRCH)
	m_nname = _T("");
	m_ncode = _T("");
	//}}AFX_DATA_INIT
}


void CRCH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRCH)
	DDX_Text(pDX, IDC_EDIT1, m_nname);
	DDX_Text(pDX, IDC_EDIT2, m_ncode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRCH, CDialog)
	//{{AFX_MSG_MAP(CRCH)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRCH message handlers
/*
***************************************************
<PRE>
函数名 ：CRCH::OnOK
功能   ：修改读者信息
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
void CRCH::OnOK() 
{
	// TODO: Add extra validation here
    UpdateData(TRUE);
	string name,code;
	string bname1,wname1,bid1,bkind1,bflag1,reader;/////////////////borrowook.txt里的变量
	int bnum1;
	//CString flag;
	int find=0;
	//flag="201201";/////////////////////////////////////////////////////////////////需要修改
    //GetDlgItem(IDC_RUSER)->GetWindowText(flag);//////////////////////////////////
	if(m_nname==""||m_ncode=="")
	{
	   AfxMessageBox("信息不完整!");
	   return;
	}
	ifstream r("Reader.txt");
	ifstream bb("borrowbook.txt");
	ofstream backup("backups.txt");//////////////////////读者文件备份
	ofstream backup1("backups1.txt");////////////////////借书文件备份
	while(r>>name>>code)/////////////////////////////////修改读者文件的内容
	{
		if(name==m_nname.GetBuffer(0))
			find=1;		
		if(name==flag.GetBuffer(0))
		{
			backup<<m_nname.GetBuffer(0)<<" "<<m_ncode.GetBuffer(0)<<endl;
		}else{
			backup<<name<<" "<<code<<endl;
		}
	}
	if(find)
	{
		AfxMessageBox("用户名重复!");
	   return;
	}
	while(bb>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1)
	{
		if(reader==flag.GetBuffer(0))
		{
			backup1<<m_nname.GetBuffer(0)<<" "<<bname1<<" "<<wname1<<" "<<bnum1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
		}
		else
		{
			backup1<<reader<<" "<<bname1<<" "<<wname1<<" "<<bnum1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
		}
	}
	flag=m_nname;////////////////////////////////需改变读者标志
	r.close();
	backup.close();
	bb.close();
	backup1.close();
	ofstream R("Reader.txt");
	ifstream ba("backups.txt");
	ofstream lend("borrowbook.txt");
	ifstream ba1("backups1.txt");
	while(ba>>name>>code)
	{
		R<<name<<" "<<code<<endl;
	}
	while(ba1>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1)
	{
		lend<<reader<<" "<<bname1<<" "<<wname1<<" "<<bnum1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
	}
    AfxMessageBox("修改完成!");
    R.close();
	ba.close();
    lend.close();
	ba1.close();
    ofstream clear("backups.txt",ios::trunc);
    clear.close();
   // ofstream clear1("backups1.txt",ios::trunc);
   // clear1.close();
	CDialog::OnOK();
}
