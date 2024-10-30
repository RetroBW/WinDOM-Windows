#include "stdafx.h"

#include "matrix.h"
#include "offset.h"

#define DEBUG 0
#define MATCH -1
#define EMPTY -2

#define DIAG 35
#define VERT 25
#define HORIZ 15

Matrix::Matrix()
{
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

Matrix::~Matrix()
{
}

void Matrix::InitMatrix()
{
	int 
		index_x,
		index_y;
		
	//initialize matrix, match and height
	for(index_x = 0; index_x < 10; index_x++)
	{  height[index_x] = 19;

		for(index_y = 0; index_y < 20; index_y++) {
			matrix[index_x][index_y] = EMPTY;
			match[index_x][index_y] = 0;
		}
	}

	score = 0;
	next_score = 400;
	
	DrawColumn();
}

void Matrix::InitpWnd(CWnd* pInitWnd)
{
	pWnd = pInitWnd;
}

int Matrix::Check()
{
	int
		index_x,
		index_y,
		prev_score = score,
		FoundMatch = 0;

	//check column
	for(index_x = 0; index_x < 10; index_x++)
	{  //check cell
		for(index_y = 19; (index_y >= 0) && (matrix[index_x][index_y] != EMPTY);
		index_y--)
		{  //check verticle
			if(matrix[index_x][index_y] == matrix[index_x][index_y - 1])
			{	if (matrix[index_x][index_y] == matrix[index_x][index_y - 2])
				{	match[index_x][index_y] = MATCH;
					match[index_x][index_y - 1] = MATCH;
					match[index_x][index_y - 2] = MATCH;
					score += VERT;
				}
			}
			if(index_x <= 7)
			{	//check diag up if index_y >= 2
				if(index_y >= 2)
				{	if(matrix[index_x][index_y] == matrix[index_x+1][index_y-1])
					{	if (matrix[index_x][index_y] ==
						matrix[index_x+2][index_y-2])
						{	match[index_x][index_y] = MATCH;
							match[index_x+1][index_y-1] = MATCH;
							match[index_x+2][index_y-2] = MATCH;
							score += DIAG;
						}
					}
				}
				//check horizontal
				if(matrix[index_x][index_y] == matrix[index_x+1][index_y])
				{	if(matrix[index_x][index_y] == matrix[index_x+2][index_y])
					{	match[index_x][index_y] = MATCH;
						match[index_x+1][index_y] = MATCH;
						match[index_x+2][index_y] = MATCH;
						score += HORIZ;
					}
				}
				//check diag down if index_y < 17
				if(index_y <= 17)
				{	if(matrix[index_x][index_y] == matrix[index_x+1][index_y+1])
					{	if (matrix[index_x][index_y] ==
						matrix[index_x+2][index_y+2])
						{	match[index_x][index_y] = MATCH;
							match[index_x+1][index_y+1] = MATCH;
							match[index_x+2][index_y+2] = MATCH;
							score += DIAG;
						}
					}
				}
			}
		}
	}

	if(prev_score != score)
	{	RemoveMatch();
		Check();
		FoundMatch = 1;
	}

	DrawColumn();
	
	return FoundMatch;
}

void Matrix::RemoveMatch()
{
	int
		match_fnd = 0,	//set when match encountered to generate tone
		i,					//local index
		index_x,			//x coordinate
		index_y;			//y coordinate

	//check column
	for(index_x = 0; index_x < 10; index_x++)
	{  //check cell
		for(index_y = 19; (index_y >= 0) && (matrix[index_x][index_y] != EMPTY);
		index_y--)
		{  //match found
			if(match[index_x][index_y] == MATCH)
			{  //not top of column - replace found match
				if(index_y)
				{	matrix[index_x][index_y] = matrix[index_x][index_y-1];
					match[index_x][index_y] = match[index_x][index_y-1];
				}
				//shift remainder of column down
				for(i=index_y;	(i > 0) && (matrix[index_x][i] != EMPTY); i--)
				{	matrix[index_x][i] = matrix[index_x][i-1];
					match[index_x][i] = match[index_x][i-1];
				}
				//top of column = 0
				matrix[index_x][0] = EMPTY;
				match[index_x][0] = 0;
				//check matrix position again due to shift
				index_y++;
				//increment height, for 0 Doms, height = 20
				height[index_x]++;
				//set to generate tone
				match_fnd = 1;
			}
		}
	}
}

void Matrix::DrawColumn()
{
	int
		index_x,
		index_y;

	RECT DisplayDomRect;

	CClientDC dc(pWnd);
	
	//check column
	for(index_x = 0; index_x < 10; index_x++)
	{  //check cell
		for(index_y = 19; index_y >= 0; index_y--)
		{	DisplayDomRect.top = (index_y * 20) + Y_OFFSET + 1;
			DisplayDomRect.left = (index_x * 20) + X_OFFSET + 1;
			DisplayDomRect.bottom = DisplayDomRect.top + 19;
			DisplayDomRect.right = DisplayDomRect.left + 19;

			if(matrix[index_x][index_y] != EMPTY)
				DrawBrush.CreateSolidBrush ( WinColors[matrix[index_x][index_y]] );
			else
				DrawBrush.CreateSolidBrush ( WinBackColor );

			dc.FillRect(&DisplayDomRect, &DrawBrush);
			DrawBrush.DeleteObject();
		}
	}
}