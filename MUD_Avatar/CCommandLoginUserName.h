#ifndef _CCOMMANDLOGINUSERNAME_H_
#define _CCOMMANDLOGINUSERNAME_H_

#include "CICommand.h"
#include "CGameCockpit.h"

class CCommandLoginUserName : public CICommand {
public:
	//typedef void(CGameCockpit:: *Action)();

	CCommandLoginUserName(/*CGameCockpit *object, Action method*/ string login);
	void execute()
	{
		CGameCockpit::instance()->validateUserLogin(m_socketKey, m_login);
		//(m_object-> *m_method)();
	}

private:
	//CGameCockpit *m_object;
	//Action m_method;
	string m_login;
};

#endif //_CCOMMANDLOGINUSERNAME_H_
