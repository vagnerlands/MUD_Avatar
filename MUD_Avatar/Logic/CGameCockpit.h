#ifndef _CGAMECOCKPIT_H_
#define _CGAMECOCKPIT_H_

#include <string>
#include <iostream>
#include <list>
#include "CWinSocket.h"
#include "CPerson.h"
#include "CControllerMenu.h"
#include "IEvent.h"

using namespace std;

class CGameCockpit {
public:
	static CGameCockpit* instance();

	bool validateUserLogin(string socketKey, string login, bool* isCharacterCreated);

	void setClass(string socketKey, ECharacterClass charClass);

	static void ControllerMenuEventHandler(IEvent* ev);

	void run();
	CControllerMenu m_CtrlMenu;
private:
	CGameCockpit();
	~CGameCockpit();
	static CGameCockpit* s_pInstance;

	list<CPerson*> m_userDB;

	
};

#endif //_CGAMELOGIN_H_
