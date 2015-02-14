// BBack.cpp : implementation file
//
/*
***************************************************
模块名       ：CBBack
文件名       ：CBBack
相关文件     ：borrowbook.txt
文件实现功能 ：归还图书
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/26  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
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
函数名 ：CBBack::OnOK
功能   ：归还图书
参数   ：
     [IN|OUT] 参数1: 无
     [IN|OUT] 参数2：无
返回值 ：无
抛出异常：
        类型1：无
        类型2：无
-----------------------------------------------------------------------------
备注   ：无
典型用法：无
-----------------------------------------------------------------------------
作者   ：喻超蓉
<PRE>
***************************************************
*/
void CBBack::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
    string bn,wn,ID,bk,bf,rnum,rcode,reader;///////////////////借书文件变量
	string bname,wname,bid,bkind,bflag;//////////////////////图书文件变量
	int no1,no2,no,bnum;
	int find=0,find1=0;
	if(m_bID==""||m_Rnum=="")
	{
		AfxMessageBox("信息不完整!");
		return;
	}
	if(m_Bnum==0)
	{
		AfxMessageBox("请输入还书数量!");
		return;
	}
	ifstream bb("borrowbook.txt");
	//ifstream r("Reader.txt");
	while(!bb.eof())//////////////////////////////////////////判断读者是否借书
	{
        bb>>reader>>bn>>wn>>no>>ID>>bk>>bf;
		if(ID==m_bID.GetBuffer(0)&&reader==m_Rnum.GetBuffer(0))
		{
			if(no<m_Bnum)
			{
				bb.close();
				AfxMessageBox("还书数量不对!");
		        return;
			}
			bb.close();
			find=1;
			break;
		}
	}
	if(find==0)/////////////////////////////////////////////没有搜索到匹配信息
	{
		bb.close();
		AfxMessageBox("输入信息有误，请重新输入!");
		return;
	}
	else
	{
		ifstream book("books.txt");
		while(book>>bname>>wname>>bnum>>bid>>bkind>>bflag)
		{
			if(bid==m_bID.GetBuffer(0))
				find1=1;
		//	AfxMessageBox("气死我了");
		   // book.close();
		}
		if(find1==0)////////////////////////////所还书籍图书馆里没有
		{
			ifstream borr("borrowbook.txt");
			ofstream boo("books.txt",ios::app);
			ofstream backup("backups.txt",ios::app);///////////////////////////借书文件备份
			while(borr>>reader>>bn>>wn>>no>>ID>>bk>>bf)
			{
				if(ID==m_bID.GetBuffer(0))
				{
					no1=no-m_Bnum;//////////////借书文件中图书的剩余数量
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
			AfxMessageBox("还书成功!");
		}
		if(find1==1)////////////////////图书馆里有要还的这本书
		{
			ifstream bos("books.txt");
			ifstream bor("borrowbook.txt");
			ofstream boba("backups.txt");////////////////////////////图书文件备份
			ofstream lend("backups1.txt");//////////////////////////借书文件备份
		    while(bos>>bname>>wname>>bnum>>bid>>bkind>>bflag)//////图书文件里的变化
			{
				if(bid==m_bID.GetBuffer(0))
				{
					no2=bnum+m_Bnum;
					boba<<bname<<" "<<wname<<" "<<no2<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
					}else{
					boba<<bname<<" "<<wname<<" "<<bnum<<" "<<bid<<" "<<bkind<<" "<<bflag<<endl;
				}
			}
			while(bor>>reader>>bn>>wn>>no>>ID>>bk>>bf)////////////////借书文件里的变化
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
			ifstream ba("backups.txt");//////////////////////////图书文件备份
			ifstream ba1("backups1.txt");//////////////////////////借书文件备份
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
			AfxMessageBox("还书成功!");
        	ofstream clear("backups.txt",ios::trunc);
	        clear.close(); 
        	ofstream clear1("backups1.txt",ios::trunc);
	        clear1.close(); 
		}
	}
	CDialog::OnOK();
}
