#ifndef CICLIENTSOCKET_H_
#define CICLIENTSOCKET_H_

#include <string>
using namespace std;

// interface class - nothing more
class CIClientSocket {
	virtual string read() = 0;
	virtual void write(string data) = 0;
};

#endif //CICLIENTSOCKET_H_
