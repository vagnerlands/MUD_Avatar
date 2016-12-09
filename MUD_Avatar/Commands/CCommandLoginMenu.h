#ifndef _COMMANDLOGINMENU_H_
#define _COMMANDLOGINMENU_H_

#include "CICommand.h"
#include "CGameCockpit.h"

class CCommandLoginMenu : public CICommand {
public:
	CCommandLoginMenu(string menuOption);
	void execute();
private:
	//CGameCockpit *m_object;
	//Action m_method;
	string m_menuOption;
};

#endif
