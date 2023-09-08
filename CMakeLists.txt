
cmake_minimum_required(VERSION 3.12)
project(logger)

set(Boost_NO_WARN_NEW_VERSIONS 1)
set(Boost_NO_BOOST_CMAKE ON)


set(BOOST_USE_STATIC_LIBS OFF)
set(BOOT_USE_MULTITHREADED ON)


find_package(Boost 1.83 REQUIRED COMPONENTS log log_setup system thread)


# Find the libmosquitto library
find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQUITTO REQUIRED libmosquitto)


# Add include directories
include_directories(${Boost_INCLUDE_DIR} include)
link_directories(${Boost_LIBRARY_DIRS} )



# Include subdirectories
add_subdirectory(library)
add_subdirectory(src)


# compile the app.cpp and generate the executable file from the src folder 
add_executable(app src/app.cpp)


#add the include folder to the project "header files"
target_include_directories(app PRIVATE include)

#link the interanl libraries with the target
target_link_libraries(app PRIVATE ${Boost_LIBRARIES} Boost::log ipclib ${MOSQUITTO_LIBRARIES} simpleLogger pthread)

#target_compile_options(app PRIVATE ${MOSQUITTO_CFLAGS_OTHER})





enable_testing()








