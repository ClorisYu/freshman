// RCH.cpp : implementation file
//
/*
***************************************************
ģ����       ��CRCH
�ļ���       ��CRCH
����ļ�     ��backups.txt Reader.txt
�ļ�ʵ�ֹ��� ���޸Ķ�����Ϣ
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/3   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
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
������ ��CRCH::OnOK
����   ���޸Ķ�����Ϣ
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
void CRCH::OnOK() 
{
	// TODO: Add extra validation here
    UpdateData(TRUE);
	string name,code;
	string bname1,wname1,bid1,bkind1,bflag1,reader;/////////////////borrowook.txt��ı���
	int bnum1;
	//CString flag;
	int find=0;
	//flag="201201";/////////////////////////////////////////////////////////////////��Ҫ�޸�
    //GetDlgItem(IDC_RUSER)->GetWindowText(flag);//////////////////////////////////
	if(m_nname==""||m_ncode=="")
	{
	   AfxMessageBox("��Ϣ������!");
	   return;
	}
	ifstream r("Reader.txt");
	ifstream bb("borrowbook.txt");
	ofstream backup("backups.txt");//////////////////////�����ļ�����
	ofstream backup1("backups1.txt");////////////////////�����ļ�����
	while(r>>name>>code)/////////////////////////////////�޸Ķ����ļ�������
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
		AfxMessageBox("�û����ظ�!");
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
	flag=m_nname;////////////////////////////////��ı���߱�־
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
    AfxMessageBox("�޸����!");
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
