#ifndef _CICLASS_H_
#define _CICLASS_H_

#include "CCommonTypes.h"
#include <string>
using namespace std;
using namespace Types;

// Class Interface
class CIClass
{
public:
	virtual ~CIClass() = 0;
	virtual string toString() = 0;

protected:
	ECharacterClass m_characterClass;
	string m_className;
};

#endif //_ICLASS_H_
