
// text18View.cpp : Ctext18View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text18.h"
#endif

#include "text18Doc.h"
#include "text18View.h"
#include "MyDlg.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext18View

IMPLEMENT_DYNCREATE(Ctext18View, CView)

BEGIN_MESSAGE_MAP(Ctext18View, CView)
	ON_COMMAND(ID_PopFileDlg, &Ctext18View::OnPopfiledlg)
	ON_COMMAND(ID_PopDlg, &Ctext18View::OnPopdlg)
END_MESSAGE_MAP()

// Ctext18View 构造/析构

Ctext18View::Ctext18View()
{
	// TODO: 在此处添加构造代码

}

Ctext18View::~Ctext18View()
{
}

BOOL Ctext18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext18View 绘制

void Ctext18View::OnDraw(CDC* /*pDC*/)
{
	Ctext18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext18View 诊断

#ifdef _DEBUG
void Ctext18View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext18Doc* Ctext18View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext18Doc)));
	return (Ctext18Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext18View 消息处理程序


void Ctext18View::OnPopfiledlg()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	CClientDC dc(this);
	CString filename;
	if (t== IDOK)
	{
		filename = cfd.GetPathName();
		dc.TextOutW(20, 30, filename);
		ofstream ofs("D:\\abc.txt");
		std::wstring ws(filename);
		std::string s;
		s.assign(ws.begin(), ws.end());
		ofs << s << endl;
	}

}


void Ctext18View::OnPopdlg()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
}
