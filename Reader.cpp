// Reader.cpp : implementation file
//
/*
***************************************************
ģ����       ��CReader
�ļ���       ��CReader
����ļ�     ��Reader.txt
�ļ�ʵ�ֹ��� �����ߵ�½
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/6   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Reader.h"
#include "Rdo.h"
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
// CReader dialog


CReader::CReader(CWnd* pParent /*=NULL*/)
	: CDialog(CReader::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReader)
	m_Rcode = _T("");
	m_Rnum = _T("");
	//}}AFX_DATA_INIT
}


void CReader::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReader)
	DDX_Text(pDX, IDC_RCODE, m_Rcode);
	DDX_Text(pDX, IDC_RUSER, m_Rnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReader, CDialog)
	//{{AFX_MSG_MAP(CReader)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReader message handlers
/*
***************************************************
<PRE>
������ ��CReader::OnOK
����   �����ߵ�½
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
void CReader::OnOK() 
{
		UpdateData(TRUE);
		string m_Rn,m_Rc;

	if(m_Rnum=="")//////////////////////////////////�ж�������Ϣ�Ƿ�����
	{
		MessageBox("��δ�����˺�!","��¼���");
		return;
	}
    if(m_Rcode=="")
	{
		MessageBox("��δ��������!","��¼���");
		return;
	}
	flag=m_Rnum;
		ifstream r("Reader.txt");
	if (r.fail())
	{
		AfxMessageBox("Error!");
	}
	// TODO: Add extra validation here
		int find=0;///////////////////////////////////////////�Ƿ���ڸ��û�
	while(!r.eof())
	{
		r>>m_Rn>>m_Rc;
        CString n,c;
		n=m_Rn.c_str();
		c=m_Rc.c_str();
		if(m_Rnum==n && m_Rcode==c)
		{
			r.close();
			find=1;
			CDialog::OnOK();
			CRdo rdo;
			rdo.DoModal();
		}
	}
	if(find==0)//////////////////////////////////////////////�����ڣ��򵯳���ʾ��Ϣ
	{
		AfxMessageBox("�˺Ż��������!");
		return;
	}

}



