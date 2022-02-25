
// hyperdistView.cpp : implementation of the ChyperdistView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "hyperdist.h"
#include "CModDlg.h"
#endif

#include "hyperdistDoc.h"
#include "hyperdistView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChyperdistView

IMPLEMENT_DYNCREATE(ChyperdistView, CView)

BEGIN_MESSAGE_MAP(ChyperdistView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChyperdistView construction/destruction

ChyperdistView::ChyperdistView() noexcept
{
	// TODO: add construction code here

}

ChyperdistView::~ChyperdistView()
{
}

BOOL ChyperdistView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ChyperdistView drawing

void ChyperdistView::OnDraw(CDC* pDC)
{
	ChyperdistDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here
	CRect rc;
	GetClientRect(&rc);
	
	int* freq = pDoc->get_freq();
	int LEN = pDoc->get_k()+1;
	int n = pDoc->get_sample_len();

	CBrush brush;
	brush.CreateHatchBrush(6, RGB(150, 66, 223));
	CBrush* pOldPen = (CBrush*)pDC->SelectObject(&brush);
	
	
	for (int i = 0; i < LEN; ++i) {
		double freqeq =  freq[i];
		int nnn = n;
		pDC->Rectangle(i * rc.Width() / LEN, (1-(double(freq[i])/n)) 
			* rc.Height(), (i + 1) * rc.Width() / LEN , rc.Height());
	}
	pDC->SelectObject(pOldPen);
	brush.DeleteObject();

}

void ChyperdistView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChyperdistView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChyperdistView diagnostics

#ifdef _DEBUG
void ChyperdistView::AssertValid() const
{
	CView::AssertValid();
}

void ChyperdistView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChyperdistDoc* ChyperdistView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChyperdistDoc)));
	return (ChyperdistDoc*)m_pDocument;
}
#endif //_DEBUG


// ChyperdistView message handlers
