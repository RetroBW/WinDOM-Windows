#include "..\header\cpp.h"
#include "dom.h"
#include "color.h"
#include "offset.h"

Dom::Dom()
{
	time_t t;
	srand( (unsigned) time(&t) );
	num_color = 3;
}

Dom::~Dom()
{
	EraseDom(x, y-2);
	EraseDom(x, y-1);
	EraseDom(x, y);
}

void Dom::InitDom()
{
	int
		i,
		color;

	//init Dom position
	x = 4;
	y = 2;

	//init Dom colors
	for(i = 0; i < 3; i++)
	{	color = rand() % num_color;

		switch(color)
		{	case 0:
				dom_color[i] = EGA_YELLOW;
				break;
			case 1:
				dom_color[i] = EGA_GREEN;
				break;
			case 2:
				dom_color[i] = EGA_RED;
				break;
			case 3:
				dom_color[i] = EGA_MAGENTA;
				break;
			case 4:
				dom_color[i] = EGA_LIGHTBLUE;
				break;
			case 5:
				dom_color[i] = EGA_LIGHTGREEN;
				break;
			case 6:
				dom_color[i] = EGA_LIGHTCYAN;
				break;
			case 7:
				dom_color[i] = EGA_LIGHTRED;
				break;
			case 8:
				dom_color[i] = EGA_LIGHTMAGENTA;
				break;
			case 9:
				dom_color[i] = EGA_CYAN;
				break;
			case 10:
				dom_color[i] = EGA_WHITE;
				break;
		}
	}
	DrawDom();
}

void Dom::DrawDom()
{
	setcolor(dom_color[0]);
	DisplayDom(x, y-2);

	setcolor(dom_color[1]);
	DisplayDom(x, y-1);

	setcolor(dom_color[2]);
	DisplayDom(x, y);
}

void Dom::LeftDom()
{
	if(x > 0)
	{	EraseDom(x, y-2);
		EraseDom(x, y-1);
		EraseDom(x, y);

		x--;
		DrawDom();
	}
}

void Dom::RightDom()
{
	if(x < 9)
	{	EraseDom(x, y-2);
		EraseDom(x, y-1);
		EraseDom(x, y);

		x++;
		DrawDom();
	}
}

void Dom::DownDom()
{
	if(y < 19)
	{	EraseDom(x, y - 2);

		y++;
		DrawDom();
	}

	sound(700);
	delay(50);
	nosound();
}

void Dom::DropDom(int height)
{
	if(y < 19)
	{	EraseDom(x, y - 2);
		EraseDom(x, y - 1);
		EraseDom(x, y);

      y = height;
		DrawDom();
	}
}

void Dom::RotateDom()
{
	int temp_color;

	temp_color = dom_color[0];
	dom_color[0] = dom_color[1];
	dom_color[1] = dom_color[2];
	dom_color[2] = temp_color;

	DrawDom();
}

void Dom::EraseDom(int cur_x, int cur_y)
{
	setcolor(WINDOW);
	DisplayDom(cur_x, cur_y);
}

void Dom::DisplayDom(int cur_x, int cur_y)
{
	cur_x = cur_x * 20 + X_OFFSET;
	cur_y = cur_y * 20 + Y_OFFSET;

	setfillstyle( SOLID_FILL, getcolor() );
	rectangle(cur_x+1, cur_y+1, cur_x + 19, cur_y + 19);
	floodfill( cur_x + 10, cur_y + 10, getcolor() );
}