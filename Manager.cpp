// Manager.cpp : implementation file
//
/*
***************************************************
ģ����       ��CManager
�ļ���       ��CManager
����ļ�     ��Manager.txt
�ļ�ʵ�ֹ��� ������Ա��½
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/20  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Manager.h"
#include "Mdo.h"
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
// CManager dialog


CManager::CManager(CWnd* pParent /*=NULL*/)
	: CDialog(CManager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManager)
	m_Mnum = _T("");
	m_Mcode = _T("");
	//}}AFX_DATA_INIT
}


void CManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManager)
	DDX_Text(pDX, IDC_EDIT1, m_Mnum);
	DDX_Text(pDX, IDC_EDIT2, m_Mcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManager, CDialog)
	//{{AFX_MSG_MAP(CManager)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManager message handlers
/*
***************************************************
<PRE>
������ ��CManager::OnOK
����   ������Ա��½
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
void CManager::OnOK() 
{
		UpdateData(TRUE);
			string m_Mn,m_Mc;

	if(m_Mnum=="")//////////////////////////////////�ж�������Ϣ�Ƿ�����
	{
		MessageBox("��δ�����˺�!","��¼���");
		return;
	}
    if(m_Mcode=="")
	{
		MessageBox("��δ��������!","��¼���");
		return;
	}
		ifstream m("Manager.txt");
	if (m.fail())
	{
		AfxMessageBox("Error!");
	}
	// TODO: Add extra validation here
	int find=0;///////////////////////////////////////////�Ƿ���ڸ��û�
	while(!m.eof())
	{
		m>>m_Mn>>m_Mc;
        CString n,c;
		n=m_Mn.c_str();
		c=m_Mc.c_str();
		if(m_Mnum==n && m_Mcode!=c)
		{
			AfxMessageBox("�������!");
		    return;
		}
        if(m_Mnum!=n&& m_Mcode==c)
		{
			AfxMessageBox("�û�������!");
		    return;
		}
		if(m_Mnum==n && m_Mcode==c)
		{
			m.close();
			find=1;
			CDialog::OnOK();
			CMdo mdo;
			mdo.DoModal();
		}
	}
	if(find==0)//////////////////////////////////////////////�����ڣ��򵯳���ʾ��Ϣ
	{
		AfxMessageBox("�˺ź����붼����!");
		return;
	}
	
}
