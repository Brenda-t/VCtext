
// JPG01View.cpp : CJPG01View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "JPG01.h"
#endif

#include "JPG01Doc.h"
#include "JPG01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJPG01View

IMPLEMENT_DYNCREATE(CJPG01View, CView)

BEGIN_MESSAGE_MAP(CJPG01View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CJPG01View::OnFileOpen)
END_MESSAGE_MAP()

// CJPG01View 构造/析构

CJPG01View::CJPG01View()
{
	// TODO: 在此处添加构造代码

}

CJPG01View::~CJPG01View()
{
}

BOOL CJPG01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CJPG01View 绘制

void CJPG01View::OnDraw(CDC* /*pDC*/)
{
	CJPG01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CJPG01View 诊断

#ifdef _DEBUG
void CJPG01View::AssertValid() const
{
	CView::AssertValid();
}

void CJPG01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJPG01Doc* CJPG01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJPG01Doc)));
	return (CJPG01Doc*)m_pDocument;
}
#endif //_DEBUG


// CJPG01View 消息处理程序


void CJPG01View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);   //建立文本框
	int r = cfd.DoModal();   //弹出对话框
	CClientDC dc(this);
	if (r == IDOK)           //如果退出对话框选项为OK的话
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
}
