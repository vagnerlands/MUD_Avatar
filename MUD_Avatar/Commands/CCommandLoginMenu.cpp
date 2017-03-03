#include "CCommandLoginMenu.h"

CCommandLoginMenu::CCommandLoginMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginMenu::execute()
{
	ELoginMenuOption eRes = CGameCockpit::instance()->validateMenu(m_socketKey, m_menuOption);
	CAnsiString message;
	message.resetFormat();
	message += "\r\n";
	message.setForegroundColor(Types::EANSICOLOR_CYAN);
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
			message += "Goodbye...\r\n";
			m_socket->write(message.getData().c_str(), message.getData().length());
			//m_socket->closeSocket();
			m_socket->recycle();
			break;
		default:			
			message += "Option is not available!\r\n> Choose: ";
			message.setBackgroundColor(Types::EANSICOLOR_RED);
			break;
	}
		
	if (m_socket != NULL)
	{
		m_socket->write(message.getData().c_str(), message.getData().length());
	}
}
