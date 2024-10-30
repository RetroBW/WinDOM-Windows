#include "stdafx.h"

#include <string.h>
#include <stdlib.h>

#include "border.h"

#include "offset.h"

Border::Border()
{
	ScreenColor = RGB(0,0,255);		//blue
	BackColor = RGB(192,192,192);	//light grey
	ForeColor = RGB(255,255,255);	//white
	ShadowColor = RGB(128,128,128);	//dark grey
	WindowColor = RGB(192,192,192);	//light grey
	HiTextColor = RGB(255,0,0);		//red
	TextColor = RGB(0,0,0);			//black

	prev_score[0] = '\0';		//init score and number of colors
	prev_color[0] = '\0';
	score = 0;
	color = 3;
}

void Border::InitBorder(RECT ClientRect)
{
	WindowRect = ClientRect;
    
    InitBorder();
}

void Border::InitBorder()
{
	for(int i = 0; i < 10; i++)
	{	hi_score[i] = 0;
		hi_name[i][0] = '\0';
	}

	Outside();	//draw borders and windows
	Window();

	Title();
	ScoreBox();
	Score();
	ColorBox();
	Color();
	if(REGISTERED) PreDomBox();
}

void Border::InitpWnd(CWnd* pInitWnd)
{
	pWnd = pInitWnd;
}

void Border::Outside()
{
	CClientDC dc(pWnd);
	
	//select black pen for outlining
	DrawPen.CreatePen(PS_SOLID, 1, ShadowColor);
	OrigPen = dc.SelectObject(&DrawPen);
	
	//fill screen with screen background color
	DrawBrush.CreateSolidBrush (ScreenColor);
	dc.FillRect(&WindowRect, &DrawBrush);
	DrawBrush.DeleteObject();
	
	//draw outer border, fill border with color
	dc.MoveTo( WindowRect.left + 10, WindowRect.top + 10 );
	dc.LineTo( WindowRect.right - 10, WindowRect.top + 10 );
	dc.LineTo( WindowRect.right - 10, WindowRect.bottom - 10 );
	dc.LineTo( WindowRect.left + 10, WindowRect.bottom - 10 );
	dc.LineTo( WindowRect.left + 10, WindowRect.top + 10 );

	DrawBrush.CreateSolidBrush (ForeColor);
	OrigBrush = dc.SelectObject(&DrawBrush);
	dc.FloodFill(1,1, ShadowColor);
	dc.SelectObject(OrigBrush);
	DrawBrush.DeleteObject();

	//draw outer border shadow
	dc.MoveTo( WindowRect.left + 16, WindowRect.bottom - 10 );
	dc.LineTo( WindowRect.left + 16, WindowRect.top + 16 );
	dc.LineTo( WindowRect.right - 10, WindowRect.top + 16 );

	DrawBrush.CreateSolidBrush (ShadowColor);
	OrigBrush = dc.SelectObject(&DrawBrush);
	dc.FloodFill(11,11, ShadowColor);
	dc.SelectObject(OrigBrush);
	DrawBrush.DeleteObject();
	
	//select orig pen and delete draw pen
	dc.SelectObject(OrigPen);
	DrawPen.DeleteObject();
}

void Border::Window()
{
	int i;

	CClientDC dc(pWnd);
	
	BoxColor = WindowColor;
	BoxRect.left = X_OFFSET;
	BoxRect.right = X_OFFSET + 201;
	BoxRect.top = Y_OFFSET;
	BoxRect.bottom = Y_OFFSET + 401;
	Box();

	//select black pen for outlining
	DrawPen.CreatePen(PS_SOLID, 1, ShadowColor);
	OrigPen = dc.SelectObject(&DrawPen);

	//draw dom grid
	for(i = 1; i < 10; i++) {
		dc.MoveTo(BoxRect.left+i*20,BoxRect.top+1);
		dc.LineTo(BoxRect.left+i*20, BoxRect.bottom-1);
	}
	for(i = 1; i < 20; i++) {
		dc.MoveTo(BoxRect.left+1,BoxRect.top+i*20);
		dc.LineTo(BoxRect.right-1, BoxRect.top+i*20);
	}

	//select orig pen and delete draw pen
	dc.SelectObject(OrigPen);
	DrawPen.DeleteObject();
}

void Border::Title()
{
	CClientDC dc(pWnd);
	
	CFont TitleFont;
	CFont* OrigFont;
	
	int OrigBackMode;
	
	BoxColor = BackColor;
	BoxRect.left = 80;
	BoxRect.right = 280;
	BoxRect.top = Y_OFFSET+55;
	BoxRect.bottom = Y_OFFSET+105;
	Box();

	//set title font attributes
	TitleFont.CreateFont(
		36,					//height
		0,					//width
		0,					//escapement
		0,					//orietation
		0,					//weight
		0,					//italic
		0,					//underline
		0,					//strike out
		0,					//char set
		0,					//out precision
		0,					//clip precision
		0,					//quality
		FF_ROMAN,			//pitch and family
		"Roman"				//facename
	);
	
	//select new font, text alignment and background mode
	OrigFont = dc.SelectObject(&TitleFont);
	dc.SetTextAlign(TA_CENTER);
	OrigBackMode = dc.SetBkMode(TRANSPARENT);
	
	//display text title shadow
	dc.SetTextColor(ShadowColor);
	dc.TextOut(177,Y_OFFSET+64, "WinDom", 6);
	
	//display text title foreground color
	dc.SetTextColor(ForeColor);
	dc.TextOut(180,Y_OFFSET+61, "WinDom", 6);
	
	dc.SelectObject(OrigFont);
	TitleFont.DeleteObject();
	
	//reset background mode
	dc.SetBkMode(OrigBackMode);
}

void Border::Score()
{
	CClientDC dc(pWnd);
	
	CFont ScoreFont;
	CFont* OrigFont;
	
	int OrigBackMode;
	
	//set title font attributes
	ScoreFont.CreateFont(
		18,					//height
		0,					//width
		0,					//escapement
		0,					//orietation
		0,					//weight
		0,					//italic
		0,					//underline
		0,					//strike out
		0,					//char set
		0,					//out precision
		0,					//clip precision
		0,					//quality
		FF_SWISS,			//pitch and family
		"Arial"				//facename
	);
	OrigFont = dc.SelectObject(&ScoreFont);
	dc.SetTextAlign(TA_CENTER);
	OrigBackMode = dc.SetBkMode(TRANSPARENT);
	
	//erase previous text
	dc.SetTextColor(BackColor);
	dc.TextOut(230,Y_OFFSET+310, prev_score, strlen(prev_score));
	
	//convert current score integer value to string
	itoa(score, prev_score, 10);

	//display text title foreground color
	dc.SetTextColor(HiTextColor);
	dc.TextOut(230,Y_OFFSET+310, prev_score, strlen(prev_score));
	
	dc.SelectObject(OrigFont);
	ScoreFont.DeleteObject();
	
	//reset background mode
	dc.SetBkMode(OrigBackMode);
}

void Border::Color()
{
	CClientDC dc(pWnd);
	
	CFont ColorFont;
	CFont* OrigFont;
	
	int OrigBackMode;
	
	//set title font attributes
	ColorFont.CreateFont(
		18,					//height
		0,					//width
		0,					//escapement
		0,					//orietation
		0,					//weight
		0,					//italic
		0,					//underline
		0,					//strike out
		0,					//char set
		0,					//out precision
		0,					//clip precision
		0,					//quality
		FF_SWISS,			//pitch and family
		"Arial"				//facename
	);
	OrigFont = dc.SelectObject(&ColorFont);
	dc.SetTextAlign(TA_CENTER);
	OrigBackMode = dc.SetBkMode(TRANSPARENT);
	
	//erase previous text
	dc.SetTextColor(BackColor);
	dc.TextOut(230,Y_OFFSET+190, prev_color, strlen(prev_color));
	
    //convert current number of colors to string
	itoa(color, prev_color, 10);

	//display text title foreground color
	dc.SetTextColor(HiTextColor);
	dc.TextOut(230,Y_OFFSET+190, prev_color, strlen(prev_color));
	
	dc.SelectObject(OrigFont);
	ColorFont.DeleteObject();
	
	//reset background mode
	dc.SetBkMode(OrigBackMode);
}

void Border::ScoreBox()
{
	BoxColor = BackColor;
	BoxRect.left = 80;
	BoxRect.right = 280;
	BoxRect.top = Y_OFFSET+295;
	BoxRect.bottom = Y_OFFSET+345;
	Box();

	CClientDC dc(pWnd);
	
	CFont ScoreTitleFont;
	CFont* OrigFont;
	
	int OrigBackMode;
	
	//set title font attributes
	ScoreTitleFont.CreateFont(
		18,					//height
		0,					//width
		0,					//escapement
		0,					//orietation
		0,					//weight
		0,					//italic
		0,					//underline
		0,					//strike out
		0,					//char set
		0,					//out precision
		0,					//clip precision
		0,					//quality
		FF_SWISS,			//pitch and family
		"Arial"				//facename
	);
	OrigFont = dc.SelectObject(&ScoreTitleFont);
	dc.SetTextAlign(TA_CENTER);
	OrigBackMode = dc.SetBkMode(TRANSPARENT);
	
	//display text title foreground color
	dc.SetTextColor(HiTextColor);
	dc.TextOut(130,Y_OFFSET+310, "Score: ");
	
	dc.SelectObject(OrigFont);
	ScoreTitleFont.DeleteObject();
	
	//reset background mode
	dc.SetBkMode(OrigBackMode);
}

void Border::ColorBox()
{
	BoxColor = BackColor;
	BoxRect.left = 80;
	BoxRect.right = 280;
	BoxRect.top = Y_OFFSET+175;
	BoxRect.bottom = Y_OFFSET+225;
	Box();

	CClientDC dc(pWnd);
	
	CFont ColorTitleFont;
	CFont* OrigFont;
	
	int OrigBackMode;
	
	//set title font attributes
	ColorTitleFont.CreateFont(
		18,					//height
		0,					//width
		0,					//escapement
		0,					//orietation
		0,					//weight
		0,					//italic
		0,					//underline
		0,					//strike out
		0,					//char set
		0,					//out precision
		0,					//clip precision
		0,					//quality
		FF_SWISS,			//pitch and family
		"Arial"				//facename
	);
	OrigFont = dc.SelectObject(&ColorTitleFont);
	dc.SetTextAlign(TA_CENTER);
	OrigBackMode = dc.SetBkMode(TRANSPARENT);
	
	//display text title foreground color
	dc.SetTextColor(HiTextColor);
	dc.TextOut(130,Y_OFFSET+190, "Colors: ");
	
	dc.SelectObject(OrigFont);
	ColorTitleFont.DeleteObject();
	
	//reset background mode
	dc.SetBkMode(OrigBackMode);
}

void Border::PreDomBox()
{
	int i;

	CClientDC dc(pWnd);
	
	BoxColor = WindowColor;
	BoxRect.left = X_OFFSET - 40;
	BoxRect.right = X_OFFSET - 19;
	BoxRect.top = Y_OFFSET;
	BoxRect.bottom = Y_OFFSET + 61;
	Box();

	//select black pen for outlining
	DrawPen.CreatePen(PS_SOLID, 1, ShadowColor);
	OrigPen = dc.SelectObject(&DrawPen);

	//draw dom grid
//	for(i = 1; i < 2; i++) {
//		dc.MoveTo(BoxRect.left+i*20,BoxRect.top+1);
//		dc.LineTo(BoxRect.left+i*20, BoxRect.bottom-1);
//	}
	for(i = 1; i < 3; i++) {
		dc.MoveTo(BoxRect.left+1,BoxRect.top+i*20);
		dc.LineTo(BoxRect.right-1, BoxRect.top+i*20);
	}

	//select orig pen and delete draw pen
	dc.SelectObject(OrigPen);
	DrawPen.DeleteObject();
}

void Border::ErasePreDomBox()
{
	int
		Xpoint = X_OFFSET - 14,
		Ypoint = Y_OFFSET + 66;

	CClientDC dc(pWnd);
	
	//create and select window background brush
	DrawBrush.CreateSolidBrush (ScreenColor);
	OrigBrush = dc.SelectObject(&DrawBrush);
	
	//fill dom preview window with screen background color
	dc.FloodFill(Xpoint, Ypoint, ScreenColor);

	//clean up
	dc.SelectObject(OrigBrush);
	DrawBrush.DeleteObject();
}

void Border::Box()
{
	CClientDC dc(pWnd);
	
	RECT ShadowRect;
	
	//calculate shadow position
	ShadowRect.left = BoxRect.left + 6;
	ShadowRect.right = BoxRect.right + 6;
	ShadowRect.top = BoxRect.top + 6;
	ShadowRect.bottom = BoxRect.bottom + 6;
	
	//draw box shadow
	DrawBrush.CreateSolidBrush (ShadowColor);
	dc.FillRect(&ShadowRect, &DrawBrush);
	DrawBrush.DeleteObject();

	//draw box in fore color and fill it with the box color
	DrawPen.CreatePen(PS_SOLID, 1, ForeColor);
	OrigPen = dc.SelectObject(&DrawPen);
	DrawBrush.CreateSolidBrush (BoxColor);
	OrigBrush = dc.SelectObject(&DrawBrush);
	dc.Rectangle(&BoxRect);
    //delete draw pen and draw brush
    dc.SelectObject(OrigPen);
    DrawPen.DeleteObject();
	dc.SelectObject(OrigBrush);    
	DrawBrush.DeleteObject();
}
