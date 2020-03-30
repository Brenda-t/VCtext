
// text12Doc.h : Ctext12Doc 类的接口
//


#pragma once


class Ctext12Doc : public CDocument
{
protected: // 仅从序列化创建
	Ctext12Doc();
	DECLARE_DYNCREATE(Ctext12Doc)

// 特性
public:

// 操作
public:
	CRect A, B, C,D;
	int a, b;
	CPoint m_pt;
	int count1,count2;
	CString m, n, p, q;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Ctext12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
