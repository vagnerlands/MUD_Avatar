#include "CCommandLoginGenderMenu.h"

CCommandLoginGenderMenu::CCommandLoginGenderMenu(string menuOption)
{
	m_menuOption = menuOption;
}

void CCommandLoginGenderMenu::execute()
{
	ELoginGenderMenuOption eRes = validate(m_menuOption);
	CAnsiString message;
	message.resetFormat();
	message += "\r\n";
	message.setForegroundColor(Types::EANSICOLOR_CYAN);
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
		message.setBackgroundColor(Types::EANSICOLOR_RED);
		break;
	}

	m_socket->write(message.getData().c_str(), message.getData().length());
}

ELoginGenderMenuOption CCommandLoginGenderMenu::validate(string menuOption)
{
	ELoginGenderMenuOption retVal = ELOGINGENDERMENUOPTION_SELECT_GENDER_INVALID;

	if ((menuOption == "M") || (menuOption == "m"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_MALE;
	}
	else if ((menuOption == "F") || (menuOption == "f"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_FEMALE;
	}
	else if ((menuOption == "r") || (menuOption == "R"))
	{
		retVal = ELOGINGENDERMENUOPTION_SELECT_RETURN_TO_MAIN_MENU;
	}

	return retVal;
}
