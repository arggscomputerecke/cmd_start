
add_executable(cmd_ssh  main.cxx)


INSTALL(TARGETS cmd_ssh  
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)