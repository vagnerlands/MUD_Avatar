#include "CGameCockpit.h"

CGameCockpit * CGameCockpit::s_pInstance = NULL;

CGameCockpit * CGameCockpit::instance()
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new CGameCockpit();
	}
	return s_pInstance;
}

bool 
CGameCockpit::validateUserLogin(string socketKey, string login)
{
	cout << "Key [" << socketKey << "] inserted user " << login << " and it's valid!" << endl;
	return true;
}

CGameCockpit::CGameCockpit()
{
	// empty
}

CGameCockpit::~CGameCockpit()
{
	delete s_pInstance;
}
