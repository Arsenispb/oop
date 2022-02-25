
// hyperdistDoc.cpp : implementation of the ChyperdistDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "hyperdist.h"
#endif

#include "hyperdistDoc.h"
#include "CModDlg.h"
#include "HI_SQUARE.h"
#include "SAMPLE.h"


#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ChyperdistDoc

IMPLEMENT_DYNCREATE(ChyperdistDoc, CDocument)

BEGIN_MESSAGE_MAP(ChyperdistDoc, CDocument)
	ON_COMMAND(ID_MODELING, &ChyperdistDoc::OnModeling)
END_MESSAGE_MAP()


// ChyperdistDoc construction/destruction

ChyperdistDoc::ChyperdistDoc() noexcept : par_a(3), par_b(3), par_k(2), sample_len(500), method(0), SPTR(0), CC(0)
{
	// TODO: add one-time construction code here
	modeling();
}

ChyperdistDoc::~ChyperdistDoc()
{
}

BOOL ChyperdistDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// ChyperdistDoc serialization

void ChyperdistDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void ChyperdistDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void ChyperdistDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void ChyperdistDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ChyperdistDoc diagnostics

#ifdef _DEBUG
void ChyperdistDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void ChyperdistDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ChyperdistDoc commands


void ChyperdistDoc::OnModeling()
{
	// TODO: добавьте свой код обработчика команд
	CModDlg dlg;
	dlg.m_a = par_a;
	dlg.m_b = par_b;
	dlg.m_k = par_k;
	dlg.m_len = sample_len;
	dlg.m_method = method;
	if (dlg.DoModal() == IDOK) {
		par_a = dlg.m_a;
		par_b = dlg.m_b;
		par_k = dlg.m_k;
		sample_len = dlg.m_len;
		method = dlg.m_method;
		UpdateAllViews(0);
		modeling();
	}
	
}


int* ChyperdistDoc::get_freq()
{
	return CC;
}


int ChyperdistDoc::get_k()
{
	return par_k;
}


int ChyperdistDoc::get_sample_len()
{
	return sample_len;
}


void ChyperdistDoc::modeling()
{
	DIST d(par_a, par_b, par_k);
	delete SPTR;
	if (!method) SPTR = new HGB();
	HI_SQUARE HS(&d, SPTR, sample_len);
	CC = HS.get_c();
}
