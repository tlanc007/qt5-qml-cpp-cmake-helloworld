cmake_minimum_required(VERSION 3.0)

include(QmlTest)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Qml Quick QuickTest REQUIRED)

# doesn't seem to be used by build
set(QUICK_TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_LIST tst_math.cpp)
set(BINARY tst_math)

add_executable (${BINARY} ${SRC_LIST})

# links Qt5Core to the project executable
target_link_libraries(${BINARY} Qt5::Widgets Qt5::QuickTest Qt5::Qml Qt5::Quick)

#add_qml_test(. QmlTestTest)
#add_test (NAME qmltestrunner
#          COMMAND qmltestrunner -import ${CMAKE_BINARY_DIR} -input ${CMAKE_CURRENT_SOURCE_DIR}
#)

add_test(NAME ${BINARY}
         COMMAND ${BINARY} -input ${CMAKE_CURRENT_SOURCE_DIR}
)

