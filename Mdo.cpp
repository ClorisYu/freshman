// Mdo.cpp : implementation file
//
/*
***************************************************
ģ����       ��CMdo
�ļ���       ��CMdo
����ļ�     ����
�ļ�ʵ�ֹ��� ����������
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/28  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Mdo.h"
#include "Lend.h"
#include "Mbook.h"
#include "Chcode.h"
#include "BBack.h"
#include "Mreader.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdo dialog


CMdo::CMdo(CWnd* pParent /*=NULL*/)
	: CDialog(CMdo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMdo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMdo, CDialog)
	//{{AFX_MSG_MAP(CMdo)
	ON_BN_CLICKED(IDC_LEND, OnLend)
	ON_BN_CLICKED(IDC_MBOOK, OnMbook)
	ON_BN_CLICKED(IDC_CHCODE, OnChcode)
	ON_BN_CLICKED(IDC_GETBACK, OnGetback)
	ON_BN_CLICKED(IDC_MREADER, OnMreader)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdo message handlers

void CMdo::OnLend() 
{
	// TODO: Add your control notification handler code here
     CLend lend;
	 lend.DoModal();	
}

void CMdo::OnMbook() 
{
	// TODO: Add your control notification handler code here
	CMbook mb;
	mb.DoModal();	
}

void CMdo::OnChcode() 
{
	// TODO: Add your control notification handler code here
    CChcode cc;
	cc.DoModal();
	
}

void CMdo::OnGetback() 
{
	// TODO: Add your control notification handler code here
	CBBack BB;
	BB.DoModal();
	
}

void CMdo::OnMreader() 
{
	// TODO: Add your control notification handler code here
	CMreader Mr;
	Mr.DoModal();
	
}
