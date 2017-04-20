# project name
PROJECT(win_start)

# project version
SET( ${PROJECT_NAME}_VERSION_MAJOR 1 )
SET( ${PROJECT_NAME}_VERSION_MINOR 0 )
SET( ${PROJECT_NAME}_VERSION_PATCH 0 )

 cmake_minimum_required(VERSION 3.5)
 
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
SET(INSTALL_PREFIX "${PROJECT_SOURCE_DIR}" CACHE PATH "Prefix prepended to install directories")
SET(CMAKE_INSTALL_PREFIX "${INSTALL_PREFIX}" CACHE INTERNAL "Prefix prepended to install directories" FORCE)
  
ADD_SUBDIRECTORY(win_vlc)

