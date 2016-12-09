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
	// check if this ip is already registered
	unordered_map<string, CWinSocket*>::const_iterator checkIterator = m_sockedDB.find(user);
	if (checkIterator != m_sockedDB.end())
	{
		cout << "Duplicated connection from Key:[" << checkIterator->first << "] - first connection will be closed!" << endl;
		CWinSocket* condemed = (CWinSocket*)checkIterator->second;
		delete condemed;
		condemed = NULL;
		m_sockedDB.erase(user);
	}
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
	// intentionally - only one command per socket in this cycle will be parsed
	// we don't want cheaters to take advantage
	for (const auto& socketItem : m_sockedDB) {
		TByte tempBuf[1025];
		TInt32 bufSize;
		// general 
		CICommand *newCommand = socketItem.second->CreateCommand();
		if (newCommand != NULL)
		{
			// for consult - if needed
			newCommand->setKey(socketItem.first);
			// to update the status - send messages to client
			newCommand->setSocket(socketItem.second);
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

	string welcomeMsg = "Welcome do Avatar MUD\r\n";
	welcomeMsg +=       "---------------------\r\n";
    welcomeMsg += "   ___            __             __  _____  _____ \r\n";
    welcomeMsg += "  / _ |_  _____ _/ /____ _____  /  |/  / / / / _ \\\r\n";
    welcomeMsg += " / __ | |/ / _ `/ __/ _ `/ __/ / /|_/ / /_/ / // /\r\n";
    welcomeMsg += "/_/ |_|___/\\_,_/\\__/\\_,_/_/   /_/  /_/\\____/____/ \r\n";
    welcomeMsg += "                                                  \r\n";
                                                  
    welcomeMsg += "---------------------\r\n";
    welcomeMsg += "Developed by Avatar - avatarch@gmail.com \r\n";

	welcomeMsg += "\r\n> Please, insert your user: ";
	inSocket->write(welcomeMsg.c_str(), welcomeMsg.length());

	// invalid socket
	if (strcmp(inSocket->getClientIP(), "205.205.205.205") != 0) 
	{
		// once someone connects - this socket shall be sent to Login process
		// which will be treated in the main thread...
		// in any case, the ID of this connection shall be the connection IP
		addSocket(inSocket->getClientIP(), inSocket);
	} 
	else
	{
		delete inSocket;
	}


	// the process finishes here and a new socket shall be allocated in the next iteration
	// and should remain in startListenSocket() till a new user performs a connection

}

