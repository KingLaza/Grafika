
// Grafika_lab_02View.h : interface of the CGrafikalab02View class
//

#pragma once

#define _USE_MATH_DEFINES

class CGrafikalab02View : public CView
{
protected: // create from serialization only
	CGrafikalab02View() noexcept;
	DECLARE_DYNCREATE(CGrafikalab02View)

// Attributes
public:
	CGrafikalab02Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	void drawFigure(CDC* pDC);
	void drawCactus(CDC* pDC, HENHMETAFILE hMetaFile, POINT middlePoint);
	void drawPot(CDC* pDC, COLORREF color);
	void drawCircle(CDC* pDC, POINT p);
	void Translate(CDC* pDC, float Dx, float Dy, bool rightMultiply);
	void Scale(CDC* pDC, float Scalex, float Scaley, bool rightMultiply);
	void Rotate(CDC* pDC, float angle, bool rightMultiply);
	void drawGrid(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CGrafikalab02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in Grafika_lab_02View.cpp
inline CGrafikalab02Doc* CGrafikalab02View::GetDocument() const
   { return reinterpret_cast<CGrafikalab02Doc*>(m_pDocument); }
#endif

