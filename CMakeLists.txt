cmake_minimum_required(VERSION 3.2)     

project(Hackertyper CXX)            

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE Hackertyper.cpp)       

set(SOURCE_LIB MainWindow.cpp MainWindow.h Model.cpp Model.h String.cpp String.h)            

add_library(foo STATIC ${SOURCE_LIB}) 

set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main ${SOURCE_EXE})       

target_link_libraries(main foo)  

target_link_libraries(main sfml-graphics sfml-audio)