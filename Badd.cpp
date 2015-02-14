// Badd.cpp : implementation file
//
/*
***************************************************
ģ����       ��CBadd
�ļ���       ��CBadd
����ļ�     ��books.txt
�ļ�ʵ�ֹ��� �����ͼ��
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����         �汾       �޸���        �޸�����
2013/6/25    1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Badd.h"
//#include "Bdelete.h"
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
// CBadd dialog


CBadd::CBadd(CWnd* pParent /*=NULL*/)
	: CDialog(CBadd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBadd)
	m_bcode = _T("");
	m_bname = _T("");
	m_wname = _T("");
	m_bnum = 0;
	m_bkind = -1;
	//}}AFX_DATA_INIT
}


void CBadd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBadd)
	DDX_Text(pDX, IDC_BCODE, m_bcode);
	DDV_MaxChars(pDX, m_bcode, 12);
	DDX_Text(pDX, IDC_BNAME, m_bname);
	DDV_MaxChars(pDX, m_bname, 12);
	DDX_Text(pDX, IDC_WNAME, m_wname);
	DDV_MaxChars(pDX, m_wname, 12);
	DDX_Text(pDX, IDC_BNUM, m_bnum);
	DDV_MinMaxInt(pDX, m_bnum, 1, 10000);
	DDX_Radio(pDX, IDC_RADIO1, m_bkind);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBadd, CDialog)
	//{{AFX_MSG_MAP(CBadd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBadd message handlers
/*
***************************************************
<PRE>
������ ��CBadd::OnOK
����   �����ͼ��
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
void CBadd::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
   string bname,wname,bid,bkind,bkind1,bflag="�ɽ�",bflag1;
   string Bname,Wname,Bid,Bkind,Bflag;
   int bnum,num,find=0,Bnum;
  // CBdelete Bd;
   	if(m_bname=="" || m_wname=="" ||m_bnum==0
		|| m_bcode=="" ||m_bkind<0)
	{ 
		AfxMessageBox("��Ϣ������!");
		return;
	}
	switch(m_bkind)
	{
	case 0:bkind="��ѧ��";
		break;
	case 1:bkind="������";
		break;
	case 2:bkind="�Ƽ���";
		break;
	case 3:bkind="������";
		break;
	}
	ifstream bs("books.txt");
	if(!bs.fail())
	while(!bs.eof())
	{
         bs>>bname>>wname>>bnum>>bid>>bkind1>>bflag1;
		 if(m_bname.GetBuffer(0)!=bname&&m_wname.GetBuffer(0)!=wname&&m_bcode.GetBuffer(0)==bid)
		 {
             AfxMessageBox("����ظ�!");
			   bs.close();
			 return;
		 }
		 if(m_bname.GetBuffer(0)==bname&&m_wname.GetBuffer(0)==wname&&m_bcode.GetBuffer(0)!=bid)
		 {
             MessageBox(bid.c_str(),"��ͼ���Ѵ��ڣ������:");
			   bs.close();
			 return;
		 }
		 if(m_bname.GetBuffer(0)==bname&&m_wname.GetBuffer(0)==wname)
		 {
			 num=m_bnum+bnum;
			 find=1;
		 }
	}
    bs.close();
	if(find==0)
	{
	ofstream add("books.txt",ios::app);
	if(add.fail())
	{
		AfxMessageBox("error");
	}
	add<<m_bname.GetBuffer(0)<<" "<<m_wname.GetBuffer(0)<<" "<<m_bnum
			<<" "<<m_bcode.GetBuffer(0)<<" "<<bkind<<" "<<bflag<<endl;
	add.close();
	AfxMessageBox("��ӳɹ�!");
	}
	if(find) /////////////////////////////////////////////////////////////��ӵ�ͼ���Ѿ�����
	{
		ifstream _add("books.txt");
		ofstream backup("backups.txt",ios::app);
  	    if(_add.fail()||backup.fail())
		{
			AfxMessageBox("error");
		    //return;
		}	
	   int find=0;
	    while(_add>>bname>>wname>>bnum>>bid>>bkind1>>bflag1)
		{
		    if(bid!=m_bcode.GetBuffer(0))
			{
			backup<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "
		 		<<bkind1<<" "<<bflag1<<endl;
			}
		}
		_add.close();
	    backup.close();
        ofstream bo("books.txt");          
		ifstream ba("backups.txt");       
		while(ba>>Bname>>Wname>>Bnum>>Bid>>Bkind>>Bflag)
		{
            
            bo<<Bname<<" "<<Wname<<" "<<Bnum<<" "<<Bid<<" "
				<<Bkind<<" "<<Bflag<<endl;
		} 
		bo.close();
		ba.close();
		ofstream clear("backups.txt",ios::trunc);
		clear.close();
		ofstream add1("books.txt",ios::app); 
		add1<<m_bname.GetBuffer(0)<<" "<<m_wname.GetBuffer(0)<<" "<<num
			<<" "<<m_bcode.GetBuffer(0)<<" "<<bkind<<" "<<bflag<<endl;
		add1.close();
       	AfxMessageBox("��ӳɹ�!");
	}
		
	EndDialog(0);
}


	

