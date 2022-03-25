cmake_minimum_required(VERSION 3.20)
project(SFML_test)

set(CMAKE_CXX_STANDARD 14)

link_directories("${PROJECT_SOURCE_DIR}/bin")

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(SFML_test src/main.cpp lib/Buttons.cpp)

#target_link_libraries( SFML_test
#        openal32.dll
#        sfml-audio-2.dll
#        sfml-audio-d-2.dll
#        sfml-graphics-2.dll
#        sfml-graphics-d-2.dll
#        sfml-network-2.dll
#        sfml-network-d-2.dll
#        sfml-system-2.dll
#        sfml-system-d-2.dll
#        sfml-window-2.dll
#        sfml-window-d-2.dll
#        libgcc_s_seh-1.dll
#        libstdc++-6.dll
#        libwinpthread-1.dll
#        )


target_link_libraries(SFML_test sfml-graphics)

set(SFML_DIR "include\\SFML-2.5.1\\lib\\cmake\\SFML")

find_package(SFML 2.5 REQUIRED system graphics audio network window)


