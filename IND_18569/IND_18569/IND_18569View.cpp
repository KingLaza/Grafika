
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

BOOL grid_flag = false;


// CIND18569View

IMPLEMENT_DYNCREATE(CIND18569View, CView)

BEGIN_MESSAGE_MAP(CIND18569View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CIND18569View construction/destruction

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

void CIND18569View::OnDraw(CDC* pDC)
{
	CIND18569Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	

	/*DrawRegularPolygon(pDC, 300, 300, 100, 4, 45);

	DrawIsoscelesTriangle(pDC, 300, 300, 250, 270);

	DrawParallelogram(pDC, 150, 150, 500, 0, 45);*/

	//I started drawing stuff here

	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	CBrush backgroundBrush(RGB(221, 221, 221));

	CBrush* OldBrushTemp;
	OldBrushTemp = pDC->SelectObject(&backgroundBrush);
	pDC->Rectangle(0, 0, width, height);
	pDC->SelectObject(OldBrushTemp); // Restore original pen




	POINT temp = { 0,0 };

	int bigLineSize = 6, smallLineSize = 3;
	//CBrush orange_brush 
	CBrush greenBrush(RGB(50, 205, 50));
	CBrush yellowBrush(RGB(255, 255, 0));
	CBrush redBrush(RGB(255, 0, 0));
	CBrush orangeBrush(RGB(255, 153, 51));
	CBrush purpleBrush(RGB(153, 0, 204));
	CBrush pinkBrush(RGB(255, 153, 204));
	CBrush grayBrush(RGB(221, 221, 221));
	CBrush stripedBrush(HS_BDIAGONAL, RGB(181, 206, 255));
	CBrush* pOldBrush;

	CPen* pOldPen;
	CPen bigPen(BS_SOLID, bigLineSize, RGB(255, 0, 0));
	CPen smallPen(BS_SOLID, smallLineSize, RGB(255, 0, 0));

	pOldPen = pDC->SelectObject(&bigPen);	//set pen
	pOldBrush = pDC->SelectObject(&orangeBrush);
	
	temp = DrawIsoscelesTriangle(pDC, 0, 0, 335, 0);	//orange
	pDC->SelectObject(pOldPen); // Restore original pen
	pDC->SelectObject(&smallPen);	//set pen
	DrawRegularPolygon(pDC, temp.x, temp.y, 50, 5, 0);	//orange
	pDC->SelectObject(pOldPen); // Restore original pen
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&bigPen);	//set pen
	pDC->SelectObject(&greenBrush);	//set
	DrawParallelogram(pDC, 170, 170, 500, 0, 45);		//green
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&redBrush);	//set
	temp = DrawIsoscelesTriangle(pDC, 500, 170, 170, 180);		//red
	pDC->SelectObject(pOldBrush);  // Restore

	//pDC->SelectObject(pOldBrush);  // Restore the original brush
	//pDC->SelectObject(pOldPen); // Restore original pen

	pDC->SelectObject(&grayBrush);	//set
	temp = DrawIsoscelesTriangle(pDC, 169, 331, 162, 180);	//gray
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&purpleBrush);	//set
	DrawRegularPolygon(pDC, 250, 250, 112, 4, 45);			//purple
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&grayBrush);	//set
	temp = DrawIsoscelesTriangle(pDC, 333, 173, 162, 0);	//gray
	pDC->SelectObject(pOldBrush);  // Restore


	pDC->SelectObject(&yellowBrush);	//set
	temp = DrawIsoscelesTriangle(pDC, 0, 500, 167, 90);		//yellow
	pDC->SelectObject(&smallPen);	//set pen
	DrawRegularPolygon(pDC, temp.x, temp.y, 26, 8, 0);		//yellow
	pDC->SelectObject(&bigPen);	//set pen
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&stripedBrush);	//set //here, I need the striped one
	temp = DrawIsoscelesTriangle(pDC, 170, 500, 235, 135);	//striped
	pDC->SelectObject(&smallPen);	//set pen
	DrawRegularPolygon(pDC, temp.x, temp.y, 35, 4, 0);		//striped
	pDC->SelectObject(&bigPen);	//set pen
	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(&pinkBrush);	//set
	temp = DrawIsoscelesTriangle(pDC, 500, 500, 327, 180);	//pink
	pDC->SelectObject(&smallPen);	//set pen
	DrawRegularPolygon(pDC, temp.x, temp.y, 50, 7, 0);		//pink

	pDC->SelectObject(pOldBrush);  // Restore
	pDC->SelectObject(pOldPen); // Restore original pen
	//pDC->SelectObject(pOldBrush);  // Restore the original brush

	if (grid_flag) {
		draw_grid(pDC, RGB(255, 255, 255), { 4,4 });
	}


}

void CIND18569View::DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle) {
	
	std::vector<POINT> skup_tacaka;
	rotAngle *= M_PI / 180;
	double angle = (2*M_PI) / n;

	for (int i = 0; i < n; i++) {
		skup_tacaka.push_back({ cx + static_cast<int>(r * cos(angle * i + rotAngle)), cy + static_cast<int> (r * sin(angle * i + rotAngle)) });
	}

	pDC->Polygon(skup_tacaka.data(), skup_tacaka.size());

}

POINT CIND18569View::DrawIsoscelesTriangle(CDC* pDC, int cx, int cy, int katetaLength, float rotationAngle) {

	float angle = rotationAngle * M_PI / 180;
	int tempX = cx + katetaLength;
	int tempY = cy + katetaLength;

	//t, general case
	std::vector<POINT> tacke = { {cx, cy}, {cx + katetaLength, cy}, {cx, cy + katetaLength} };
	POINT t = {0,0};
	for (auto p : tacke) {
		t.x += p.x;
		t.y += p.y;
	}
	t.x /= 3;				//moze i sa size, ali necu >:)	:3
	t.y /= 3;

	for (auto& p : tacke) {
		p.x -= t.x;
		p.y -= t.y;
		int realX = static_cast<int>(p.x * cos(angle) + p.y * sin(angle));
		int realY = static_cast<int>(-p.x * sin(angle) + p.y * cos(angle));
		p.x = realX + t.x;
		p.y = realY + t.y;
	}

	//shiftovanje trougla na adekvatne pozicije posle rotacije
	int shiftX = cx - tacke[0].x;
	int shiftY = cy - tacke[0].y;
	tacke[0].x = cx;
	tacke[0].y = cy;
	tacke[1].x += shiftX;
	tacke[1].y += shiftY;
	tacke[2].x += shiftX;
	tacke[2].y += shiftY;

	pDC->Polygon(tacke.data(), tacke.size());

	t = { 0,0 };
	for (auto p : tacke) {
		t.x += p.x;
		t.y += p.y;
	}
	t.x /= 3;				//moze i sa size, ali necu >:)	:3
	t.y /= 3;

	return t;

}

POINT CIND18569View::DrawParallelogram(CDC* pDC, int x1, int y1, int x2, int y2, float angle) {

	if (x2 < x1) {			//only to check if you mixed these up
		int temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1; 
		y1 = y2;
		y2 = temp;
	}
	float ratio = tan(angle*M_PI / 180);
	float excess = static_cast<float>(abs(y2 - y1)) / ratio;
	POINT p3 = { x2 - excess, y1 };
	POINT p4 = { x1 + excess, y2 };

	std::vector<POINT> tacke = { {x1,y1},p3, {x2,y2}, p4 };

	pDC->Polygon(tacke.data(), tacke.size());

	POINT t = {0,0};

	for (auto p : tacke) {
		t.x += p.x;
		t.y += p.y;
	}
	t.x /= 4;
	t.y /= 4;

	return t;

}



//grid stuff
void CIND18569View::draw_grid(CDC* pDC, COLORREF color, POINT origin) {
	CBrush grid_brush(HS_CROSS, color);

	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	auto old_pen = pDC->SelectObject(&grid_brush);

	pDC->SetBkMode(TRANSPARENT);

	pDC->SetBrushOrg(origin);

	pDC->Rectangle(0, 0, width, height);

	pDC->SelectObject(old_pen);

	pDC->SetBrushOrg(0, 0);

	pDC->SetBkMode(OPAQUE);
}

BOOL CIND18569View::PreTranslateMessage(MSG* pMsg) {
	if (pMsg->message == WM_KEYDOWN) // Check for key down message
	{
		switch (pMsg->wParam) // Check the key code
		{
		case 'D': // Check if the 'D' key is pressed
			// Handle 'G' key press here
			grid_flag = !grid_flag;
			Invalidate();
			return TRUE; // Return TRUE to indicate it was handled
		case 'd':
			grid_flag = !grid_flag;
			Invalidate();
			return TRUE;
		}

	}
	return CView::PreTranslateMessage(pMsg);
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
