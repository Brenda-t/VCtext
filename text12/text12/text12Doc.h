
// text12Doc.h : Ctext12Doc ��Ľӿ�
//


#pragma once


class Ctext12Doc : public CDocument
{
protected: // �������л�����
	Ctext12Doc();
	DECLARE_DYNCREATE(Ctext12Doc)

// ����
public:

// ����
public:
	CRect A, B, C,D;
	int a, b;
	CPoint m_pt;
	int count1,count2;
	CString m, n, p, q;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Ctext12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ�����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};