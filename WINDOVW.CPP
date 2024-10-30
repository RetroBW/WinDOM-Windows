// windovw.cpp : implementation of the CWindomView class
//

#include "stdafx.h"
#include "windom.h"
#include <mmsystem.h>

#include "windodoc.h"
#include "windovw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindomView

IMPLEMENT_DYNCREATE(CWindomView, CView)

BEGIN_MESSAGE_MAP(CWindomView, CView)
	//{{AFX_MSG_MAP(CWindomView)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_OPTIONS_SOUND, OnOptionsSound)
	ON_COMMAND(ID_OPTIONS_PREVIEW, OnOptionsPreview)
	ON_COMMAND(ID_FILE_SCORE, OnFileScore)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindomView construction/destruction

CWindomView::CWindomView()
{
	// TODO: add construction code here
	MyDom.InitpWnd(this);
	MyMatrix.InitpWnd(this);
	MyBorder.InitpWnd(this);

	PlayGame = 0;
	SoundWait = 0;
	
	if(REGISTERED) {
		SoundOn = 1;
		PreviewOn = 1;
	}
	else {
		SoundOn = 0;
		PreviewOn = 0;
	}
}

CWindomView::~CWindomView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CWindomView drawing

void CWindomView::OnDraw(CDC* pDC)
{
	CWindomDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	RECT ClientRect;
	
	GetClientRect(&ClientRect);
	MyBorder.InitBorder(ClientRect);
	
	if(PlayGame) {
		MyMatrix.DrawColumn();
		MyDom.DrawPreDom();
		MyDom.DrawDom(PreviewOn);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWindomView diagnostics

#ifdef _DEBUG
void CWindomView::AssertValid() const
{
	CView::AssertValid();
}

void CWindomView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWindomDoc* CWindomView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWindomDoc)));
	return (CWindomDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWindomView message handlers

void CWindomView::OnFileNew()
{
	//end current game if one is being played
	if(PlayGame) GameOver();

    //init speed
	Speed = 500;

	// allocate timer
	DomTimer = SetTimer(1,Speed,NULL);
	if(DomTimer == 0)
		MessageBox("Cannot allocate timer!!!");
	else {
		if(SoundOn) sndPlaySound("dom.wav", SND_SYNC);
		PlayGame = 1;
		MyBorder.score = 0;
		MyBorder.color = 3;
		MyBorder.Color();
		MyBorder.Score();
		MyMatrix.InitMatrix();
		MyDom.num_color = 3;
		MyDom.InitDom(PreviewOn);
	}
}

void CWindomView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// handle keystrokes if game is still going
	if(PlayGame) {
		switch(nChar) {
			case VK_LEFT:
				if(MyDom.x > 0)
					if(MyMatrix.height[MyDom.x - 1] > MyDom.y)
						MyDom.LeftDom();
				break;
			case VK_RIGHT:
				if(MyDom.x < 9)
					if(MyMatrix.height[MyDom.x + 1] > MyDom.y)
						MyDom.RightDom();
				break;
			case VK_UP:
				MyDom.RotateDom();
				break;
			case VK_DOWN:
				MyDom.DropDom(MyMatrix.height[MyDom.x]);
				break;
		}
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CWindomView::OnTimer(UINT nIDEvent)
{
	//make sure that it's our timer that went off
	if(nIDEvent == DomTimer) {
		if(MyMatrix.height[MyDom.x] > MyDom.y) {
			//move dom down
			MyDom.DownDom();
			//play sound, change sound as score increases
			if(SoundOn) {
				if(!SoundWait)
					switch(MyDom.num_color) {
						case 3:
							sndPlaySound("down1.wav", SND_ASYNC);
							break;
						case 4:
							sndPlaySound("down2.wav", SND_ASYNC);
							break;
						case 5:
							sndPlaySound("down3.wav", SND_ASYNC);
							break;
						case 6:
							sndPlaySound("down4.wav", SND_ASYNC);
							break;
						case 7:
							sndPlaySound("down5.wav", SND_ASYNC);
							break;
						case 8:
							sndPlaySound("down6.wav", SND_ASYNC);
							break;
						case 9:
							sndPlaySound("down7.wav", SND_ASYNC);
							break;
						case 10:
							sndPlaySound("down8.wav", SND_ASYNC);
							break;
        			}
        		else SoundWait = 0;
        	}
		}
		else {
			//store Dom - move Dom colors to appropriate matrix positions
			for(int i = 0; i < 3; i++)
				MyMatrix.matrix[MyDom.x][MyDom.y-i] = MyDom.DomColor[abs(i-2)];
		
			//set new matrix height
			MyMatrix.height[MyDom.x] = MyMatrix.height[MyDom.x] - 3;
			//check for matches, play sound if any are found
			if(MyMatrix.Check()) {
				if(SoundOn) {
					SoundWait = 1;
					sndPlaySound("match.wav", SND_ASYNC);
				}
			}

			//increment number of colors and score
			if(MyMatrix.score > MyMatrix.next_score)
			{  //increment number of colors
				if(MyDom.num_color < 10)
				{	MyDom.num_color++;
					MyBorder.color = MyDom.num_color;
					MyBorder.Color();
				}
				//increment speed
				if(Speed > 25) {
					Speed-=25;
					KillTimer(DomTimer);
					DomTimer = SetTimer(1,Speed,NULL);
					if(DomTimer == 0) MessageBox("Cannot allocate timer!!!");
				}
				//increment next score to increment color and score
				MyMatrix.next_score += 400;
			}

			//init dom
			MyBorder.score = MyMatrix.score;
			MyBorder.Score();
			MyDom.InitDom(PreviewOn);
		}
	
		//if the doms are stacker too high, the game is over
		if(MyMatrix.height[4] <= 3) GameOver();
	}
	
	CView::OnTimer(nIDEvent);
}

void CWindomView::GameOver()
{
	PlayGame = 0;
	KillTimer(DomTimer);
	if(REGISTERED) CheckScore();
}

void CWindomView::OnKillFocus(CWnd* pNewWnd)
{
	CView::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
	if(PlayGame) KillTimer(DomTimer);
}

void CWindomView::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	if(PlayGame) {
		DomTimer = SetTimer(1,Speed,NULL);
		if(DomTimer == 0) MessageBox("Cannot allocate timer!!!");
	}
}

void CWindomView::OnOptionsSound()
{
	//get pointer to parent window and the menu
	CWnd* pParent = GetParent();
	CMenu* pMenu = pParent->GetMenu();
	
	//toggle sound on/off
	if(REGISTERED) {
		if(SoundOn) {
			pMenu->CheckMenuItem(ID_OPTIONS_SOUND, MF_UNCHECKED);
			//MyWave.CloseDevice();
			SoundOn = 0;
		}
		else {
			pMenu->CheckMenuItem(ID_OPTIONS_SOUND, MF_CHECKED);
			//MyWave.OpenDevice();
			SoundOn = 1;
		}
	}
	else MessageBox("Please register WinDom to enable this feature", "Please Register", MB_OK | MB_ICONEXCLAMATION);
}

void CWindomView::OnOptionsPreview()
{
	//get pointer to parent window and the menu
	CWnd* pParent = GetParent();
	CMenu* pMenu = pParent->GetMenu();
	
	if(REGISTERED) {
		if(PreviewOn) {
			PreviewOn = 0;
			pMenu->CheckMenuItem(ID_OPTIONS_PREVIEW, MF_UNCHECKED);
			MyBorder.ErasePreDomBox();
		}
		else {
			PreviewOn = 1;
			pMenu->CheckMenuItem(ID_OPTIONS_PREVIEW, MF_CHECKED);
			MyBorder.PreDomBox();
		}
	}
	else MessageBox("Please register WinDom to enable this feature", "Please Register", MB_OK | MB_ICONEXCLAMATION);
}

void CWindomView::ReadScores()
{
	CFile DomFile;
	CFileException DomFileException;
	
	int i;
	
	if(DomFile.Open("top.bin", CFile::modeRead, &DomFileException))
		for(i = 0; i < 10; i++) {	
			if(!DomFile.Read(HiScore[i].hi_name.GetBuffer(10), 10 )) HiScore[i].hi_name = "\0";
			HiScore[i].hi_name.ReleaseBuffer(-1);
			if(!DomFile.Read(&HiScore[i].hi_score, sizeof(int))) HiScore[i].hi_score = 0;
		}
	else 
		for(i = 0; i < 10; i++) {	
			HiScore[i].hi_name = "\0";
			HiScore[i].hi_score = 0;
		}
	
}

void CWindomView::WriteScores()
{
	CFile DomFile("top.bin", CFile::modeWrite | CFile::modeCreate);

	for(int i=0; i < 10; i++) {	
		DomFile.Write(HiScore[i].hi_name, 10 );
		DomFile.Write(&HiScore[i].hi_score, sizeof(int));
	}
}

void CWindomView::CheckScore()
{
	//read scores
	ReadScores();
	
	//check score, prompt for name if high score
	if(MyBorder.score > HiScore[9].hi_score) {
		NameDialog.DoModal();
		if(NameDialog.m_Name != "\0") NameOk();
	}
	else DisplayScores();
}

void CWindomView::NameOk()
{
	//copy name and score into last place
	HiScore[9].hi_score = MyBorder.score;
	HiScore[9].hi_name = NameDialog.m_Name;
	
	//sort by score
	for(int j = 0; j < 9; j++)
		for(int i = 9; i > j; i--)
			if(HiScore[i].hi_score > HiScore[i-1].hi_score) {	
				TempScore = HiScore[i];
				HiScore[i] = HiScore[i-1];
				HiScore[i-1] = TempScore;
			}
	
	//display high scores dialog
	WriteScores();
	DisplayScores();
}

void CWindomView::DisplayScores()
{
	ScoreDialog.m_Name1 = HiScore[0].hi_name;
	ScoreDialog.m_Name2 = HiScore[1].hi_name;
	ScoreDialog.m_Name3 = HiScore[2].hi_name;
	ScoreDialog.m_Name4 = HiScore[3].hi_name;
	ScoreDialog.m_Name5 = HiScore[4].hi_name;
	ScoreDialog.m_Name6 = HiScore[5].hi_name;
	ScoreDialog.m_Name7 = HiScore[6].hi_name;
	ScoreDialog.m_Name8 = HiScore[7].hi_name;
	ScoreDialog.m_Name9 = HiScore[8].hi_name;
	ScoreDialog.m_Name10 = HiScore[9].hi_name;
	
	ScoreDialog.m_Score1 = HiScore[0].hi_score;
	ScoreDialog.m_Score2 = HiScore[1].hi_score;
	ScoreDialog.m_Score3 = HiScore[2].hi_score;
	ScoreDialog.m_Score4 = HiScore[3].hi_score;
	ScoreDialog.m_Score5 = HiScore[4].hi_score;
	ScoreDialog.m_Score6 = HiScore[5].hi_score;
	ScoreDialog.m_Score7 = HiScore[6].hi_score;
	ScoreDialog.m_Score8 = HiScore[7].hi_score;
	ScoreDialog.m_Score9 = HiScore[8].hi_score;
	ScoreDialog.m_Score10 = HiScore[9].hi_score;
	
	ScoreDialog.DoModal();
}

void CWindomView::OnFileScore()
{
	//read and display scores
	if(REGISTERED) {
		ReadScores();
		DisplayScores();
	}
	else MessageBox("Please register WinDom to enable this feature", "Please Register", MB_OK | MB_ICONEXCLAMATION);
}

int CWindomView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CWnd* pParent = GetParent();
	CMenu* pMenu = pParent->GetMenu();

	if(!REGISTERED) {
		pMenu->CheckMenuItem(ID_OPTIONS_SOUND, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_OPTIONS_PREVIEW, MF_UNCHECKED);
	}
	
	return 0;
}
