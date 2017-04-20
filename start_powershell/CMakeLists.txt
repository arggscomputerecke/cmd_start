
add_executable(powershell_start  main.cxx)


INSTALL(TARGETS powershell_start
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)