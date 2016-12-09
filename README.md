# MUD_Avatar
   ___            __             __  _____  _____ 
  / _ |_  _____ _/ /____ _____  /  |/  / / / / _ \
 / __ | |/ / _ `/ __/ _ `/ __/ / /|_/ / /_/ / // /
/_/ |_|___/\_,_/\__/\_,_/_/   /_/  /_/\____/____/ 
                                                  

Simple application Multi User Domain like.
This application was developed by Vagner Landskron - avatarch@gmail.com
As a proof for a particular solution in a project.

Feel free to use as you like.

====================================================
     _________________
____/ List of Changes:
----------------------

- For now - it's only compilable in Windows environment. Soon to be portated to Linux as well.
- CGameCockpit shall control the decision flow of this application;
- Let CWinSocket handle all TCP read/write functions;
- CWinSocket holds a static SOCKET for the listening;
- Thread for the listening operations;
- Mutex for shared resources;

     ____________
____/ To do List:
-----------------

- Serializable classes (with backward compability);
- Library for file loading/treatment;
- Users loading;
- Rooms loading;
- Objects loading;
