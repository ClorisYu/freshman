// Rdo.cpp : implementation file
//
/*
***************************************************
ģ����       ��CRdo
�ļ���       ��CRdo
����ļ�     ����
�ļ�ʵ�ֹ��� ����������
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/30  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Rdo.h"
#include "RCH.h"
#include "Rfor.h"
#include "flag.h"
#include "BFIND.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdo dialog


CRdo::CRdo(CWnd* pParent /*=NULL*/)
	: CDialog(CRdo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRdo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRdo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRdo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRdo, CDialog)
	//{{AFX_MSG_MAP(CRdo)
	ON_BN_CLICKED(IDC_CHCODE, OnChcode)
	ON_BN_CLICKED(IDC_BLOOK, OnBlook)
	ON_BN_CLICKED(IDC_LBLOOK, OnLblook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRdo message handlers

void CRdo::OnChcode() 
{
	// TODO: Add your control notification handler code here
	CRCH rch;
	rch.DoModal();
	
}

void CRdo::OnBlook() 
{
	// TODO: Add your control notification handler code here
    CBFIND bf;
	bf.DoModal();
	
}

void CRdo::OnLblook() 
{
	// TODO: Add your control notification handler code here
    CRfor rf;
	rf.DoModal();
	
}
