class Dom
{   
//windows graphics
public:
    CPen* OrigPen;
    CBrush* OrigBrush;
    
    CPen
    	DrawPen,
    	ErasePen;
    	
    CBrush
    	DrawBrush,
    	EraseBrush;

    RECT ScreenSize;
    
    COLORREF
    	WinColors[10],
    	WinBackColor;
    	
	int 
		DomPreColor[3],
		DomColor[3];	//dom color values
	
    CWnd* pWnd;

//dom variables
public:
	int
		num_color,		//number of possible colors
		x,				//x coordinate
		y;				//y coordinate

//dom functions
public:
	Dom();
	~Dom();
	void InitpWnd(CWnd* pInitWnd);
	void InitDom(int PreviewOn);
	void DrawDom(int PreviewOn);
	void DrawPreDom();
	void LeftDom();
	void RightDom();
	void DownDom();
	void DropDom(int height);
	void RotateDom();

private:
	void DisplayDom(int cur_x, int cur_y, COLORREF DisplayDomColor);
	void InitPreDom();
	void EraseDom(int cur_x, int cur_y);
};
