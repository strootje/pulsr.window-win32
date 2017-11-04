cmake_minimum_required(VERSION 2.8.12)
project(PackageTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD TRUE)

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_NAME Grawlog.PackageTests)
set(TEST_SOURCES
	${BASE_DIR}/Program.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${TEST_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_NAME} ${CONAN_LIBS})
