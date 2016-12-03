#ifndef _COMMONTYPES_H_
#define _COMMONTYPES_H_

namespace Types {
	typedef unsigned int TUInt32;
	typedef int TInt32;
	typedef short TInt16;
	typedef unsigned short TUInt16;
	typedef char TByte;
	typedef unsigned char TUByte;

	static const TByte* s_GAME_CONNECTION_PORT = "1234";


	enum ESocketConnectionStatus
	{
		ESOCKETCONNECTION_OK = 0,
		ESOCKETCONNECTION_FAIL,
		ESOCKETCONNECTION_TOTAL,
	};

	// what is the current state of a given socket
	enum ESocketState
	{
		ESOCKETSTATE_FIRST = 0,
		ESOCKETSTATE_LOGIN = ESOCKETSTATE_FIRST,
		ESOCKETSTATE_SELECT_CHARACTER, // 1 
		ESOCKETSTATE_CREATE_NEW_CHAR_NAME, // 2
		// more to be added here
		ESOCKETSTATE_IN_GAME, // 3
		ESOCKETSTATE_LAST
	};

	enum ESocketCommandType
	{
		ESOCKETCOMMANDTYPE_LOGIN_INJECTED,
		ESOCKETCOMMANDTYPE_TOTAL
	};
}

#endif //_COMMONTYPES_H_
