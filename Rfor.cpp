// Rfor.cpp : implementation file
//
/*
***************************************************
ģ����       ��CRfor
�ļ���       ��CRfor
����ļ�     ��borrowbook.txt
�ļ�ʵ�ֹ��� ����ʾ��������ͼ����Ϣ
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/7   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
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
������ ��CRfor::OnOK
����   ����ʾ��������ͼ����Ϣ
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
	if(!find) AfxMessageBox("�˶���δ����!");
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
				 AfxMessageBox("����������ֻ�ܲ�ѯ�Լ��Ľ�����Ϣ!");
				 return;
			}
		}
    	 if(!find) AfxMessageBox("�˶���δ����!");
	}
		
	//bb.close();
	//CDialog::OnOK();
}

BOOL CRfor::OnInitDialog()
{

	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_find.InsertColumn(0,"����",LVCFMT_LEFT,100);
	m_find.InsertColumn(1,"����ͼ��",LVCFMT_LEFT,100);
    m_find.InsertColumn(2,"����",LVCFMT_LEFT,100);
	m_find.InsertColumn(3,"����",LVCFMT_LEFT,50);
	m_find.InsertColumn(4,"���",LVCFMT_LEFT,100);
	m_find.InsertColumn(5,"����",LVCFMT_LEFT,100);
//	m_find.InsertColumn(6,"״̬",LVCFMT_LEFT,50);
	m_find.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP);
	return TRUE;
}

