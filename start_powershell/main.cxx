#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // !_DEBUG

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  
auto cmd=string("powershell.exe -ExecutionPolicy Bypass -Command ") + argv[1];
    std::cout << cmd << std::endl;
    WinExec(cmd.c_str(),0);
    return 0;
}
