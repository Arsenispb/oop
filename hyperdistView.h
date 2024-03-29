
// hyperdistView.h : interface of the ChyperdistView class
//

#pragma once


class ChyperdistView : public CView
{
protected: // create from serialization only
	ChyperdistView() noexcept;
	DECLARE_DYNCREATE(ChyperdistView)

// Attributes
public:
	ChyperdistDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~ChyperdistView();
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
};

#ifndef _DEBUG  // debug version in hyperdistView.cpp
inline ChyperdistDoc* ChyperdistView::GetDocument() const
   { return reinterpret_cast<ChyperdistDoc*>(m_pDocument); }
#endif

