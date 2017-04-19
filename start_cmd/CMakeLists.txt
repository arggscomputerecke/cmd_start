
add_executable(cmd_start  main.cxx)


INSTALL(TARGETS cmd_start  
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)