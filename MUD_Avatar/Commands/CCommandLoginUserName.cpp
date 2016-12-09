#include "CCommandLoginUserName.h"


CCommandLoginUserName::CCommandLoginUserName(string login)
{
	//m_object = object;
	//m_method = method;
	m_login = login;
}

void CCommandLoginUserName::execute()
{
	bool isCharacterCreated = false;
	bool bRes = CGameCockpit::instance()->validateUserLogin(m_socketKey, m_login, &isCharacterCreated);
	if (bRes)
	{
		string message = "\r\n> Login accepted!\r\n";
		message += m_socket->setState(Types::ESOCKETSTATE_LOGIN_MENU);
		m_socket->write(message.c_str(), message.length());
	} 
	else
	{
		string message = "\r\n> Non existing user\r\n";
		message += "\r\n> Please, insert your user: ";
		m_socket->write(message.c_str(), message.length());
	}
}
