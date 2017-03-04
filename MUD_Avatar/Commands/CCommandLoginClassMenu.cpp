#include "CCommandLoginClassMenu.h"

CCommandLoginClassMenu::CCommandLoginClassMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginClassMenu::execute()
{
	ELoginClassMenuOption eRes = validate(m_menuOption);
	CAnsiString message;
	message.resetFormat();
	message += "\r\n";
	message.setForegroundColor(Types::EANSICOLOR_CYAN);
	switch (eRes)
	{
	case ELOGINCLASSMENUOPTION_SELECT_WARRIOR:
		CGameCockpit::instance()->setClass(m_socketKey, ECharacterClass::ECHARACTERCLASS_WARRIOR);
		message += "\r\nYou're now a Warrior!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_GENDER);
		break;
	case ELOGINCLASSMENUOPTION_SELECT_MAGE:
		message += "\r\nYou're now a Mage!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_GENDER);
		break;
	case ELOGINCLASSMENUOPTION_SELECT_PALADIN:
		message += "\r\nYou're now a Paladin!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_GENDER);
		break;
	case ELOGINCLASSMENUOPTION_SELECT_NINJA:
		message += "\r\nYou're now a Ninja!";
		message += m_socket->setState(ESOCKETSTATE_CREATE_NEW_CHAR_GENDER);
		break;
	case ELOGINCLASSMENUOPTION_SELECT_RETURN_TO_MAIN_MENU:
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

ELoginClassMenuOption 
CCommandLoginClassMenu::validate(string menuOption)
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
