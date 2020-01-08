
cmake_minimum_required (VERSION 3.8)

project ("Cryptography")

set(-DCMAKE_GENERATOR_PLATFORM "x64")
set(-A "x64")
file(GLOB_RECURSE  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
 )

file(GLOB_RECURSE  RESOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.rc
 )

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
add_executable (${PROJECT_NAME} ${RESOURCE_FILES} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 99)