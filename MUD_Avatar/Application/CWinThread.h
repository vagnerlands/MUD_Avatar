#ifndef _CWINTHREAD_H_
#define _CWINTHREAD_H_

#include <Windows.h>
#include <string>
#include <iostream>
#include "CCommonTypes.h"

using namespace Types;
using namespace std;

//typedef TThreadEntryPoint PTHREAD_START_ROUTINE;

class CWinThread {
public:
	static CWinThread* instance();
	void createThread(string thName, LPTHREAD_START_ROUTINE thEntry);
	void mutexLock();
	void mutexUnlock();
	void destroy();
private:
	CWinThread();
	~CWinThread();
	DWORD m_threadID;
	HANDLE m_threadHandle;
	HANDLE m_mutexHandle;
	TUInt32 m_counter;
	static CWinThread* s_pInstance;
};

#endif
