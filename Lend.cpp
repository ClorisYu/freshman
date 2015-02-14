// Lend.cpp : implementation file
//
/*
***************************************************
ģ����       ��CLend
�ļ���       ��CLend
����ļ�     ��books.txt Reader.txt borrowbook.txt backups.txt
�ļ�ʵ�ֹ��� �����ͼ��
����         ��������
�汾         ��1.0
-----------------------------------------------------------------------------
��ע         ����
-----------------------------------------------------------------------------
�޸ļ�¼     ��
����       �汾       �޸���        �޸�����
2013/7/1   1.0        ������        ��
***************************************************
*/
#include "stdafx.h"
#include "ͼ�����ϵͳ.h"
#include "Lend.h"
#include "Mbook.h"
//#include "book.h"
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
// CLend dialog
//extern int find=0;
CLend::CLend(CWnd* pParent /*=NULL*/)
	: CDialog(CLend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLend)
	m_bcode = _T("");
	m_Rnum = _T("");
	m_num = 0;
	//}}AFX_DATA_INIT
}


void CLend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLend)
	DDX_Text(pDX, IDC_EDIT1, m_bcode);
	DDV_MaxChars(pDX, m_bcode, 12);
	DDX_Text(pDX, IDC_EDIT3, m_Rnum);
	DDV_MaxChars(pDX, m_Rnum, 12);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLend, CDialog)
	//{{AFX_MSG_MAP(CLend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLend message handlers



/*
***************************************************
<PRE>
������ ��CLend::OnOK
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
void CLend::OnOK() 
{
	// TODO: Add extra validation here
	
	UpdateData(TRUE);
	string bname,wname,bid,bkind,bflag,Rnum,Rcode;//////////////////books.txt��ı���
	string bname1,wname1,bid1,bkind1,bflag1,reader;/////////////////borrowook.txt��ı���
	int bnum,num,bnum1,num1,all=0;
	int find=0,_find=0,find1=0;
	ifstream bs("books.txt");
	ifstream r("Reader.txt");
	while(!r.eof())
	{
        r>>Rnum>>Rcode;
		if(Rnum==m_Rnum.GetBuffer(0))
		{
			r.close();
			find=1;
			break;
		}
	}
	if(m_bcode==""||m_Rnum=="")
	{
		AfxMessageBox("��Ϣ������!");
		return;
	}
	if(find==0)
	{
		AfxMessageBox("���ߴ���!");
		r.close();
		return;
	}
	if(m_num<=0)/////////////////////////////��ֹ����Ƿ���Ϣ���縺��
	{
		AfxMessageBox("��������ȷ����!");
		return;
	}
	find=0;
	ifstream bb("borrowbook.txt");
	ofstream backup("backups.txt");//////////////////////////////books.txt�ı����ļ�
    ofstream backup1("backups1.txt");/////////////////////////////borrow.txt�ı����ļ�
	while(bs>>bname>>wname>>bnum>>bid>>bkind>>bflag)//&&bb>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1)
	{
		if(m_bcode.GetBuffer(0)==bid)
		{
			find=1;
			num=bnum-m_num;/////////////////////////////////num��ͼ��ݸñ�ͼ���ʣ��ͼ������
			if(num>0){
				backup<<bname<<" "<<wname<<" "<<num<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
			}
			
		}else{
			backup<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
		}
		
		
	}
	while(!bb.eof())
	{
		bb>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1;
		if(m_bcode.GetBuffer(0)==bid1&&reader==m_Rnum.GetBuffer(0))
		{
			_find=1;
			num1=bnum1+m_num;////////////////////////////////num1����֮ǰ�������Ľ�����
			backup1<<reader<<" "<<bname1<<" "<<wname1<<" "<<num1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
		}else{
			backup1<<reader<<" "<<bname1<<" "<<wname1<<" "<<bnum1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
		}
		if(m_Rnum.GetBuffer(0)==reader)
		{
			all=all+bnum1;
		}
	}

	if(find==0)
	{
		AfxMessageBox("��ͼ�鲻����!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;
	}
	if(num<0)
	{
		AfxMessageBox("�������㣬����������!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}
	if((all+m_num)>10)
	{
		AfxMessageBox("�������˽������ޣ�����10����!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}

	if(num1>5)
	{
		AfxMessageBox("�������˽������ޣ�ͬ��������5��!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}

	if(m_num>5)
	{
		AfxMessageBox("ͬ��������ܽ��屾!");///////////////////////////////����ͬ����һ������5��
		return;
	}
	if(_find==1)
	{
    	ifstream up("backups.txt");
        ifstream up1("backups1.txt");
		ofstream lend("borrowbook.txt");
		ofstream bk("books.txt");
		while(up>>bname>>wname>>bnum>>bid>>bkind>>bflag)
		{
			bk<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
		}
		while(up1>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1)
		{
			lend<<reader<<" "<<bname1<<" "<<wname1<<" "<<bnum1<<" "<<bid1<<" "<<bkind1<<" "<<bflag1<<endl;
		}
		up.close();
		up1.close();
		bk.close();
		lend.close();
    	ofstream clear("backups.txt",ios::trunc);
    	clear.close();
    	ofstream clear1("backups1.txt",ios::trunc);
    	clear1.close();
		AfxMessageBox("����ɹ�!");
		EndDialog(0);
	}

	if(_find==0)
	{
		ifstream book("books.txt");
		ofstream borrow("borrowbook.txt",ios::app);
		while(!book.eof())
		{
			book>>bname>>wname>>bnum>>bid>>bkind>>bflag;
			if(m_bcode.GetBuffer(0)==bid)
			{
				borrow<<m_Rnum.GetBuffer(0)<<" "<<bname<<" "<<wname<<" "<<m_num<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
				find1=1;
			}
		}
    	if(find1)
		{
        	AfxMessageBox("����ɹ�!");
        	book.close();
            borrow.close();
        	ifstream bp("backups.txt");
        	ofstream boo("books.txt");
        	while(bp>>bname>>wname>>bnum>>bid>>bkind>>bflag)
			{
		    	boo<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
			}
        	bp.close();
    	    boo.close();
		}
    	else
		{
	    	AfxMessageBox("�������ʧ��!");
          	book.close();
            bb.close();
	    	return;
		}
    	ofstream clear("backups.txt",ios::trunc);//////////////////////////////��ձ����ļ�
    	clear.close();
		ofstream clear1("backups1.txt",ios::trunc);
    	clear1.close();
    	EndDialog(0);
	}
}
