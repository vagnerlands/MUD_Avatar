#ifndef _ITHREAD_H_
#define _ITHREAD_H_

#include <string>
#include <iostream>
#include "CCommonTypes.h"

using namespace Types;
using namespace std;

//typedef TThreadEntryPoint PTHREAD_START_ROUTINE;

class IThread {
public:
	virtual ~IThread()
	{
		// empty - should be reinplemented by derived class
	}
	virtual void createThread(string thName, void* thEntry) = 0;
	virtual void mutexLock() = 0;
	virtual void mutexUnlock() = 0;
	virtual void destroy() = 0;
};

#endif
