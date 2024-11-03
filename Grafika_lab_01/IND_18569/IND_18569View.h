
// IND_18569View.h : interface of the CIND18569View class
//

#pragma once

#define _USE_MATH_DEFINES

#include <vector>
#include <math.h>



class CIND18569View : public CView
{
protected: // create from serialization only
	CIND18569View() noexcept;
	DECLARE_DYNCREATE(CIND18569View)

// Attributes
public:
	CIND18569Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle);
	POINT DrawIsoscelesTriangle(CDC* pDC, int cx, int cy, int katetaLength, float rotationAngle);
	POINT DrawParallelogram(CDC* pDC, int x1, int y1, int x2, int y2, float angle);
	void draw_grid(CDC* pDC, COLORREF color, POINT origin);
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CIND18569View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IND_18569View.cpp
inline CIND18569Doc* CIND18569View::GetDocument() const
   { return reinterpret_cast<CIND18569Doc*>(m_pDocument); }
#endif

