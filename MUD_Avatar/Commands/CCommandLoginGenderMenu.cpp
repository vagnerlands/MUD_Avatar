#include "CCommandLoginGenderMenu.h"

CCommandLoginGenderMenu::CCommandLoginGenderMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginGenderMenu::execute()
{
	ELoginGenderMenuOption eRes = CGameCockpit::instance()->validateGenderMenu(m_socketKey, m_menuOption);
	string message = "\r\n";
	switch (eRes)
	{
	case ELOGINGENDERMENUOPTION_SELECT_FEMALE:
		message += "\r\nOk Milady!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_RACE);
		break;
	case ELOGINGENDERMENUOPTION_SELECT_MALE:
		message += "\r\nOk Sir!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_RACE);
		break;
	case ELOGINGENDERMENUOPTION_SELECT_RETURN_TO_MAIN_MENU:
		message += "\r\n...\r\n";
		message += m_socket->setState(ESOCKETSTATE_LOGIN_MENU);
		break;
	default:
		message += "Option is not available!\r\n> Try again: ";
		break;
	}

	m_socket->write(message.c_str(), message.length());
}
