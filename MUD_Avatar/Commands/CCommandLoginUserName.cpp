#include "CCommandLoginUserName.h"


CCommandLoginUserName::CCommandLoginUserName(string login)
{
	//m_object = object;
	//m_method = method;
	m_login = login;
}

void CCommandLoginUserName::execute()
{
	// the result of this value will be used to decide the menu content
	bool isCharacterCreated = false;
	// validates given user
	bool bRes = CGameCockpit::instance()->validateUserLogin(m_socketKey, m_login, &isCharacterCreated);
	// user message
	CAnsiString message;
	message.resetFormat();
	message += "\r\n";
	message.setForegroundColor(Types::EANSICOLOR_CYAN);
	if (bRes)
	{
		message += "\r\n> Login accepted!\r\n";
		message += m_socket->setState(Types::ESOCKETSTATE_LOGIN_MENU);		
	} 
	else
	{
		message += "\r\n> Non existing user\r\n";
		message += "\r\n> Please, insert your user: ";
		message.setBackgroundColor(EANSICOLOR_RED);
	}
	m_socket->write(message.getData().c_str(), message.getData().length());
}
