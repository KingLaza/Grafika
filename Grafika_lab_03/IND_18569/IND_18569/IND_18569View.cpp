
// IND_18569View.cpp : implementation of the CIND18569View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IND_18569.h"
#endif

#include "IND_18569Doc.h"
#include "IND_18569View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "../../../git grafika/Grafika/additional shit/DImage/DImage.h"
#include <vector>


// CIND18569View

IMPLEMENT_DYNCREATE(CIND18569View, CView)

BEGIN_MESSAGE_MAP(CIND18569View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CIND18569View construction/destruction

//struct ImagePart {
//	CString imagePath;
//	double rotationAngle;   // Rotation angle
//	CPoint translate1;      // First translation
//	CPoint translate2;      // Second translation
//	bool mirrorX;           // Mirror along X-axis
//	bool mirrorY;           // Mirror along Y-axis
//	bool blue_filter = false;
//};
//
//std::vector<ImagePart> imageParts = {
//	{_T("res\\MonaLisa00.bmp"), 109, {-80, -235}, {20, 170}, true, false},
//	{_T("res\\MonaLisa01.bmp"), 17, {-33, -100}, {326, 34}, false, true},
//	{_T("res\\MonaLisa02.bmp"), 115, {-27, -100}, {321, 22}, false, true},
//	{_T("res\\MonaLisa10.bmp"), 203, {-165, -37}, {23, 165}, true, false, true},
//	{_T("res\\MonaLisa11.bmp"), -32, {-100, -33}, {323, 167}, false, true},
//	{_T("res\\MonaLisa12.bmp"), 145, {-140, -240}, {466, 165}, false, true},
//	{_T("res\\MonaLisa20.bmp"), 71, {-170, -230}, {173, 464}, false, true},
//	{_T("res\\MonaLisa21.bmp"), -18, {-76, -41}, {323, 315}, false, true},
//	{_T("res\\MonaLisa22.bmp"), 14, {-215, -189}, {468, 317}, true, false},
//};

float center_rot_angle = -90;
const CPoint rot_center = { 250, 250 };
bool right_mult = true;
bool first_time = true;
std::vector<std::vector<DImage>> puzzle_parts;
const int cols = 3;
const int rows = 3;

CIND18569View::CIND18569View() noexcept
{
	// TODO: add construction code here

}

CIND18569View::~CIND18569View()
{
}

BOOL CIND18569View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIND18569View drawing

//void CIND18569View::OnDraw(CDC* pDC)
//{
//	CIND18569Doc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
//	if (!pDoc)
//		return;
//
//	// TODO: add draw code for native data here 
//
//	COLORREF color(RGB(0, 255, 0));
//	CRect rect(0, 0, 256, 256);
//	CRect img_rect(0, 0, 500, 500);
//	CDC memDC;
//	if (!memDC.CreateCompatibleDC(pDC))
//		return;
//
//	CBitmap memBitmap;
//	memBitmap.CreateCompatibleBitmap(pDC, img_rect.Width(), img_rect.Height());
//	memDC.SelectObject(&memBitmap);
//
//	memDC.FillSolidRect(0, 0, img_rect.Width(), img_rect.Height(), RGB(255, 255, 255));
//
//	auto old_mode = memDC.SetGraphicsMode(GM_ADVANCED);
//	XFORM old_transform;
//	memDC.GetWorldTransform(&old_transform);
//
//
//	for (const auto& part : imageParts) {
//		Translate(&memDC, part.translate1.x, part.translate1.y, true);
//		Rotate(&memDC, part.rotationAngle, true);
//		Mirror(&memDC, part.mirrorX, part.mirrorY, true);
//		Translate(&memDC, part.translate2.x, part.translate2.y, true);
//
//		if (center_rot_angle) {
//			Translate(&memDC, -rot_center.x, -rot_center.y, true);
//			Rotate(&memDC, center_rot_angle, true);
//			Translate(&memDC, rot_center.x, rot_center.y, true);
//		}
//
//		DImage image;
//		image.Load(part.imagePath);
//		DrawTransparentImage(image, &memDC, rect, rect, color, part.blue_filter);
//
//		memDC.SetWorldTransform(&old_transform);
//	}
//
//	pDC->BitBlt(0, 0, 500, 500, &memDC, 0, 0, SRCCOPY);
//
//	memDC.SetGraphicsMode(old_mode);
//	memDC.DeleteDC();
//
//}
void CIND18569View::OnDraw(CDC* pDC)
{
	CIND18569Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	COLORREF color(RGB(0, 255, 0));
	CRect rect(0, 0, 256, 256);
	CRect img_rect(0, 0, 500, 500);
	CDC memDC;
	if (!memDC.CreateCompatibleDC(pDC))
		return;

	CBitmap memBitmap;
	memBitmap.CreateCompatibleBitmap(pDC, img_rect.Width(), img_rect.Height());
	memDC.SelectObject(&memBitmap);

	memDC.FillSolidRect(0, 0, img_rect.Width(), img_rect.Height(), RGB(255, 255, 255));

	auto old_mode = memDC.SetGraphicsMode(GM_ADVANCED);
	XFORM old_transform;
	memDC.GetWorldTransform(&old_transform);

	// Crtanje svake slike ponaosob
	DrawImagePart(&memDC, _T("res\\MonaLisa00.bmp"), 109, { -80, -235 }, { 20, 170 }, true, false, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa01.bmp"), 17, { -33, -100 }, { 326, 34 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa02.bmp"), 115, { -27, -100 }, { 321, 22 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa10.bmp"), 203, { -165, -37 }, { 23, 165 }, true, false, true, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa11.bmp"), -32, { -100, -33 }, { 323, 167 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa12.bmp"), 145, { -140, -240 }, { 466, 165 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa20.bmp"), 71, { -170, -230 }, { 173, 464 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa21.bmp"), -18, { -76, -41 }, { 323, 315 }, false, true, false, rect, color);
	DrawImagePart(&memDC, _T("res\\MonaLisa22.bmp"), 14, { -215, -189 }, { 468, 317 }, true, false, false, rect, color);

	pDC->BitBlt(0, 0, 500, 500, &memDC, 0, 0, SRCCOPY);

	memDC.SetGraphicsMode(old_mode);
	memDC.DeleteDC();
}

void CIND18569View::DrawImagePart(CDC* pDC, const CString& imagePath, double rotationAngle, const CPoint& translate1,
	const CPoint& translate2, bool mirrorX, bool mirrorY, bool blue_filter,
	CRect& rect, COLORREF color)
{
	XFORM old_transform;
	pDC->GetWorldTransform(&old_transform);

	Translate(pDC, translate1.x, translate1.y, true);
	Rotate(pDC, rotationAngle, true);
	Mirror(pDC, mirrorX, mirrorY, true);
	Translate(pDC, translate2.x, translate2.y, true);

	if (center_rot_angle) {
		Translate(pDC, -rot_center.x, -rot_center.y, true);
		Rotate(pDC, center_rot_angle, true);
		Translate(pDC, rot_center.x, rot_center.y, true);
	}

	DImage image;
	image.Load(imagePath);
	DrawTransparentImage(image, pDC, rect, rect, color, blue_filter);

	pDC->SetWorldTransform(&old_transform);
}

void CIND18569View::Translate(CDC* pDC, float Dx, float Dy, bool rightMultiply) {
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

void CIND18569View::Scale(CDC* pDC, float Scalex, float Scaley, bool rightMultiply) {
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

void CIND18569View::Rotate(CDC* pDC, float angle, bool rightMultiply) {
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

void CIND18569View::Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply) {
	XFORM Xform;

	Xform.eM11 = mx ? 1 : -1;
	Xform.eM12 = 0;
	Xform.eM21 = 0;
	Xform.eM22 = my ? 1 : -1;
	Xform.eDx = 0;
	Xform.eDy = 0;

	if (rightMultiply)
		pDC->ModifyWorldTransform(&Xform, MWT_RIGHTMULTIPLY);
	else
		pDC->ModifyWorldTransform(&Xform, MWT_LEFTMULTIPLY);
}

void CIND18569View::drawGrid(CDC* pDC) {
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

//main stuff

void CIND18569View::DrawTransparentImage(DImage& dImage, CDC* pDC, CRect& rcImg, CRect& rcDC, COLORREF& cTrans, const bool& blue_filter) {
	
	CBitmap* pBitmap = dImage.GetBitmap();
	if (!pBitmap) {
		return;
	}

	BITMAP bmp;
	pBitmap->GetBitmap(&bmp);

	int dataSize = bmp.bmWidthBytes * bmp.bmHeight;

	std::vector<BYTE> bitmapData(dataSize);

	if (pBitmap->GetBitmapBits(dataSize, bitmapData.data()) == 0) {
		return;
	}

	for (int y = 0; y < bmp.bmHeight; ++y) {
		for (int x = 0; x < bmp.bmWidth; ++x) {
			int pixelOffset = y * bmp.bmWidthBytes + x * (bmp.bmBitsPixel / 8);

			BYTE blue = bitmapData[pixelOffset];
			BYTE green = bitmapData[pixelOffset + 1];
			BYTE red = bitmapData[pixelOffset + 2];

			COLORREF color = RGB(red, green, blue);

			if (color != cTrans) {
				int newRed = 0, newGreen = 0, newBlue = 0;

				if (blue_filter) {
					newBlue = 64 + blue;
					newBlue = newBlue > 255 ? 255 : newBlue;
				}
				else {
					auto gray = 64 + (red + green + blue) / 3;
					gray = gray > 255 ? 255 : gray;
					newRed = newGreen = newBlue = gray;
				}

				// Set the new pixel color
				bitmapData[pixelOffset] = newBlue;
				bitmapData[pixelOffset + 1] = newGreen;
				bitmapData[pixelOffset + 2] = newRed;
			}
		}
	}

	// Set the modified bits back to the bitmap
	if (pBitmap->SetBitmapBits(dataSize, bitmapData.data()) == 0) {
		return; // Failed to set bitmap bits
	}

	// Create a memory DC for the bitmap
	CDC memDC;
	if (!memDC.CreateCompatibleDC(pDC)) {
		return; // Failed to create compatible DC
	}

	// Select the bitmap into the memory DC
	CBitmap* pOldBitmap = memDC.SelectObject(pBitmap);


	pDC->SetStretchBltMode(HALFTONE); // Smooth the bitmap during stretching


	pDC->TransparentBlt(rcDC.left, rcDC.top,
		rcDC.Width(), rcDC.Height(),
		&memDC, rcImg.left, rcImg.top,
		rcImg.Width(), rcImg.Height(),
		cTrans);

	// Restore the old bitmap in the memory DC
	memDC.SelectObject(pOldBitmap);
}



// CIND18569View printing

BOOL CIND18569View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIND18569View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIND18569View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIND18569View diagnostics

#ifdef _DEBUG
void CIND18569View::AssertValid() const
{
	CView::AssertValid();
}

void CIND18569View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIND18569Doc* CIND18569View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIND18569Doc)));
	return (CIND18569Doc*)m_pDocument;
}
#endif //_DEBUG


// CIND18569View message handlers
