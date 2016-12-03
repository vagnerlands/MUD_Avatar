#ifndef _CGAMECOCKPIT_H_
#define _CGAMECOCKPIT_H_

#include <string>
#include <iostream>
using namespace std;

class CGameCockpit {
public:
	static CGameCockpit* instance();

	bool validateUserLogin(string socketKey, string login);

private:
	CGameCockpit();
	~CGameCockpit();
	static CGameCockpit* s_pInstance;
};

#endif //_CGAMELOGIN_H_
