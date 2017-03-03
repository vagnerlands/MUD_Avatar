#ifndef _CICOMMAND_H_
#define _CICOMMAND_H_

#include <string>
#include "ISocket.h"

using namespace std;

class CICommand {
public:
	//CICommand();
	//virtual ~CICommand() = 0;
	virtual void execute() = 0;

	// set the key - to perform matching later on in the sockets
	void setKey(string user);

	void setSocket(ISocket* socket);

protected:
	string m_socketKey;
	ISocket* m_socket;
};

inline void CICommand::setKey(string user)
{
	m_socketKey = user;
}

inline void
CICommand::setSocket(ISocket* socket)
{
	m_socket = socket;
}

#endif //_CICOMMAND_H_
