// BFIND.cpp : implementation file
//
/*
***************************************************
ģ����       ��CBFIND
�ļ���       ��CBFIND
����ļ�     ��books.txt
�ļ�ʵ�ֹ��� ������ͼ��
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/28  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
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
������ ��CBFIND::OnOK
����   ������ͼ��
����   ��
     [IN|OUT] ����1: ��
     [IN|OUT] ����2����
����ֵ ����
�׳��쳣��
        ����1����
        ����2����
-----------------------------------------------------------------------------
��ע   ����
�����÷�����
-----------------------------------------------------------------------------
����   ��������
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
	if(!find) AfxMessageBox("û���ҵ�");
	//CDialog::OnOK();
}
BOOL CBFIND::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_find.InsertColumn(0,"����",LVCFMT_LEFT,100);
    m_find.InsertColumn(1,"����",LVCFMT_LEFT,100);
	m_find.InsertColumn(2,"����",LVCFMT_LEFT,50);
	m_find.InsertColumn(3,"���",LVCFMT_LEFT,100);
	m_find.InsertColumn(4,"����",LVCFMT_LEFT,100);
	m_find.InsertColumn(5,"״̬",LVCFMT_LEFT,50);
	m_find.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


