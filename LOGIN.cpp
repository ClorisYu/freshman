// LOGIN.cpp : implementation file
//
/*
***************************************************
ģ����       ��CLOGIN
�ļ���       ��CLOGIN
����ļ�     ����
�ļ�ʵ�ֹ��� ����½����
����         ������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸�����     ��
����       �汾       �޸���        �޸�����
2013/7/7   1.0        ����           ��
***************************************************
*/

#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "LOGIN.h"
#include "Reader.h"
#include "flag.h"
#include "Manager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLOGIN dialog


CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialog(CLOGIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLOGIN)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLOGIN)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialog)
	//{{AFX_MSG_MAP(CLOGIN)
	ON_BN_CLICKED(IDC_RLOGIN, OnRlogin)
	ON_BN_CLICKED(IDC_MLOGIN, OnMlogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLOGIN message handlers
/*
***************************************************
<PRE>
������ ��CLOGIN::OnRlogin
����   ����½����
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
����   ������
<PRE>
***************************************************
*/

void CLOGIN::OnRlogin() 
{
	// TODO: Add your control notification handler code here
	//CLOGIN::OnOK();
	CReader Reader;
	person=0;////////////////////////��¼��¼�����
	Reader.DoModal();

}

void CLOGIN::OnMlogin() 
{
	// TODO: Add your control notification handler code here
	//CLOGIN::OnOK();
	CManager Manager;
	person=1;////////////////////////��¼��¼����ݣ�
	Manager.DoModal();
}
