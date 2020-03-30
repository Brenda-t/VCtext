
// JPG02View.cpp : CJPG02View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "JPG02.h"
#endif

#include "JPG02Doc.h"
#include "JPG02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJPG02View

IMPLEMENT_DYNCREATE(CJPG02View, CView)

BEGIN_MESSAGE_MAP(CJPG02View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CJPG02View::OnFileOpen)
END_MESSAGE_MAP()

// CJPG02View 构造/析构

CJPG02View::CJPG02View()
{
	// TODO: 在此处添加构造代码
	set = false;
}

CJPG02View::~CJPG02View()
{
}

BOOL CJPG02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CJPG02View 绘制

void CJPG02View::OnDraw(CDC* pDC)
{
	CJPG02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		CFileDialog cfd(true);   //建立文本框
		int r = cfd.DoModal();   //弹出对话框
		CClientDC dc(this);
		if (r == IDOK)           //如果退出对话框选项为OK的话
		{
			CString filename = cfd.GetPathName();
			CImage img;
			img.Load(filename);
			img.Draw(pDC->m_hDC, 100, 100, img.GetWidth(), img.GetHeight());
		}
	}
}


// CJPG02View 诊断

#ifdef _DEBUG
void CJPG02View::AssertValid() const
{
	CView::AssertValid();
}

void CJPG02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJPG02Doc* CJPG02View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJPG02Doc)));
	return (CJPG02Doc*)m_pDocument;
}
#endif //_DEBUG


// CJPG02View 消息处理程序


void CJPG02View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	set = true;
	Invalidate();
}
