#include "CCommandLoginRaceMenu.h"

CCommandLoginRaceMenu::CCommandLoginRaceMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginRaceMenu::execute()
{
	ELoginRaceMenuOption eRes = CGameCockpit::instance()->validateRaceMenu(m_socketKey, m_menuOption);
	string message = "\r\n";
	switch (eRes)
	{
	case ELOGINRACEMENUOPTION_SELECT_HUMAN:
		message += "\r\nYou're now a Human!";
		message += m_socket->setState(ESOCKETSTATE_IN_GAME);
		break;
	case ELOGINRACEMENUOPTION_SELECT_ELF:
		message += "\r\nYou're now a Elf!";
		message += m_socket->setState(ESOCKETSTATE_IN_GAME);
		break;
	case ELOGINRACEMENUOPTION_SELECT_ORC:
		message += "\r\nYou're now a Orc!";
		message += m_socket->setState(ESOCKETSTATE_IN_GAME);
		break;
	case ELOGINRACEMENUOPTION_SELECT_DWARF:
		message += "\r\nYou're now a Dwarf!";
		message += m_socket->setState(ESOCKETSTATE_IN_GAME);
		break;
	case ELOGINRACEMENUOPTION_SELECT_RETURN_TO_MAIN_MENU:
		message += "\r\n...\r\n";
		message += m_socket->setState(ESOCKETSTATE_LOGIN_MENU);
		break;
	default:
		message += "Option is not available!\r\n> Try again: ";
		break;
	}

	m_socket->write(message.c_str(), message.length());
}
