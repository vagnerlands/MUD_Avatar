#include "CCommandLoginMenu.h"

CCommandLoginMenu::CCommandLoginMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginMenu::execute()
{
	ELoginMenuOption eRes = CGameCockpit::instance()->validateMenu(m_socketKey, m_menuOption);
	string message = "\r\n";
	switch (eRes) 
	{
		case ELOGINMENUOPTION_CREATE_NEW_CHARACTER:
			message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_CLASS);
			break;
		case ELOGINMENUOPTION_START_GAME:
			message += "Entering the game...\r\n\r\n";
			message += m_socket->setState(ESOCKETSTATE_IN_GAME);
			break;
		case ELOGINMENUOPTION_LEAVE_GAME:
			message = "Goodbye...\r\n";
			m_socket->write(message.c_str(), message.length());
			m_socket->closeSocket();
			break;
		default:
			message += "Option is not available!\r\n> Choose: ";
			break;
	}
		
	m_socket->write(message.c_str(), message.length());
}
