// RDelete.cpp : implementation file
//
/*
***************************************************
ģ����       ��CRDelete
�ļ���       ��CRDelete
����ļ�     ��Reader.txt backups.txt
�ļ�ʵ�ֹ��� ��ɾ��������Ϣ
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/4   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
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
������ ��CRDelete::OnOK
����   ��ɾ��������Ϣ
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
void CRDelete::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	string reader,code;
	int find=0;
	if(m_Reader=="")
	{
	   AfxMessageBox("��Ϣ������!");
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
	   AfxMessageBox("�˶��߲�����!");
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
	AfxMessageBox("�˶�����ɾ��!");
	ofstream clear("backups.txt",ios::trunc);
	clear.close(); 
	CDialog::OnOK();
}
