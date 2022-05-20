include_directories(../libs/googletest-main/googletest ../libs/googletest-main/googletest/include)

add_executable(run_basic_gtest sfml_check.cpp font_check.cpp basic_check.cpp)

target_link_libraries(run_basic_gtest sfml-graphics)
set(SFML_DIR "../../include/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system)


target_link_libraries(run_basic_gtest gmock gtest pthread gtest_main)