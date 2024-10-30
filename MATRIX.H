class Matrix {
public:	//variables
	int
		matrix[10][20],
		height[10],
		score,
		next_score;

private:
	int match[10][20];

    COLORREF
    	WinColors[10],
		DomColor[3],	//dom color values
    	WinBackColor;
    	
    CWnd* pWnd;

    CBrush
    	DrawBrush,
    	EraseBrush;

public:	//functions
	Matrix();
	~Matrix();
	void InitpWnd(CWnd* pInitWnd);
    void InitMatrix();
	int Check();
	void DrawColumn();

private:
	void RemoveMatch();
};

