
// IND_18569View.h : interface of the CIND18569View class
//

#pragma once
#include "../../../git grafika/Grafika/additional shit/DImage/DImage.h"


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
	void DrawImagePart(CDC* pDC, const CString& imagePath, double rotationAngle, const CPoint& translate1, const CPoint& translate2, bool mirrorX, bool mirrorY, bool blue_filter, CRect& rect, COLORREF color);
	void Translate(CDC* pDC, float Dx, float Dy, bool rightMultiply);
	void Scale(CDC* pDC, float Scalex, float Scaley, bool rightMultiply);
	void Rotate(CDC* pDC, float angle, bool rightMultiply);
	void Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply);
	void drawGrid(CDC* pDC);
	void DrawTransparentImage(DImage& dImage, CDC* pDC, CRect& rcImg, CRect& rcDC, COLORREF& cTrans, const bool& blue_filter);
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

