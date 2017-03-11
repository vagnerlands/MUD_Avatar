#include "CEngine.h"
#include "CThreadHolder.h"
#include "CEventManager.h"
#include <iostream>

using namespace std;

CEngine* CEngine::m_pInstance = nullptr;

void
CEngine::instance() {
	// just set the instance 
	m_pInstance = this;
}

CEngine::CEngine()
{

}

CEngine::~CEngine() {
	//empty implementation
}
void 
CEngine::connectionLoop()
{
	cout << "Accepting new connection..." << endl;
	m_socketServer.onConnectionEvent();
}


// @
// Execute a given command - output shall be
// @
void
CEngine::execute() 
{
	// read incoming bytes from all sockets
	m_socketServer.readIncomingMsgs();

	// execute commands from Sockets
	m_socketServer.executeCommands();

	// runs periodic functions based on system events
	CGameCockpit::instance()->run();

	// remove all dead sockets
	m_socketServer.removeCondemedSockets();
}

void 
CEngine::RunWrap() 
{
	// main loop of this application
	while (true)
	{
		// performs main logic features
		m_pInstance->execute();
	}
}

DWORD WINAPI
CEngine::ConnectionListener(LPVOID lpParameter)
{
	// remains listening for more connections "forever"
	// or till the system runs out of resources...
	while (true)
	{
		// performs main logic features
		m_pInstance->connectionLoop();
	}
}

void 
CEngine::ignition() 
{
	// first thing ever - set "this" instance to the m_pInstance
	instance();

	// initialize all singletons

	// register event listeners
	CEventManager::instance()->registerListener(EEVENTTYPE_FIRST, &CGameCockpit::ControllerMenuEventHandler);

	// creates a thread which will automatically start running  
	CThreadHolder::instance()->registerThread("thSocketListener", ConnectionListener);
	
	// create as many callbacks as necessary to static functions
	// static functions (wrapper) shall call the respective 
	// non-static method with instance()->
	RunWrap();

	// releases the <listening> thread
	CThreadHolder::instance()->destroyThread("thSocketListener");

	return ;
}
