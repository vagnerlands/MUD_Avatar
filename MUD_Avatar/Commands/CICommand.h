#ifndef _CICOMMAND_H_
#define _CICOMMAND_H_

#include <string>

using namespace std;
// forward declaration of CWinSocket
class CWinSocket;
class CICommand {
public:
	//CICommand();
	//virtual ~CICommand() = 0;
	virtual void execute() = 0;

	// set the key - to perform matching later on in the sockets
	void setKey(string user);

	void setSocket(CWinSocket* socket);

protected:
	string m_socketKey;
	CWinSocket* m_socket;
};

inline void CICommand::setKey(string user)
{
	m_socketKey = user;
}

inline void
CICommand::setSocket(CWinSocket* socket)
{
	m_socket = socket;
}

#endif //_CICOMMAND_H_
