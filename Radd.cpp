// Radd.cpp : implementation file
//
/*
***************************************************
ģ����       ��CRadd
�ļ���       ��CRadd
����ļ�     ��Reader.txt
�ļ�ʵ�ֹ��� ����Ӷ�����Ϣ
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/2   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
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
������ ��CRadd::OnOK
����   ����Ӷ�����Ϣ
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
void CRadd::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	string reader,code;
	if(m_Reader==""||m_password=="")
	{
		AfxMessageBox("������������Ϣ!");
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
			AfxMessageBox("�˶����Ѵ���!");
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
	AfxMessageBox("��ӳɹ�!");

	CDialog::OnOK();
}
