#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // !_DEBUG

#include <iostream>
#include <windows.h>


int main(int argc, char **argv)
{
  std::cout << argv[1]<< std::endl;
    WinExec(argv[1],0);
    return 0;
}
