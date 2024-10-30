#define FONT SMALL_FONT
#define LARGE_FONT 4
#define SM_FONT 7
#define TINY_FONT 6

#include "register.h"

class Border {
public:	//variables
	int
		score,
		color;

	unsigned
		orig_speed,
		cur_speed;

private:
	int
		x[2],
		y[2],
		box_color,
		new_hi,
		hi_score[10],
		Registered;

	char
		prev_color[25],		//previous number of colors
		prev_score[25],
		hi_name[11][10];

/*	struct score_struct{
		char name[25];
		int score;
	} top_score[10];
*/
public:	//functions
	Border();
	void InitBorder(RECT ClientRect);
	void InitBorder();
	void Score();
	void Color();
	void PreDomBox();
	void ErasePreDomBox();
//	int Again();
	void InitpWnd(CWnd* pInitWnd);

private:
	COLORREF
		ScreenColor,
		BackColor,
		ForeColor,
		ShadowColor,
		WindowColor,
		HiTextColor,
		TextColor,
		BoxColor;
	
	RECT 
		WindowRect,
		BoxRect;
	
	CWnd* pWnd;
	
	CPen DrawPen;
	CPen* OrigPen;
	CBrush DrawBrush;
	CBrush* OrigBrush;

	void Speed();
	void Outside();
	void Window();
	void Title();
	void ScoreBox();
	void ColorBox();
	void Box();
//	int ReadScores();
//	void GetName();
//	void WriteScore();
};