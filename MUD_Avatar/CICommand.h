#ifndef _CICOMMAND_H_
#define _CICOMMAND_H_

#include <string>
using namespace std;

class CICommand {
public:
	//CICommand();
	//virtual ~CICommand() = 0;
	virtual void execute() = 0;

	// set the key - to perform matching later on in the sockets
	void setKey(string user);
protected:
	string m_socketKey;
};

inline void 
CICommand::setKey(string user)
{
	m_socketKey = user;
}


#endif //_CICOMMAND_H_
