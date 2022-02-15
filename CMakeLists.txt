cmake_minimum_required(VERSION 3.20)
project(SFML_test)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -DSFML_STATIC")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(SFML_test main.cpp)

set(SFML_DIR "C:\\Users\\ashim\\Desktop\\SFML\\lib\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(SFML_test sfml-graphics)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


