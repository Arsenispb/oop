
// hyperdistDoc.h : interface of the ChyperdistDoc class
//


#pragma once

#include "SAMPLE.h"

class ChyperdistDoc : public CDocument
{
protected: // create from serialization only
	ChyperdistDoc() noexcept;
	DECLARE_DYNCREATE(ChyperdistDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~ChyperdistDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnModeling();
	int par_a;
	int par_b;
	int par_k;
	int sample_len;
	int method;
	SAMPLE* SPTR;
	int* CC;
	int* get_freq();
	int get_k();
	int get_sample_len();
	void modeling();
};
