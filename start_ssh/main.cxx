#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // !_DEBUG

#include <iostream>
#include <windows.h>
#include <thread>
#include <string>
int main(int argc, char **argv)
{
  std::string comd = "bash.exe -c \"/usr/sbin/sshd -D\"";
  WinExec("lxrun /setdefaultuser root",0);
 auto t= std::thread([]() {
    Sleep(1000);
    WinExec("lxrun /setdefaultuser argg", 0);
  });

  Sleep(200);
  std::cout << comd<< std::endl;
    WinExec(comd.c_str(),0);
    t.join();
    return 0;
}
