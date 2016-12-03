#include "CSocketHolder.h"

CSocketHolder::CSocketHolder()
{
	// empty
}

CSocketHolder::~CSocketHolder()
{
	// loops through all open sockets and close them all
	// Iterate and print keys and values of unordered_map
	for (const auto& socketItem : m_sockedDB) {
		cout << "Forcing connect Key:[" << socketItem.first << "] to close !" << endl;
		CWinSocket* condemed = (CWinSocket*)socketItem.second;
		delete condemed;
		condemed = NULL;
	}
}

void 
CSocketHolder::addSocket(string user, CWinSocket* userSocket)
{
	// protects with MUTEX
	CWinThread::instance()->mutexLock();
	// creates a pair for user/userSocket
	m_sockedDB.insert({ user, userSocket });
	// Releases MUTEX
	CWinThread::instance()->mutexUnlock();
}

bool
CSocketHolder::dropSocket(string user)
{
	// creates a pair for user/userSocket
	m_sockedDB[user]->closeSocket();
	bool retVal = m_sockedDB.erase(user);

	return retVal;
}

string 
CSocketHolder::read()
{
	return "a";
}

void 
CSocketHolder::write(string data)
{

}

void
CSocketHolder::readIncomingMsgs()
{
	for (const auto& socketItem : m_sockedDB) {
		char tempBuf[1025];
		int bufSize;
		int iRes = socketItem.second->read(tempBuf, &bufSize);

		// error code - lost connection;
		if (iRes == 100)
		{
			cout << "ERROR READING " << socketItem.first << " Code " << iRes << endl;
			m_condemedSockets.push_back(socketItem.first);
			CWinSocket* condemed = (CWinSocket*)socketItem.second;
			delete condemed;
			condemed = NULL;
		}
	}

}

void CSocketHolder::executeCommands()
{
	// intentionally - only one command per cycle will be parsed
	// we don't want cheaters to take adavantage
	for (const auto& socketItem : m_sockedDB) {
		char tempBuf[1025];
		int bufSize;
		// general 
		CICommand *newCommand = socketItem.second->execute1Command();
		if (newCommand != NULL)
		{
			newCommand->setKey(socketItem.first);
			// executes it immediatelly
			newCommand->execute();
			// deletes the allocated memory to avoid mem leak
			delete newCommand;
			newCommand = NULL;
		}

		// must decide what to do with iRes
	}
}

TInt32 
CSocketHolder::removeCondemedSockets()
{
	TInt32 retVal = m_condemedSockets.size();

	// protects with MUTEX
	CWinThread::instance()->mutexLock();

	for (std::list<string>::iterator it = m_condemedSockets.begin(); it != m_condemedSockets.end(); ++it)
	{
		m_sockedDB.erase(*it);
	}

	m_condemedSockets.clear();

	// release MUTEX
	CWinThread::instance()->mutexUnlock();

	return retVal;
}

void 
CSocketHolder::onConnectionEvent()
{
	CWinSocket* inSocket = new CWinSocket();

	// blocking action - stays here till a new user connects
	inSocket->startListenSocket();

	string welcomeMsg = "Welcome do Avatar MUD\n\r";
	welcomeMsg +=       "---------------------\n\r";
	welcomeMsg +=       "\n\r";
	welcomeMsg +=       "Please, insert your login: ";
	inSocket->write(welcomeMsg.c_str(), welcomeMsg.length());

	// once someone connects - this socket shall be sent to Login process
	// which will be treated in the main thread...
	// in any case, the ID of this connection shall be the connection IP
	addSocket(inSocket->getClientIP(), inSocket);


	// the process finishes here and a new socket shall be allocated in the next iteration
	// and should remain in startListenSocket() till a new user performs a connection

}

