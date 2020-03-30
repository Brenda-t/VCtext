
// text12Doc.cpp : Ctext12Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text12.h"
#endif

#include "text12Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ctext12Doc

IMPLEMENT_DYNCREATE(Ctext12Doc, CDocument)

BEGIN_MESSAGE_MAP(Ctext12Doc, CDocument)
END_MESSAGE_MAP()


// Ctext12Doc 构造/析构

Ctext12Doc::Ctext12Doc()
{
	// TODO: 在此添加一次性构造代码
	A.left = 50;   A.top = 50;
	A.right = 150;  A.bottom = 200;
	B.left = 300;   B.top = 350;
	B.right = 400;  B.bottom = 450;
	C.left = 350;   C.top = 100;
	C.right = 500;  C.bottom = 300;
	D.left = 50;   D.top = 350;
	D.right = 200;  D.bottom = 500;
	a = rand() % 50 + 5;
	b = rand() % 100 + 10;
	m_pt = 0;
	count1 = 0;
	count2 = 0;
	m = "+"; n = "-"; p = "*"; q = "/";
}

Ctext12Doc::~Ctext12Doc()
{
}

BOOL Ctext12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Ctext12Doc 序列化

void Ctext12Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Ctext12Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Ctext12Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Ctext12Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Ctext12Doc 诊断

#ifdef _DEBUG
void Ctext12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ctext12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ctext12Doc 命令
