cmake_minimum_required(VERSION 3.9.0)
project(Pulsr.Window VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD TRUE)

include(GoogleTest)
enable_testing()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

option(BUILD_DOCS "TODO: Build documentation" OFF)
option(BUILD_SPECS "TODO: Build scenario's" OFF)
option(BUILD_TESTS "Build tests" OFF)

set(DIR_BASE ${CMAKE_CURRENT_SOURCE_DIR})
set(DIR_INCLUDE ${DIR_BASE}/include)
set(DIR_SPECS ${DIR_BASE}/specs)
set(DIR_SRC ${DIR_BASE}/src)
set(DIR_TESTS ${DIR_BASE}/tests)

set(TARGET_NAME ${PROJECT_NAME})
set(TARGET_SOURCES
	${DIR_SRC}/Manager.cpp
	${DIR_SRC}/Window.cpp)

add_subdirectory(${DIR_SRC})
add_subdirectory(${DIR_SPECS})
add_subdirectory(${DIR_TESTS})
