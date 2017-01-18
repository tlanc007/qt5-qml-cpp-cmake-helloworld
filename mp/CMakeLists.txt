# sets the PROJECT_NAME variable
project(mpApp)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml Quick REQUIRED)

set(SRC_LIST mp.cpp)

# add an executable based on the project name and source list
add_executable(${PROJECT_NAME} ${SRC_LIST})

# links Qt5Core to the project executable
target_link_libraries(${PROJECT_NAME} Qt5::Qml Qt5::Quick)

