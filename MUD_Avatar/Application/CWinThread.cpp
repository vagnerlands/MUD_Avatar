#include "CWinThread.h"

CWinThread::~CWinThread()
{
	// release all handles
	CloseHandle(m_mutexHandle);
	CloseHandle(m_threadHandle);
}

CWinThread::CWinThread()
{
	// empty implementation
}

void CWinThread::createThread(string thName, void* thEntry)
{
	m_mutexHandle = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (m_mutexHandle == NULL)
	{
		cout << "CreateMutex error: " << GetLastError() << endl;
	}

	m_threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thEntry, &m_counter, 0x00000000, &m_threadID);
	if (m_mutexHandle == NULL)
	{
		cout << "CreateThread error: " << GetLastError() << endl;
	}
	cout << "Created <listening> thread " << m_threadHandle << endl;
}

void
CWinThread::mutexLock()
{
	DWORD dwWaitResult;
	// request the ownership of mutex...
	dwWaitResult = WaitForSingleObject(
		m_mutexHandle,   // handle to mutex
		5000L);   // five-second time-out interval
	switch (dwWaitResult)
	{
		// the thread got the mutex ownership...
		case WAIT_OBJECT_0:
			// mutex was performed
			break;		
		// cannot get the mutex ownership due to time-out.
		case WAIT_TIMEOUT:
			cout << "time-out interval elapsed, and the object's state is non-signaled." << endl;
			break;
		// got the ownership of the abandoned mutex object.
		case WAIT_ABANDONED:		
			cout << "the mutex is set to non-signaled." << endl;
			break;
	}
}

void
CWinThread::mutexUnlock()
{
	if (!ReleaseMutex(m_mutexHandle))
	{
		// deal with error.
		cout << "Error releasing mutex" << endl;
	}
}

void CWinThread::destroy()
{
	mutexUnlock();
}
