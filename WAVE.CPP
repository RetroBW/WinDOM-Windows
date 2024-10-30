/*********************************************************\
 CWave

 Inheritance    CObject
                   |
                 CWave

 This class provides a simple interface to play WAV files.
 It does not have the limation of sndPlaySound; the WAV file
 does not have to fit into available memory. It sends MCI 
 commands to the device to play the WAV file.
 
\*********************************************************/

#include "stdafx.h"
#include "wave.h"

// constructor
CWave::CWave()
{
	// initialize private data members
	m_nDeviceID = 0;
	m_nElementID = 0;
}


// destructor
CWave::~CWave()
{
	// make sure wave file is closed
	if (m_nElementID)
		Stop();

	// make sure wave device is closed
	if (m_nDeviceID)
		CloseDevice();
}


/*********************************************************\
 OpenDevice (public)

 Open wave audio device.
 
 Return
  0 is success, otherwise error code of MCI operation

\*********************************************************/

DWORD CWave::OpenDevice()
{
	DWORD dwResult = 0;

	// open wave device if not already open
	if (m_nDeviceID)
		{
		MCI_OPEN_PARMS mciOpenParms;

		// set the device to a WAV audio device	
		mciOpenParms.lpstrDeviceType = (LPSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;

		// open the wave device	
		dwResult = mciSendCommand(NULL, MCI_OPEN,
			MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_WAIT,
			(DWORD)(LPVOID)&mciOpenParms);

		// save device identifier, will use with other MCI commands
		m_nDeviceID = mciOpenParms.wDeviceID;

		// display error message if failed
 		if (dwResult)
			DisplayErrorMsg(dwResult);
		}

	// return result of MCI operation
	return dwResult;
}



/*********************************************************\
 CloseDevice (public)

 Close the wave audio device. 

 Return
  0 is success, otherwise error code of MCI operation

\*********************************************************/

DWORD CWave::CloseDevice()
{
	DWORD dwResult = 0;

	// close if currently open
	if (m_nDeviceID)
		{
		// close the MCI device
		dwResult = mciSendCommand(m_nDeviceID, 
			MCI_CLOSE, NULL, NULL);

		// display error message if failed
		if (dwResult)
			DisplayErrorMsg(dwResult);

		// set identifer to closed state
		else
			m_nDeviceID = 0;
		}

	// return result of MCI operation
	return dwResult;
}



/*********************************************************\
 Play (public)

 Play specified wave file. First open the wave file element.
 Then play the wave file asynchronously. The specified window
 will receive a MM_MCINOTIFY message when the play operation
 has completed.
 
 Input
  pWnd ........ window that will receive notification message
  pFileName ... name of wave file to be played

 Return
  0 is success, otherwise error code of MCI operation

\*********************************************************/

DWORD CWave::Play(CWnd* pWnd, LPCSTR pFileName)
{
	MCI_OPEN_PARMS mciOpenParms;

	//open wave device
	OpenDevice();
	
	// initialize structure 
	memset(&mciOpenParms, 0, sizeof(MCI_OPEN_PARMS));

	// set the WAV file name to be played
	mciOpenParms.lpstrElementName = pFileName;

	// first open the device	
	DWORD dwResult = mciSendCommand(m_nDeviceID, MCI_OPEN,
		MCI_OPEN_ELEMENT,
		(DWORD)(LPVOID)&mciOpenParms);

	// display error message if failed
 	if (dwResult)
		DisplayErrorMsg(dwResult);

  	// if successful, intruct the device to play the WAV file
	else		
		{
		// save element indentifier
		m_nElementID = mciOpenParms.wDeviceID;

		MCI_PLAY_PARMS mciPlayParms;
	
		// set the window that will receive notification message
		mciPlayParms.dwCallback = (DWORD)pWnd->m_hWnd;
		
		// instruct device to play file
		dwResult = mciSendCommand(m_nElementID, MCI_PLAY,
			MCI_NOTIFY, (DWORD)(LPVOID)&mciPlayParms);

		// display error and close element if failed
	 	if (dwResult)
			{
			DisplayErrorMsg(dwResult);
			Stop();
			}
		}

	//close wave device
	CloseDevice();
	
	// return result of MCI operation
	return dwResult;
}



/*********************************************************\
 Stop (public)

 Close the wave file element (the wave file device is 
 left open).
 
 Return
  0 is success, otherwise error code of MCI operation

\*********************************************************/

DWORD CWave::Stop()
{
	DWORD dwResult = 0;

	// close if element is currenly open
	if (m_nElementID)
		{
		// close element
		dwResult = mciSendCommand(m_nElementID, MCI_CLOSE, NULL, NULL);

		// display error message if failed
 		if (dwResult)
			DisplayErrorMsg(dwResult);

		// set identifier to closed state
		else
			m_nElementID = 0;
		}

	// return result of MCI operation
	return dwResult;
}


/*********************************************************\
 DisplayErrorMsg (private)

 If there was an error, display a string in a message box 
 that describes the MCI error. If there is not an error, 
 this function does not do anything.
 
 Input
  dwError ... MCI error 

\*********************************************************/

void CWave::DisplayErrorMsg(DWORD dwError)
{
	// check if there was an error
	if (dwError)
		{
		// character string that contains error message
		char szErrorMsg[MAXERRORLENGTH];

		// retrieve string associated with error
		if (!mciGetErrorString(dwError, szErrorMsg, sizeof(szErrorMsg)))
			strcpy(szErrorMsg, "Unknow Error");

		// display error string in message box
		::MessageBox(NULL, szErrorMsg, "MCI Error", MB_ICONEXCLAMATION | MB_OK);
		}
}

