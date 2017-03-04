#ifndef _CWINTHREAD_H_
#define _CWINTHREAD_H_

#include <Windows.h>
#include <string>
#include <iostream>
#include "CCommonTypes.h"
#include "IThread.h"

using namespace Types;
using namespace std;

class CWinThread : public IThread {
public:
	CWinThread();
	~CWinThread();
	//void createThread(string thName, LPTHREAD_START_ROUTINE thEntry);
	void createThread(string thName, void* thEntry);
	void mutexLock();
	void mutexUnlock();
	void destroy();
private:
	DWORD m_threadID;
	HANDLE m_threadHandle;
	HANDLE m_mutexHandle;
	TUInt32 m_counter;
};

#endif
