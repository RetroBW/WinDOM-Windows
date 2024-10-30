#include "stdafx.h"

#include <stdlib.h>
#include <time.h>

#include "offset.h"
#include "dom.h"

Dom::Dom()
{
	//get screen size
	ScreenSize.left = 0;
	ScreenSize.right = GetSystemMetrics(SM_CXSCREEN);
	ScreenSize.top = 0;
	ScreenSize.bottom = GetSystemMetrics(SM_CYSCREEN);

	//seed random number generator
	srand( (unsigned)time( NULL ) );
    
	WinColors[0] = RGB(255,0,0);
	WinColors[1] = RGB(255,255,0);
	WinColors[2] = RGB(0,0,255);
	WinColors[3] = RGB(255,0,255);
	WinColors[4] = RGB(0,255,255);
	WinColors[5] = RGB(0,255,0);
	WinColors[6] = RGB(255,255,255);
	WinColors[7] = RGB(164,200,240);
	WinColors[8] = RGB(64,0,128);
	WinColors[9] = RGB(128,64,0);
	
	WinBackColor = RGB(192,192,192);
}

Dom::~Dom()
{
}

void Dom::InitpWnd(CWnd* pInitWnd)
{
	pWnd = pInitWnd;
}

void Dom::InitDom(int PreviewOn)
{
	//init Dom position
	x = 4;
	y = 2;

	//check that DomPreColor has valid colors
	if(DomPreColor[0] < 0 || DomPreColor[1] < 0 || DomPreColor[2] < 0 ||
	   DomPreColor[0] > num_color || DomPreColor[1] > num_color || DomPreColor[2] > num_color) {
	
		//init PreDom colors
		for(int i = 0; i < 3; i++)
			DomPreColor[i] = rand() % num_color;
	}

	//init Dom colors
	for(int i = 0; i < 3; i++) {
		DomColor[i] = DomPreColor[i];
		DomPreColor[i] = rand() % num_color;
	}
	
	DrawDom(PreviewOn);
}

void Dom::DrawDom(int PreviewOn)
{
	DisplayDom(x, y-2, WinColors[DomColor[0]]);
	DisplayDom(x, y-1, WinColors[DomColor[1]]);
	DisplayDom(x, y, WinColors[DomColor[2]]);
	
	if(PreviewOn) DrawPreDom();
}

void Dom::DrawPreDom()
{
	DisplayDom(-2, 0, WinColors[DomPreColor[0]]);
	DisplayDom(-2, 1, WinColors[DomPreColor[1]]);
	DisplayDom(-2, 2, WinColors[DomPreColor[2]]);
}

void Dom::LeftDom()
{
	if(x > 0)
	{	EraseDom(x, y-2);
		EraseDom(x, y-1);
		EraseDom(x, y);

		x--;
		DrawDom(0);
	}
}

void Dom::RightDom()
{
	if(x < 9)
	{	EraseDom(x, y-2);
		EraseDom(x, y-1);
		EraseDom(x, y);

		x++;
		DrawDom(0);
	}
}

void Dom::DownDom()
{
	if(y < 19)
	{	EraseDom(x, y - 2);

		y++;
		DrawDom(0);
	}
}

void Dom::DropDom(int height)
{
	if(y < 19)
	{	EraseDom(x, y - 2);
		EraseDom(x, y - 1);
		EraseDom(x, y);

		y = height;
		DrawDom(0);
	}
}

void Dom::RotateDom()
{
	int TempColor;

	TempColor = DomColor[0];
	DomColor[0] = DomColor[1];
	DomColor[1] = DomColor[2];
	DomColor[2] = TempColor;

	DrawDom(0);
}

void Dom::EraseDom(int cur_x, int cur_y)
{
	DisplayDom(cur_x, cur_y, WinBackColor);
}

void Dom::DisplayDom(int cur_x, int cur_y, COLORREF DisplayDomColor)
{
	RECT DisplayDomRect;

	CClientDC dc(pWnd);
	
	//calculate rectangle coordinates
	DisplayDomRect.top = (cur_y * 20) + Y_OFFSET + 1;
	DisplayDomRect.left = (cur_x * 20) + X_OFFSET + 1;
	DisplayDomRect.bottom = DisplayDomRect.top + 19;
	DisplayDomRect.right = DisplayDomRect.left + 19;

	//draw dom segment (square)
	DrawBrush.CreateSolidBrush (DisplayDomColor);
	dc.FillRect(&DisplayDomRect, &DrawBrush);
	DrawBrush.DeleteObject();
}
