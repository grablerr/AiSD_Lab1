cmake_minimum_required(VERSION 3.11)

project(polynomial CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(Vector STATIC "include/Vector/Vector.cpp")
add_library(Polynomial STATIC "include/Polynomial/Polynomial.cpp")
target_include_directories(Vector PUBLIC "include/Vector")
target_include_directories(Polynomial PUBLIC "include/Polynomial")

add_executable (${PROJECT_NAME} "main.cpp")
target_link_libraries(Polynomial PUBLIC Vector)
target_link_libraries(${PROJECT_NAME} Polynomial)

add_executable(tests "tests/tests.cpp")
target_link_libraries(tests Polynomial GTest::gtest_main)