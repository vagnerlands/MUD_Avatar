#include "CCommandLoginRaceMenu.h"

CCommandLoginRaceMenu::CCommandLoginRaceMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginRaceMenu::execute()
{
	ELoginRaceMenuOption eRes = validate(m_menuOption);
	CAnsiString message;
	message.resetFormat();
	message += "\r\n";
	message.setForegroundColor(Types::EANSICOLOR_CYAN);
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
		message.setBackgroundColor(Types::EANSICOLOR_RED);
		break;
	}

	m_socket->write(message.getData().c_str(), message.getData().length());
}

ELoginRaceMenuOption 
CCommandLoginRaceMenu::validate(string menuOption)
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
