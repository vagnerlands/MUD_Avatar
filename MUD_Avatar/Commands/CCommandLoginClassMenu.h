#ifndef _COMMANDLOGINCLASSMENU_H_
#define _COMMANDLOGINCLASSMENU_H_

#include "CICommand.h"
#include "CGameCockpit.h"

class CCommandLoginClassMenu : public CICommand {
public:
	CCommandLoginClassMenu(string menuOption);
	void execute();
private:
	//CGameCockpit *m_object;
	//Action m_method;
	string m_menuOption;
};

#endif
