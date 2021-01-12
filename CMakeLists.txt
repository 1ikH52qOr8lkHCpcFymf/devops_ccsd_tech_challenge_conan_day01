cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(day01)

include(GNUInstallDirs)

set(TARGET_NAME day01)

# setup Conan (if we are in Conan)
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

# find dependencies
find_package(utilslib REQUIRED)

# provide buildable target
file(GLOB SOURCE_FILES src/*.cpp)
add_executable(${TARGET_NAME} ${SOURCE_FILES})
target_include_directories(${TARGET_NAME} PRIVATE include)
target_link_libraries(${TARGET_NAME} PRIVATE utilslib)

# install target and input file
install(TARGETS ${TARGET_NAME})
install(FILES inputData/input.txt DESTINATION ${CMAKE_INSTALL_BINDIR})

# provide unit tests target (if required)
if(BUILD_UNIT_TESTS)
    # enable CTest support
    enable_testing()
    include(GoogleTest)

    # copy test input to build directory
    file(COPY inputData/input.txt DESTINATION ${CMAKE_BINARY_DIR})

    # provide test executable
    set(TARGET_NAME_UT day01-gtests)
    set(SOURCE_FILES_UT unit_tests/day1-gtests.cpp src/day1.cpp)
    add_executable(${TARGET_NAME_UT} ${SOURCE_FILES_UT})
    target_include_directories(${TARGET_NAME_UT} PRIVATE include)
    target_link_libraries(${TARGET_NAME_UT} PRIVATE utilslib gtest gtest_main)
    if(UNIX)
        target_link_libraries(${TARGET_NAME_UT} PRIVATE pthread)
    endif()

    # add unit test executable to testsuite and run it in build directory
    gtest_discover_tests(${TARGET_NAME_UT} WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
