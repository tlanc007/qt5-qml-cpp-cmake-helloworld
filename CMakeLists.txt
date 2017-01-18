cmake_minimum_required(VERSION 3.0)

# sets the PROJECT_NAME variable
project(qmlApp)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

##
### config for getting/building gtest
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
${CMAKE_BINARY_DIR}/googletest-build)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml Quick Test REQUIRED)

# enable QML debugging
string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_lower)
if(cmake_build_type_lower MATCHES "debug")
    add_definitions(-DQT_QML_DEBUG)
endif()

if (NOT NO_TESTS)
    message(STATUS "Testing enabled; add dir tests")
    include(CTest)
    enable_testing()
    set(BUILD_TESTING ON)
    add_subdirectory(tests)
else()
    message(STATUS "Tests disabled")
endif()

##
### config for getting/building gtest
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
${CMAKE_BINARY_DIR}/googletest-build)


set(SRC_LIST main.cpp)

# add an executable based on the project name and source list
add_executable(${PROJECT_NAME} ${SRC_LIST})

# links Qt5Core to the project executable
target_link_libraries(${PROJECT_NAME} Qt5::Qml Qt5::Quick)

add_subdirectory (mp)

add_custom_target(copyQmlFiles ALL
    DEPENDS ${PROJECT} ${CMAKE_SOURCE_DIR}/qml
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/qml ${CMAKE_BINARY_DIR}/qml
)

