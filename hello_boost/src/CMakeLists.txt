cmake_minimum_required(VERSION 3.13)
project(hello_boost)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.74.0 REQUIRED COMPONENTS filesystem)   
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  file(
    GLOB cppfiles
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
  foreach(cppfile ${cppfiles})
    string( REPLACE ".cpp" "" name ${cppfile})
    add_executable( ${name} ${cppfile})
  endforeach()
  
  target_link_libraries(checkfile Boost::filesystem)
  install(TARGETS checkfile DESTINATION bin)
endif()

