// Bdelete.cpp : implementation file
//
/*
***************************************************
ģ����       ��CBdelete
�ļ���       ��CBdelete
����ļ�     ��books.txt backups.txt
�ļ�ʵ�ֹ��� ��ɾ��ͼ��
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/27  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Bdelete.h"
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
// CBdelete dialog


CBdelete::CBdelete(CWnd* pParent /*=NULL*/)
	: CDialog(CBdelete::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBdelete)
	m_bcode = _T("");
	//}}AFX_DATA_INIT
}


void CBdelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBdelete)
	DDX_Text(pDX, IDC_EDIT1, m_bcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBdelete, CDialog)
	//{{AFX_MSG_MAP(CBdelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBdelete message handlers
/*
***************************************************
<PRE>
������ ��CBdelete::OnOK
����   ��ɾ��ͼ��
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
void CBdelete::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_bcode=="")
	{
		AfxMessageBox("������ͼ����!");
		return;
	}
	//deleteb();
	if(deleteb())
	AfxMessageBox("ɾ���ɹ�!");
	CDialog::OnOK();
}


int CBdelete::deleteb()
{

  string bna,wna,kind,bID,bf;
  int num;
  	ifstream bs("books.txt");
	if(bs.fail())
	{
		AfxMessageBox("error");
	}
	ofstream bu("backups.txt");
	int find=0;
	while(bs>>bna>>wna>>num>>bID>>kind>>bf)
	{
		if(bID==m_bcode.GetBuffer(0))
		{
			find=1;
		}
		else
		{
			bu<<bna<<" "<<wna<<" "<<num<<" "<<bID<<" "
				<<kind<<" "<<bf<<endl;
		}
	}
	bs.close();
	bu.close();
    if(find==1)
	{                                    
		ofstream bo("books.txt");          
		ifstream ba("backups.txt");       
		while(ba>>bna>>wna>>num>>bID>>kind>>bf)
		{
            
            bo<<bna<<" "<<wna<<" "<<num<<" "<<bID<<" "
				<<kind<<" "<<bf<<endl;
		} 
		bo.close();
		ba.close();
		ofstream clear("backups.txt",ios::trunc);
		clear.close();
		EndDialog(0);
	}
	else
	{
		AfxMessageBox("�������Ȿ��!");
		return 0;
	}
  return 1;
}


