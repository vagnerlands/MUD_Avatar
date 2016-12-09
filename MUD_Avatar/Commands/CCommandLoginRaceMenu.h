#ifndef _CCOMMANDLOGINRACEMENU_H_
#define _CCOMMANDLOGINRACEMENU_H_

#include "CICommand.h"
#include "CGameCockpit.h"

class CCommandLoginRaceMenu : public CICommand {
public:
	CCommandLoginRaceMenu(string menuOption);
	void execute();
private:
	//CGameCockpit *m_object;
	//Action m_method;
	string m_menuOption;
};

#endif
