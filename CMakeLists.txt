cmake_minimum_required(VERSION 3.17)
project(Minuit2 VERSION 5.28
              DESCRIPTION "Minuit2"
              LANGUAGES CXX;C )


# Basic Includes
# Helps with installig
include(GNUInstallDirs)

# Helps with Exporting and Creating XXXConfig.cmake scripts
include(CMakePackageConfigHelpers)


# Get Pthread options
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Configure subdirs
add_subdirectory(inc) 
add_subdirectory(src) 
#add_subdirectory(test) 
#add_subdirectory(doc) 

#Install the filedb.cmake file which contains the exports for importing
#install(EXPORT FileDBTargets NAMESPACE FileDB:: DESTINATION lib/cmake/FileDB )

#Create a packageConfig.cmake file
#configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
#  "${CMAKE_CURRENT_BINARY_DIR}/FileDBConfig.cmake"
#  INSTALL_DESTINATION "lib/cmake/FileDB"
#)

# generate the version file for the config file
#write_basic_package_version_file(
#  "${CMAKE_CURRENT_BINARY_DIR}/FileDBConfigVersion.cmake"
#  VERSION "${FileDB_VERSION_MAJOR}.${FileDB_VERSION_MINOR}"
#  COMPATIBILITY AnyNewerVersion
#)

# install it
#install(FILES
#  ${CMAKE_CURRENT_BINARY_DIR}/FileDBConfig.cmake
 # ${CMAKE_CURRENT_BINARY_DIR}/FileDBConfigVersion.cmake
 # DESTINATION lib/cmake/FileDB
#)

# export package. Does nothing by default, but
# can have uses in specially set up configurations
export(PACKAGE minuit)

