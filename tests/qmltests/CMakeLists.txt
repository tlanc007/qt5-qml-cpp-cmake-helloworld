cmake_minimum_required(VERSION 3.0)

include(QmlTest)

#add_qml_test(. QmlTestTest)
add_test (NAME qmltestrunner
          COMMAND qmltestrunner -import ${CMAKE_BINARY_DIR} -input ${CMAKE_CURRENT_SOURCE_DIR}
)


