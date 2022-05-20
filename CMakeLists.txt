cmake_minimum_required(VERSION 3.20)
project(SFML_project)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(tests)


add_executable(SFML_project src/main.cpp lib/Buttons.cpp)

target_link_libraries(SFML_project sfml-graphics)

set(SFML_DIR "include/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics window system)


