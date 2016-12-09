#ifndef _CCLIENTSOCKET_H_
#define _CCLIENTSOCKET_H_

#include "CWinSocket.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include "CCommonTypes.h"
#include "CWinThread.h"
#include "CCommandLoginUserName.h"


// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

using namespace std;

class CSocketHolder {
public:
	CSocketHolder();
	~CSocketHolder();

	void addSocket(string user, CWinSocket* userSocket);
	void onConnectionEvent();
	bool dropSocket(string user);

	string read();
	void write(string data);

	void readIncomingMsgs();

	void executeCommands();

	TInt32 removeCondemedSockets();
private:
	// socket database - all client sockets shall be placed here
	// Key == client IP
	// Value == CWinSocket* object, including handle of the connection
	unordered_map<string, CWinSocket*> m_sockedDB;

	list<string> m_condemedSockets;

};

#endif //_CCLIENTSOCKET_H_
