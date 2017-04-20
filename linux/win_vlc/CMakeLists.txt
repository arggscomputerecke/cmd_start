

add_executable(win_vlc  main.cxx)

 
 list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
 
INSTALL(TARGETS win_vlc  
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)