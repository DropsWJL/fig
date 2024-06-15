cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src FIG_TEST_SOURCE_FILES)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(fig-test ${CMAKE_CURRENT_SOURCE_DIR}/src/TestFig.cpp )
add_test(NAME fig-test COMMAND fig-test )