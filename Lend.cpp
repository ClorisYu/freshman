// Lend.cpp : implementation file
//
/*
***************************************************
模块名       ：CLend
文件名       ：CLend
相关文件     ：books.txt Reader.txt borrowbook.txt backups.txt
文件实现功能 ：借出图书
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/7/1   1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
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
函数名 ：CLend::OnOK
功能   ：借出图书
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
void CLend::OnOK() 
{
	// TODO: Add extra validation here
	
	UpdateData(TRUE);
	string bname,wname,bid,bkind,bflag,Rnum,Rcode;//////////////////books.txt里的变量
	string bname1,wname1,bid1,bkind1,bflag1,reader;/////////////////borrowook.txt里的变量
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
		AfxMessageBox("信息不完整!");
		return;
	}
	if(find==0)
	{
		AfxMessageBox("读者错误!");
		r.close();
		return;
	}
	if(m_num<=0)/////////////////////////////防止输入非法信息，如负数
	{
		AfxMessageBox("请输入正确数量!");
		return;
	}
	find=0;
	ifstream bb("borrowbook.txt");
	ofstream backup("backups.txt");//////////////////////////////books.txt的备份文件
    ofstream backup1("backups1.txt");/////////////////////////////borrow.txt的备份文件
	while(bs>>bname>>wname>>bnum>>bid>>bkind>>bflag)//&&bb>>reader>>bname1>>wname1>>bnum1>>bid1>>bkind1>>bflag1)
	{
		if(m_bcode.GetBuffer(0)==bid)
		{
			find=1;
			num=bnum-m_num;/////////////////////////////////num是图书馆该本图书的剩余图书数量
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
			num1=bnum1+m_num;////////////////////////////////num1是若之前借过此书的借书量
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
		AfxMessageBox("此图书不存在!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;
	}
	if(num<0)
	{
		AfxMessageBox("数量不足，请重新输入!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}
	if((all+m_num)>10)
	{
		AfxMessageBox("您超过了借书上限，最多借10本书!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}

	if(num1>5)
	{
		AfxMessageBox("您超过了借书上限，同本书最多借5本!");
		backup.close();
		backup1.close();
		bb.close();
		bs.close();
		return;	
	}

	if(m_num>5)
	{
		AfxMessageBox("同本书最多能借五本!");///////////////////////////////限制同本书一次最多借5本
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
		AfxMessageBox("借书成功!");
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
        	AfxMessageBox("借书成功!");
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
	    	AfxMessageBox("借书操作失败!");
          	book.close();
            bb.close();
	    	return;
		}
    	ofstream clear("backups.txt",ios::trunc);//////////////////////////////清空备份文件
    	clear.close();
		ofstream clear1("backups1.txt",ios::trunc);
    	clear1.close();
    	EndDialog(0);
	}
}
