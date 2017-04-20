#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <algorithm>
#include <fstream>


std::string GetEnv( const std::string & var ) {
     const char * val = ::getenv( var.c_str() );
     if ( val != 0 ) {
         return val;
     }

     auto home =  GetEnv("HOME");
     std::ifstream in(home +  "/.WINHOME");
     std::string buffer;
     std::getline(in,buffer);
     if(!buffer.empty()){
         return buffer;
     }

    return "";

}

std::string translateNames(const std::string& name){


    auto i =  name.find("/mnt/");
    if (i < 3){ // the mnt should be at the begin of the path

        if(name[6] != '/'){
            std::cout << "wrong formated path" << std::endl;
            return "";
        }

        std::string ret = std::string("\"") +name.substr(5,1) + ":\\" +name.substr(7) +"\"";
        std::replace( ret.begin(), ret.end(), '/', '\\');
        std::cout << i << "   " <<ret<< std::endl;
        return ret;        
    }
    i =  name.find("/home/");
    if (i < 3){ // the mnt should be at the begin of the path
        if(name[5] != '/'){
            std::cout << "home : wrong formated path" << name[5]<< std::endl;
            return "";
        }
        auto winHome = GetEnv("WINHOME");
        if(winHome.empty()){
            std::cout << "home: WINHOME not set " << name[5]<< std::endl;
        }
        std::string ret = std::string("\"") + winHome+ "\\"  +name.substr(6) +"\"";
        std::replace( ret.begin(), ret.end(), '/', '\\');
        std::cout << i << "   " <<ret<< std::endl;
        return ret;      

    }
    return name;

}

int main(int argc, char **argv){

std::ofstream out("/mnt/c/ArggsComputerEcke/cmd_start/linux/bin/win_vlc.log");

std::string cmd = "\"/mnt/c/Program Files/VideoLAN/VLC/vlc.exe\" ";
if (argc >1){
    cmd += translateNames(argv[1]);
    out << "input arg: \"" << argv[1] << "\" \n";
}
std::cout << cmd << std::endl;
out << "cmd: \"" << cmd << "\"\n";
auto t = std::thread([&](){  system(cmd.c_str() );} );
   out.close();
usleep(1000);
    return 0;
}