#ifndef _CGAMECOCKPIT_H_
#define _CGAMECOCKPIT_H_

#include <string>
#include <iostream>
#include <list>
#include "CWinSocket.h"
#include "CPerson.h"

using namespace std;

class CGameCockpit {
public:
	static CGameCockpit* instance();

	bool validateUserLogin(string socketKey, string login, bool* isCharacterCreated);
	ELoginMenuOption validateMenu(string socketKey, string menuOption);
	ELoginClassMenuOption validateClassMenu(string socketKey, string menuOption);
	ELoginGenderMenuOption validateGenderMenu(string socketKey, string menuOption);
	ELoginRaceMenuOption CGameCockpit::validateRaceMenu(string socketKey, string menuOption);

private:
	CGameCockpit();
	~CGameCockpit();
	static CGameCockpit* s_pInstance;

	list<CPerson*> m_userDB;
};

#endif //_CGAMELOGIN_H_
