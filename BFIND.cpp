// BFIND.cpp : implementation file
//
/*
***************************************************
模块名       ：CBFIND
文件名       ：CBFIND
相关文件     ：books.txt
文件实现功能 ：查找图书
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/28  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "BFIND.h"
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
// CBFIND dialog


CBFIND::CBFIND(CWnd* pParent /*=NULL*/)
	: CDialog(CBFIND::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBFIND)
	m_Bname = _T("");
	m_Wname = _T("");
	//}}AFX_DATA_INIT
}


void CBFIND::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBFIND)
	DDX_Control(pDX, IDC_LIST2, m_find);
	DDX_Text(pDX, IDC_BNAME, m_Bname);
	DDX_Text(pDX, IDC_WNAME, m_Wname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBFIND, CDialog)
	//{{AFX_MSG_MAP(CBFIND)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBFIND message handlers
/*
***************************************************
<PRE>
函数名 ：CBFIND::OnOK
功能   ：查找图书
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
void CBFIND::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	string bookname,writer,booknum,bookid,bookkind,bookflag;
//	int booknum;
	int find=0;
	ifstream bk("books.txt");
	if(bk.fail())
	{
		AfxMessageBox("error");
	}
	int i=0;
    while(!bk.eof())
	{
		bk>>bookname>>writer>>booknum>>bookid>>bookkind>>bookflag;
		if(bookname.c_str()==m_Bname&&writer.c_str()==m_Wname)
		{
			m_find.InsertItem(i,"");
			m_find.SetItemText(i,0,bookname.c_str());
            m_find.SetItemText(i,1,writer.c_str());
			m_find.SetItemText(i,2,booknum.c_str());
			m_find.SetItemText(i,3,bookid.c_str());
			m_find.SetItemText(i,4,bookkind.c_str());
			m_find.SetItemText(i,5,bookflag.c_str());
			i++;
			find=1;
		}
	}
	if(!find) AfxMessageBox("没有找到");
	//CDialog::OnOK();
}
BOOL CBFIND::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_find.InsertColumn(0,"书名",LVCFMT_LEFT,100);
    m_find.InsertColumn(1,"作者",LVCFMT_LEFT,100);
	m_find.InsertColumn(2,"数量",LVCFMT_LEFT,50);
	m_find.InsertColumn(3,"编号",LVCFMT_LEFT,100);
	m_find.InsertColumn(4,"种类",LVCFMT_LEFT,100);
	m_find.InsertColumn(5,"状态",LVCFMT_LEFT,50);
	m_find.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


