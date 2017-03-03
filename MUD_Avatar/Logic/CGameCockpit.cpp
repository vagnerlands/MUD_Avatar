#include "CGameCockpit.h"

CGameCockpit* CGameCockpit::s_pInstance = NULL;

CGameCockpit* 
CGameCockpit::instance()
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new CGameCockpit();
	}
	return s_pInstance;
}

bool 
CGameCockpit::validateUserLogin(string socketKey, string login, bool* isCharacterCreated)
{
	bool retVal = false;
	for (list<CPerson*>::iterator it = m_userDB.begin(); it != m_userDB.end(); it++)
	{		
		if ((*it)->getUser() == login)
		{
			cout << "Key [" << socketKey << "] typed " << login << " and it's valid!" << endl;
			retVal = true;
			*isCharacterCreated = (*it)->isCharacterCreated();
		}
	}

	if (!retVal)
		cout << "Key [" << socketKey << "] typed " << login << ", this user is not valid!" << endl;
	
	return retVal;
}

ELoginMenuOption 
CGameCockpit::validateMenu(string socketKey, string menuOption)
{
	ELoginMenuOption retVal = ELOGINMENUOPTION_INVALID;

	if (menuOption == "1")
	{
		retVal = ELOGINMENUOPTION_CREATE_NEW_CHARACTER;
	} 
	else if (menuOption == "2")
	{
		retVal = ELOGINMENUOPTION_START_GAME;
	} 
	else if (menuOption == "3")
	{
		retVal = ELOGINMENUOPTION_LEAVE_GAME;
	}

	return retVal;
}

ELoginClassMenuOption CGameCockpit::validateClassMenu(string socketKey, string menuOption)
{
	ELoginClassMenuOption retVal = ELOGINCLASSMENUOPTION_SELECT_INVALID;
	if (menuOption == "1")
	{
		retVal = ELOGINCLASSMENUOPTION_SELECT_WARRIOR;
	}
	else if (menuOption == "2")
	{
		retVal = ELOGINCLASSMENUOPTION_SELECT_MAGE;
	}
	else if (menuOption == "3")
	{
		retVal = ELOGINCLASSMENUOPTION_SELECT_PALADIN;
	}
	else if (menuOption == "4")
	{
		retVal = ELOGINCLASSMENUOPTION_SELECT_NINJA;
	}
	else if ((menuOption == "r") || (menuOption == "R"))
	{
		retVal = ELOGINCLASSMENUOPTION_SELECT_RETURN_TO_MAIN_MENU;
	}
	return retVal;
}

ELoginRaceMenuOption CGameCockpit::validateRaceMenu(string socketKey, string menuOption)
{
	ELoginRaceMenuOption retVal = ELOGINRACEMENUOPTION_SELECT_INVALID;
	if (menuOption == "1")
	{
		retVal = ELOGINRACEMENUOPTION_SELECT_HUMAN;
	}
	else if (menuOption == "2")
	{
		retVal = ELOGINRACEMENUOPTION_SELECT_ELF;
	}
	else if (menuOption == "3")
	{
		retVal = ELOGINRACEMENUOPTION_SELECT_ORC;
	}
	else if (menuOption == "4")
	{
		retVal = ELOGINRACEMENUOPTION_SELECT_DWARF;
	}
	else if ((menuOption == "r") || (menuOption == "R"))
	{
		retVal = ELOGINRACEMENUOPTION_SELECT_RETURN_TO_MAIN_MENU;
	}
	return retVal;
}

void CGameCockpit::setClass(string socketKey, ECharacterClass charClass)
{
	// remove it
}

ELoginGenderMenuOption CGameCockpit::validateGenderMenu(string socketKey, string menuOption)
{
	ELoginGenderMenuOption retVal = ELOGINGENDERMENUOPTION_SELECT_GENDER_INVALID;

	if ((menuOption == "M") || (menuOption == "m"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_MALE;
	}
	else if ((menuOption == "F") || (menuOption == "f"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_FEMALE;
	}
	else if ((menuOption == "r") || (menuOption == "R"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_RETURN_TO_MAIN_MENU;
	}

	return retVal;
}


CGameCockpit::CGameCockpit()
{
	CPerson* user1 = new CPerson("vagner", false, ECHARACTERGENDER_MALE, ECHARACTERRACE_HUMAN);
	CPerson* user2 = new CPerson("chen", false, ECHARACTERGENDER_FEMALE, ECHARACTERRACE_HUMAN);
	m_userDB.push_back(user1);
	m_userDB.push_back(user2);
}

CGameCockpit::~CGameCockpit()
{
	for (list<CPerson*>::iterator it = m_userDB.begin(); it != m_userDB.end(); it++)
	{
		delete *it;
		*it = NULL;
	}
	delete s_pInstance;
}
