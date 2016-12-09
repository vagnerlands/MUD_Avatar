#ifndef _CCOMMANDLOGINGENDERMENU_H_
#define _CCOMMANDLOGINGENDERMENU_H_

#include "CICommand.h"
#include "CGameCockpit.h"

class CCommandLoginGenderMenu : public CICommand {
public:
	CCommandLoginGenderMenu(string menuOption);
	void execute();
private:
	//CGameCockpit *m_object;
	//Action m_method;
	string m_menuOption;
};

#endif
