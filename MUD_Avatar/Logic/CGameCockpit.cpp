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


void CGameCockpit::setClass(string socketKey, ECharacterClass charClass)
{
	// remove it
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
