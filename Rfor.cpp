// Rfor.cpp : implementation file
//
/*
***************************************************
模块名       ：CRfor
文件名       ：CRfor
相关文件     ：borrowbook.txt
文件实现功能 ：显示读者所借图书信息
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/7   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Rfor.h"
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
// CRfor dialog


CRfor::CRfor(CWnd* pParent /*=NULL*/)
	: CDialog(CRfor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRfor)
	m_reader = _T("");
	//}}AFX_DATA_INIT
}


void CRfor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRfor)
	DDX_Control(pDX, IDC_LIST1, m_find);
	DDX_Text(pDX, IDC_EDIT1, m_reader);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRfor, CDialog)
	//{{AFX_MSG_MAP(CRfor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRfor message handlers
/*
***************************************************
<PRE>
函数名 ：CRfor::OnOK
功能   ：显示读者所借图书信息
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
void CRfor::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	string reader,bookname,writer,booknum,bookid,bookkind,bookflag;
	int find=0;
	ifstream bb("borrowbook.txt");
	if(bb.fail())
	{
		AfxMessageBox("error");
	}
	int i=0;
	if(person==1)
	{
    while(bb>>reader>>bookname>>writer>>booknum>>bookid>>bookkind>>bookflag)
	{
		
		if(reader.c_str()==m_reader)
		{
			m_find.InsertItem(i,"");
			m_find.SetItemText(i,0,reader.c_str());
			m_find.SetItemText(i,1,bookname.c_str());
            m_find.SetItemText(i,2,writer.c_str());
			m_find.SetItemText(i,3,booknum.c_str());
			m_find.SetItemText(i,4,bookid.c_str());
			m_find.SetItemText(i,5,bookkind.c_str());
		//	m_find.SetItemText(i,6,bookflag.c_str());
			i++;
			find=1;
		}
	}
	if(!find) AfxMessageBox("此读者未借书!");
	}
	else
	{
    	while(bb>>reader>>bookname>>writer>>booknum>>bookid>>bookkind>>bookflag)
		{
 	 	
    		if(reader.c_str()==m_reader&&m_reader==flag)
			{
		    	m_find.InsertItem(i,"");
		    	m_find.SetItemText(i,0,reader.c_str());
		    	m_find.SetItemText(i,1,bookname.c_str());
                m_find.SetItemText(i,2,writer.c_str());
		    	m_find.SetItemText(i,3,booknum.c_str());
		    	m_find.SetItemText(i,4,bookid.c_str());
	    		m_find.SetItemText(i,5,bookkind.c_str());
		//	m_find.SetItemText(i,6,bookflag.c_str());
		     	i++;
		    	find=1;
			}
			if(m_reader!=flag)
			{
				 AfxMessageBox("输入有误，您只能查询自己的借书信息!");
				 return;
			}
		}
    	 if(!find) AfxMessageBox("此读者未借书!");
	}
		
	//bb.close();
	//CDialog::OnOK();
}

BOOL CRfor::OnInitDialog()
{

	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_find.InsertColumn(0,"读者",LVCFMT_LEFT,100);
	m_find.InsertColumn(1,"所借图书",LVCFMT_LEFT,100);
    m_find.InsertColumn(2,"作者",LVCFMT_LEFT,100);
	m_find.InsertColumn(3,"数量",LVCFMT_LEFT,50);
	m_find.InsertColumn(4,"编号",LVCFMT_LEFT,100);
	m_find.InsertColumn(5,"种类",LVCFMT_LEFT,100);
//	m_find.InsertColumn(6,"状态",LVCFMT_LEFT,50);
	m_find.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);
	return TRUE;
}

