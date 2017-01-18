cmake_minimum_required(VERSION 3.0)

# sets the PROJECT_NAME variable
project(qmlApp)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

set(SRC_LIST main.cpp)

# add an executable based on the project name and source list
add_executable(${PROJECT_NAME} ${SRC_LIST})

# links Qt5Core to the project executable
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Qml Qt5::Quick)

add_subdirectory (mp)

add_custom_target(copyQmlFiles ALL
    DEPENDS ${PROJECT} ${CMAKE_SOURCE_DIR}/qml
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/qml ${CMAKE_BINARY_DIR}/qml
)

