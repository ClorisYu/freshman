// Mreader.cpp : implementation file
//
/*
***************************************************
ģ����       ��CMreader
�ļ���       ��CMreader
����ļ�     ����
�ļ�ʵ�ֹ��� ����������
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
#include "Mreader.h"
#include "Radd.h"
#include "RDelete.h"
#include "Rfor.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMreader dialog


CMreader::CMreader(CWnd* pParent /*=NULL*/)
	: CDialog(CMreader::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMreader)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMreader::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMreader) 
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMreader, CDialog)
	//{{AFX_MSG_MAP(CMreader)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_FOR, OnFor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMreader message handlers

void CMreader::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CRadd Ra;
	Ra.DoModal();
	
}

void CMreader::OnDelete() 
{
	// TODO: Add your control notification handler code here
    CRDelete rd;
	rd.DoModal();	
}

void CMreader::OnFor() 
{
	// TODO: Add your control notification handler code here
	CRfor rf;
	rf.DoModal();	
}
