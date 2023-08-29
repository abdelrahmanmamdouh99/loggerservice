# add_library(WriteInFile STATIC WriteInFile.cpp)


# Define a library 

add_library(logger STATIC logger.cpp)
add_library(ipclib STATIC IPCLib.cpp)

#include the headers from include file,This allows code within the logger target to include header files from the current directory without needing to provide a full path.

target_include_directories(ipclib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

