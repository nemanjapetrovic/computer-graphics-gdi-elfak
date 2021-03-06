
// CarBilboardView.h : interface of the CCarBilboardView class
//

#pragma once


class CCarBilboardView : public CView
{
protected: // create from serialization only
	CCarBilboardView();
	DECLARE_DYNCREATE(CCarBilboardView)

// Attributes
public:
	CCarBilboardDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	void translateAndRotate(CDC *pDC,float x, float y, float angle);
	float toRad(float angle);
	void Translate(CDC *pDC, float x, float y, bool right);
	void Rotate(CDC *pDC, float angle, bool right);
	void DrawAll(CRect rect, CDC *pDC);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCarBilboardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in CarBilboardView.cpp
inline CCarBilboardDoc* CCarBilboardView::GetDocument() const
   { return reinterpret_cast<CCarBilboardDoc*>(m_pDocument); }
#endif

