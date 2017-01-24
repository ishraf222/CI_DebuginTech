cmake_minimum_required(VERSION 2.8)
project(attempt2)

include(ExternalProject)

ExternalProject_Add(catch
		GIT_REPOSITORY "https://github.com/samaursa/catch.git"
		GIT_TAG "master"

		SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/catch"
		CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/INSTALL/catch/ -H. -BBuild -Wdev

		TEST_COMMAND ""
		)

include_directories(${CMAKE_SOURCE_DIR}/INSTALL/catch/include)

enable_testing()

add_library(MathLib
		src/Vector.h
		src/Vector.cpp)
		
add_executable(MathLibTest
		src/VectorTest.cpp)
		

target_link_libraries(MathLibTest MathLib)

install(TARGETS MathLib MathLibTest
		RUNTIME DESTINATION "bin/"
		LIBRARY DESTINATION "lib/"
		ARCHIVE DESTINATION "lib/static/"
		)

		

		
		
add_test(MathLibTestRun MathLibTest)