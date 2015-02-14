// BBack.cpp : implementation file
//
/*
***************************************************
ģ����       ��CBBack
�ļ���       ��CBBack
����ļ�     ��borrowbook.txt
�ļ�ʵ�ֹ��� ���黹ͼ��
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/6/26  1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "BBack.h"
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
// CBBack dialog


CBBack::CBBack(CWnd* pParent /*=NULL*/)
	: CDialog(CBBack::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBBack)
	m_bID = _T("");
	m_Bnum = 0;
	m_Rnum = _T("");
	//}}AFX_DATA_INIT
}


void CBBack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBBack)
	DDX_Text(pDX, IDC_EDIT1, m_bID);
	DDX_Text(pDX, IDC_EDIT2, m_Bnum);
	DDV_MinMaxInt(pDX, m_Bnum, 0, 5);
	DDX_Text(pDX, IDC_EDIT3, m_Rnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBBack, CDialog)
	//{{AFX_MSG_MAP(CBBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBack message handlers
/*
***************************************************
<PRE>
������ ��CBBack::OnOK
����   ���黹ͼ��
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
void CBBack::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
    string bn,wn,ID,bk,bf,rnum,rcode,reader;///////////////////�����ļ�����
	string bname,wname,bid,bkind,bflag;//////////////////////ͼ���ļ�����
	int no1,no2,no,bnum;
	int find=0,find1=0;
	if(m_bID==""||m_Rnum=="")
	{
		AfxMessageBox("��Ϣ������!");
		return;
	}
	if(m_Bnum==0)
	{
		AfxMessageBox("�����뻹������!");
		return;
	}
	ifstream bb("borrowbook.txt");
	//ifstream r("Reader.txt");
	while(!bb.eof())//////////////////////////////////////////�ж϶����Ƿ����
	{
        bb>>reader>>bn>>wn>>no>>ID>>bk>>bf;
		if(ID==m_bID.GetBuffer(0)&&reader==m_Rnum.GetBuffer(0))
		{
			if(no<m_Bnum)
			{
				bb.close();
				AfxMessageBox("������������!");
		        return;
			}
			bb.close();
			find=1;
			break;
		}
	}
	if(find==0)/////////////////////////////////////////////û��������ƥ����Ϣ
	{
		bb.close();
		AfxMessageBox("������Ϣ��������������!");
		return;
	}
	else
	{
		ifstream book("books.txt");
		while(book>>bname>>wname>>bnum>>bid>>bkind>>bflag)
		{
			if(bid==m_bID.GetBuffer(0))
				find1=1;
		//	AfxMessageBox("��������");
		   // book.close();
		}
		if(find1==0)////////////////////////////�����鼮ͼ�����û��
		{
			ifstream borr("borrowbook.txt");
			ofstream boo("books.txt",ios::app);
			ofstream backup("backups.txt",ios::app);///////////////////////////�����ļ�����
			while(borr>>reader>>bn>>wn>>no>>ID>>bk>>bf)
			{
				if(ID==m_bID.GetBuffer(0))
				{
					no1=no-m_Bnum;//////////////�����ļ���ͼ���ʣ������
					boo<<bn<<" "<<wn<<" "<<m_Bnum<<" "<<m_bID.GetBuffer(0)<<" "<<bk<<" "<<bf<<endl;
					if(no1>0)
					backup<<reader<<" "<<bn<<" "<<wn<<" "<<no1<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
				}
				else
					backup<<reader<<" "<<bn<<" "<<wn<<" "<<no<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
			}			
			borr.close();
			boo.close();
			backup.close();
			ifstream up("backups.txt");
			ofstream lend("borrowbook.txt");
            while(up>>reader>>bn>>wn>>no>>ID>>bk>>bf)
			{
				lend<<reader<<" "<<bn<<" "<<wn<<" "<<no<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
			}
			up.close();
			lend.close();
        	ofstream clear("backups.txt",ios::trunc);
	        clear.close();         
			AfxMessageBox("����ɹ�!");
		}
		if(find1==1)////////////////////ͼ�������Ҫ�����Ȿ��
		{
			ifstream bos("books.txt");
			ifstream bor("borrowbook.txt");
			ofstream boba("backups.txt");////////////////////////////ͼ���ļ�����
			ofstream lend("backups1.txt");//////////////////////////�����ļ�����
		    while(bos>>bname>>wname>>bnum>>bid>>bkind>>bflag)//////ͼ���ļ���ı仯
			{
				if(bid==m_bID.GetBuffer(0))
				{
					no2=bnum+m_Bnum;
					boba<<bname<<" "<<wname<<" "<<no2<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
					}else{
					boba<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
				}
			}
			while(bor>>reader>>bn>>wn>>no>>ID>>bk>>bf)////////////////�����ļ���ı仯
			{
				if(ID==m_bID.GetBuffer(0))
				{
					no1=no-m_Bnum;
					if(no1>0)
					lend<<reader<<" "<<bn<<" "<<wn<<" "<<no1<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
				}else{
					lend<<reader<<" "<<bn<<" "<<wn<<" "<<no<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
				}
			}
			bos.close();
			bor.close();
			boba.close();
			lend.close();
			ofstream b("books.txt");
			ofstream br("borrowbook.txt");
			ifstream ba("backups.txt");//////////////////////////ͼ���ļ�����
			ifstream ba1("backups1.txt");//////////////////////////�����ļ�����
            while(ba1>>reader>>bn>>wn>>no>>ID>>bk>>bf)
			{
				br<<reader<<" "<<bn<<" "<<wn<<" "<<no<<" "<<ID<<" "<<bk<<" "<<bf<<endl;
				
			}
			while(ba>>bname>>wname>>bnum>>bid>>bkind>>bflag)
			{
				b<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
			}
			ba.close();
			ba1.close();
			b.close();
			br.close();
			AfxMessageBox("����ɹ�!");
        	ofstream clear("backups.txt",ios::trunc);
	        clear.close(); 
        	ofstream clear1("backups1.txt",ios::trunc);
	        clear1.close(); 
		}
	}
	CDialog::OnOK();
}
