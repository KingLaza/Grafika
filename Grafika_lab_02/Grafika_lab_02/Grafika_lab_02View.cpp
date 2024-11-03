
// Grafika_lab_02View.cpp : implementation of the CGrafikalab02View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Grafika_lab_02.h"
#endif

#include "Grafika_lab_02Doc.h"
#include "Grafika_lab_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <vector>
#include <stdio.h>
#include <iostream>



// CGrafikalab02View
float rotationAngle = 0.0f;
float smallerRotationAngle = 0.0f;
POINT rotationPointMinus = { -250, -425 };		//first you need - then +
POINT rotationPointPlus = { 250, 425 };
POINT smallerRotationPointMinus = { -302, -297};
POINT smallerRotationPointPlus = { 302, 297};
struct floatPoint {
	float x;
	float y;
};
floatPoint fatCactus = { 0.6f, 0.75f };
floatPoint regularCactus = { 0.4f, 0.75f};
floatPoint slimCactus = { 0.2f, 0.75f };	//the slim reaper
bool drawGridFlag = false;


IMPLEMENT_DYNCREATE(CGrafikalab02View, CView)

BEGIN_MESSAGE_MAP(CGrafikalab02View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CGrafikalab02View construction/destruction

CGrafikalab02View::CGrafikalab02View() noexcept
{
	// TODO: add construction code here

}

CGrafikalab02View::~CGrafikalab02View()
{
}

BOOL CGrafikalab02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGrafikalab02View drawing

void CGrafikalab02View::OnDraw(CDC* pDC)
{
	CGrafikalab02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//background drawing
	CBrush backgroundBrush(RGB(135, 206, 235));
	CBrush* OldBrushTemp;
	OldBrushTemp = pDC->SelectObject(&backgroundBrush);
	pDC->Rectangle(0, 0, 500, 500);
	pDC->SelectObject(OldBrushTemp); // Restore original pen
	
	drawFigure(pDC);

	//pot
	drawPot(pDC, RGB(222, 148, 0));
	//grid
	if (drawGridFlag)
		drawGrid(pDC);
	
}

//this method will use the global attributes to draw a cactus
//when there is a change, Invalidate() will be called and this function
//will draw a new cactus with modified attributes
void CGrafikalab02View::drawFigure(CDC* pDC) {
	//metafajlovi 
	CString EMFnameLight = _T("cactus_part_light.emf");
	CString EMFnameRegular = _T("cactus_part.emf");
	HENHMETAFILE hMetaFileLight = GetEnhMetaFile(EMFnameLight);
	HENHMETAFILE hMetaFileRegular = GetEnhMetaFile(EMFnameRegular);
	int old_mode = pDC->SetGraphicsMode(GM_ADVANCED);
	XFORM oldTransform;
	pDC->GetWorldTransform(&oldTransform);

	//and here we begin folks!	~~~

	Scale(pDC, fatCactus.x, fatCactus.y, true);
	Translate(pDC, 220, 349, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileLight, CRect(0, 0, 100, 100)); // Play the metafile relative to the origin
	pDC->SetWorldTransform(&oldTransform);

	//center of their circle
	POINT circle1 = { 250, 350 };

	Scale(pDC, slimCactus.x, slimCactus.y, true);		//tanki
	Translate(pDC, 240, 275, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, slimCactus.x, slimCactus.y, true);		//levi tanki
	Translate(pDC, 240, 275, true);
	Translate(pDC, -circle1.x, -circle1.y, true);
	Rotate(pDC, -45, true);
	Translate(pDC, circle1.x, circle1.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, slimCactus.x, slimCactus.y, true);		//desni tanki
	Translate(pDC, 240, 275, true);
	Translate(pDC, -circle1.x, -circle1.y, true);
	Rotate(pDC, 45, true);
	Translate(pDC, circle1.x, circle1.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	POINT circle2 = { 197, 298 };					//normalan
	Scale(pDC, regularCactus.x, regularCactus.y, true);
	Translate(pDC, 177, 222, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, regularCactus.x, regularCactus.y, true);		//levi normalan
	Translate(pDC, 177, 222, true);
	Translate(pDC, -circle2.x, -circle2.y, true);
	Rotate(pDC, -90, true);
	Translate(pDC, circle2.x, circle2.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	POINT circle3 = { 303, 297 };					//normalan (light)
	Scale(pDC, regularCactus.x, regularCactus.y, true);
	Translate(pDC, 283, 222, true);
	Translate(pDC, -circle3.x, -circle3.y, true);
	Rotate(pDC, smallerRotationAngle, true);
	Translate(pDC, circle3.x, circle3.y, true);	
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileLight, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, regularCactus.x, regularCactus.y, true);		//normalan right
	Translate(pDC, 283, 222, true);
	Translate(pDC, -circle3.x, -circle3.y, true);
	Rotate(pDC, 90, true);
	Translate(pDC, circle3.x, circle3.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	POINT circle4 = { 377, 297 };					//normalan gore desno
	Scale(pDC, regularCactus.x, regularCactus.y, true);
	Translate(pDC, 357, 222, true);
	Translate(pDC, -circle4.x, -circle4.y, true);
	Rotate(pDC, 45, true);
	Translate(pDC, circle4.x, circle4.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, regularCactus.x, regularCactus.y, true);		//normalan dole levo
	Translate(pDC, 357, 222, true);
	Translate(pDC, -circle4.x, -circle4.y, true);
	Rotate(pDC, 135, true);
	Translate(pDC, circle4.x, circle4.y, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	Scale(pDC, fatCactus.x, fatCactus.y, true);		//debeo na vrhu
	Translate(pDC, 167, 147, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	pDC->PlayMetaFile(hMetaFileRegular, CRect(0, 0, 100, 100));
	pDC->SetWorldTransform(&oldTransform);

	// Delete metafiles
	DeleteEnhMetaFile(hMetaFileLight);
	DeleteEnhMetaFile(hMetaFileRegular);

	//old_mode = pDC->SetGraphicsMode(old_mode);

	//~~~
	//circles, I guess circles need to be at the very end because
	//of the overlay, they need to fold over the cacti
	
	drawCircle(pDC, { 250, 435 });

	//old_mode = pDC->SetGraphicsMode(GM_ADVANCED);
	pDC->GetWorldTransform(&oldTransform);
	Translate(pDC, 250, 360, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	drawCircle(pDC, { 0,0 });
	pDC->SetWorldTransform(&oldTransform);

	pDC->GetWorldTransform(&oldTransform);
	Translate(pDC, 197, 308, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	drawCircle(pDC, { 0,0 });
	pDC->SetWorldTransform(&oldTransform);

	pDC->GetWorldTransform(&oldTransform);
	Translate(pDC, 303, 308, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	drawCircle(pDC, { 0,0 });
	pDC->SetWorldTransform(&oldTransform);

	pDC->GetWorldTransform(&oldTransform);
	Translate(pDC, 378, 307, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	drawCircle(pDC, { 0,0 });
	pDC->SetWorldTransform(&oldTransform);

	pDC->GetWorldTransform(&oldTransform);
	Translate(pDC, 197, 232, true);
	Translate(pDC, rotationPointMinus.x, rotationPointMinus.y, true);
	Rotate(pDC, rotationAngle, true);
	Translate(pDC, rotationPointPlus.x, rotationPointPlus.y, true);
	drawCircle(pDC, { 0,0 });
	pDC->SetWorldTransform(&oldTransform);

	old_mode = pDC->SetGraphicsMode(old_mode);
	
}




void CGrafikalab02View::drawCactus(CDC* pDC, HENHMETAFILE hMetaFile, POINT middlePoint) {
	//75 sam stavio da su dimenzije kaktusa, treba samo da se promeni
	//x dimenzija (debljina), visina je svima ista
	POINT p = middlePoint;
	pDC->PlayMetaFile(hMetaFile, CRect(p.x - 37.5, p.y + 10, p.x + 37.5, p.y - 75 + 10));
}

//222,148,0
void CGrafikalab02View::drawPot(CDC* pDC, COLORREF color) {
	//bottom 250,500; left - 210, right - 290; 450y
	// 200, 450 / 300, 450
	//190, 450; 190, 430 / 310, 450;  310, 430
	std::vector<POINT> dots;
	dots.push_back({210, 500});
	dots.push_back({ 290, 500 });
	dots.push_back({ 300, 450 });
	dots.push_back({ 200, 450 });
	CBrush* old;
	CBrush nova(color);
	old = pDC->SelectObject(&nova);
	pDC->Polygon(dots.data(), dots.size());
	dots.clear();
	dots.push_back({ 190,450 });
	dots.push_back({ 310,450 });
	dots.push_back({ 310,430 });
	dots.push_back({ 190,430 });
	pDC->Polygon(dots.data(), dots.size());

	pDC->SelectObject(old);
}

void CGrafikalab02View::drawCircle(CDC* pDC, POINT p) {

	CBrush* old;
	CBrush nova(RGB(0,204,0));
	old = pDC->SelectObject(&nova);
	pDC->Ellipse(p.x - 10, p.y, p.x + 10, p.y - 20);
	pDC->SelectObject(old);

}

void CGrafikalab02View::Translate(CDC* pDC, float Dx, float Dy, bool rightMultiply) {
	XFORM Xform;

	Xform.eM11 = (FLOAT)1.0;
	Xform.eM12 = (FLOAT)0.0;
	Xform.eM21 = (FLOAT)0.0;
	Xform.eM22 = (FLOAT)1.0;
	Xform.eDx = (FLOAT)Dx;
	Xform.eDy = (FLOAT)Dy;

	if (rightMultiply)
		pDC->ModifyWorldTransform(&Xform, MWT_RIGHTMULTIPLY);
	else 
		pDC->ModifyWorldTransform(&Xform, MWT_LEFTMULTIPLY);	
}

void CGrafikalab02View::Scale(CDC* pDC, float Scalex, float Scaley, bool rightMultiply) {
	XFORM Xform;

	Xform.eM11 = (FLOAT)Scalex;
	Xform.eM12 = (FLOAT)0.0;
	Xform.eM21 = (FLOAT)0.0;
	Xform.eM22 = (FLOAT)Scaley;
	Xform.eDx = (FLOAT)0.0;
	Xform.eDy = (FLOAT)0.0;

	if (rightMultiply)
		pDC->ModifyWorldTransform(&Xform, MWT_RIGHTMULTIPLY);
	else
		pDC->ModifyWorldTransform(&Xform, MWT_LEFTMULTIPLY);
}

void CGrafikalab02View::Rotate(CDC* pDC, float angle, bool rightMultiply) {
	XFORM Xform;
	//float radians = angle * (M_PI/180.0f);
	float radians = angle * (3.14159265358979f / 180.0f);


	Xform.eM11 = cos(radians);
	Xform.eM12 = sin(radians);
	Xform.eM21 = -sin(radians);
	Xform.eM22 = cos(radians);
	Xform.eDx = (FLOAT)0.0;
	Xform.eDy = (FLOAT)0.0;

	if (rightMultiply)
		pDC->ModifyWorldTransform(&Xform, MWT_RIGHTMULTIPLY);
	else
		pDC->ModifyWorldTransform(&Xform, MWT_LEFTMULTIPLY);
}

void CGrafikalab02View::drawGrid(CDC* pDC) {
	CPen* OldPen;
	CPen gridPen(BS_SOLID, 1, RGB(255, 255, 255));
	OldPen = pDC->SelectObject(&gridPen);
	//20 squares, each with a 25 pixels side length
	for (int i = 0; i <= 500 / 25; i++) {
		pDC->MoveTo(25 * i, 0);
		pDC->LineTo(25 * i, 500);
	}
	for (int i = 0; i <= 500 / 25; i++) {
		pDC->MoveTo(0, 25 * i);
		pDC->LineTo(500, 25 * i);
	}
	pDC->SelectObject(OldPen);
}


// CGrafikalab02View printing

BOOL CGrafikalab02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGrafikalab02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGrafikalab02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGrafikalab02View diagnostics

#ifdef _DEBUG
void CGrafikalab02View::AssertValid() const
{
	CView::AssertValid();
}

void CGrafikalab02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGrafikalab02Doc* CGrafikalab02View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafikalab02Doc)));
	return (CGrafikalab02Doc*)m_pDocument;
}
#endif //_DEBUG


// CGrafikalab02View message handlers


void CGrafikalab02View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_LEFT:
		rotationAngle -= 6.0f;
		break;
	case VK_RIGHT:
		rotationAngle += 6.0f;
		break;
	case 0x51:		//Q, VK_KEY_Q doesn't work
		smallerRotationAngle -= 6.0f;
		break;
	case 0x45:		//E
		smallerRotationAngle += 6.0f;
		break;
	case 0x47:		//G
		drawGridFlag = !drawGridFlag;
		break;
	}
	Invalidate();
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


