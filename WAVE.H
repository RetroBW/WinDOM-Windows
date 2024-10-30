#ifndef _WAVE_H
#define _WAVE_H

#include <mmsystem.h>

// taken from Visual C++ 2.0 mmsystem.h file
// (it's not in VC1.5 mmsystem.h)
#ifndef _MCIDEVICEID_
#define _MCIDEVICEID_
typedef UINT    MCIDEVICEID;    // MCI device ID type
/* BEWARE:  MCI device ids can be stored and read from Win 3 compatible */
/* files when the device id will be WORD size. */
#endif // _MCIDEVICEID_

class CWave : public CObject
{
// constructor, destructor
public:
	CWave();
	~CWave();

// public member functions
public:
	DWORD	OpenDevice();
	DWORD	CloseDevice();
	DWORD	Play(CWnd* pWnd, LPCSTR pFileName);
	DWORD	Stop();

// pricate member function
private:
	void	DisplayErrorMsg(DWORD dwError);

// private data members
private:
	MCIDEVICEID	m_nDeviceID;	// identifer of MCI device
	MCIDEVICEID	m_nElementID;	// identifer of MCI device
};


#endif
