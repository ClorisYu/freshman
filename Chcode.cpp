// Chcode.cpp : implementation file
//
/*
***************************************************
ģ����       ��CChcode
�ļ���       ��CChcode
����ļ�     ��Manager.txt
�ļ�ʵ�ֹ��� ���޸Ĺ���Ա��Ϣ
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/29  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Chcode.h"
#include "Manager.h"
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
// CChcode dialog


CChcode::CChcode(CWnd* pParent /*=NULL*/)
	: CDialog(CChcode::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChcode)
	m_ncode = _T("");
	m_nname = _T("");
	//}}AFX_DATA_INIT
}


void CChcode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChcode)
	DDX_Text(pDX, IDC_NCODE, m_ncode);
	DDX_Text(pDX, IDC_NNEW, m_nname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChcode, CDialog)
	//{{AFX_MSG_MAP(CChcode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChcode message handlers
/*
***************************************************
<PRE>
������ ��CChcode::OnOK
����   ���޸Ĺ���Ա��Ϣ
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
void CChcode::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
  
    if(m_ncode==""||m_nname=="")
	{
	   AfxMessageBox("��Ϣ������!");
	   return;
	}
	ofstream m("Manager.txt");
	m<<m_nname.GetBuffer(0)<<" "<<m_ncode.GetBuffer(0)<<endl;
    AfxMessageBox("�޸����");
	CDialog::OnOK();
}
