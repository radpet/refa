cmake_minimum_required(VERSION 3.7)
project(refa)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


include_directories(src)

set(SOURCES
        src/state-machine/utils/transition.h
        src/state-machine/utils/state.h
        src/state-machine/nfa/nfa.h
        src/regular-expression/regular-expression.h
        src/compiler/compiler.h
        src/parser/token/operator/operator.h
        src/parser/token/letter/letter.h
        src/parser/token/parsed-token.h
        src/parser/parser.h

        src/writer/serializable.h

        src/state-machine/utils/transition.cpp
        src/state-machine/utils/state.cpp
        src/state-machine/nfa/nfa.cpp
        src/regular-expression/regular-expression.cpp
        src/compiler/compiler.cpp
        src/parser/token/operator/operator.cpp
        src/parser/token/letter/letter.cpp
        src/parser/token/parsed-token.cpp
        src/parser/parser.cpp

        )

set(TEST_RUNNER
        test/gtest_main.cpp)

add_library(refa ${SOURCES})

add_executable(testRunner ${TEST_RUNNER})

target_link_libraries(testRunner
        refa
        gtest_main
        )



