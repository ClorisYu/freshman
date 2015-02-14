// Bdelete.cpp : implementation file
//
/*
***************************************************
模块名       ：CBdelete
文件名       ：CBdelete
相关文件     ：books.txt backups.txt
文件实现功能 ：删除图书
作者         ：喻超蓉
版本         ：1.0
-----------------------------------------------------------------------------
备注         ：无
-----------------------------------------------------------------------------
修改记录     ：
日期       版本       修改人        修改内容
2013/6/27  1.0        喻超蓉        无
***************************************************
*/
#include "stdafx.h"
#include "图书管理系统.h"
#include "Bdelete.h"
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
// CBdelete dialog


CBdelete::CBdelete(CWnd* pParent /*=NULL*/)
	: CDialog(CBdelete::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBdelete)
	m_bcode = _T("");
	//}}AFX_DATA_INIT
}


void CBdelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBdelete)
	DDX_Text(pDX, IDC_EDIT1, m_bcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBdelete, CDialog)
	//{{AFX_MSG_MAP(CBdelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBdelete message handlers
/*
***************************************************
<PRE>
函数名 ：CBdelete::OnOK
功能   ：删除图书
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
void CBdelete::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_bcode=="")
	{
		AfxMessageBox("请输入图书编号!");
		return;
	}
	//deleteb();
	if(deleteb())
	AfxMessageBox("删除成功!");
	CDialog::OnOK();
}


int CBdelete::deleteb()
{

  string bna,wna,kind,bID,bf;
  int num;
  	ifstream bs("books.txt");
	if(bs.fail())
	{
		AfxMessageBox("error");
	}
	ofstream bu("backups.txt");
	int find=0;
	while(bs>>bna>>wna>>num>>bID>>kind>>bf)
	{
		if(bID==m_bcode.GetBuffer(0))
		{
			find=1;
		}
		else
		{
			bu<<bna<<" "<<wna<<" "<<num<<" "<<bID<<" "
				<<kind<<" "<<bf<<endl;
		}
	}
	bs.close();
	bu.close();
    if(find==1)
	{                                    
		ofstream bo("books.txt");          
		ifstream ba("backups.txt");       
		while(ba>>bna>>wna>>num>>bID>>kind>>bf)
		{
            
            bo<<bna<<" "<<wna<<" "<<num<<" "<<bID<<" "
				<<kind<<" "<<bf<<endl;
		} 
		bo.close();
		ba.close();
		ofstream clear("backups.txt",ios::trunc);
		clear.close();
		EndDialog(0);
	}
	else
	{
		AfxMessageBox("不存在这本书!");
		return 0;
	}
  return 1;
}


