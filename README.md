# qt5-qml-cpp-cmake-helloworld
Simple hello world example using qt5, qml, c++, cmake

## Table of Contents

* [Background](#background)
* [Build Instructions](#buildinstructions)
* [hw.qml](#hw.qml)
* [main.cpp](#main.cpp)
* [CMakeLists.txt](#cmakelists.txt)


## Background
This is a simple helloworld example: 

* opens up a window an displays the text "Hello world!"
* The window and text are configured through a qt5 qml file.
* a simple C++ main is used to start things up
* cmake is used to configure the build

I spent a number of hours searching for something like this.  An example that showed the barebones of what was needed to have C++ make use of a qt5 qml file.  But most of the examples presumed the use of **gmake** (which is the primary build system for Qt).  For my need, I wanted to see how to things needed to be set up for **cmake**.

As I didn't find what I was looking for, I ended up writing this example from bits of info I could find.

## Build Instructions
1. mkdir build
2. cd build
3. cmake ..
4. make
5. run qmlApp

For osx (macOS) users for step 3 you may need something like:

```
cmake .. -DCMAKE_PREFIX_PATH="$(brew --prefix qt5 )" 
```

## hw.qml
`qml/hw.qml` is a simple qml file that creates a rectangle and displays the text "Hello world!".

## main.cpp
`main.cpp` sets up Qt5 and opens up the `hw.qml` to have the GUI display.

## CMakeLists.txt
This is the **cmake** config file.

Of note: 

* it looks for the appropriate Qt5 packages
   * `find_packages`
* what libraries to link with 
   * `target_link_libraries` 
* copy the `qml` directory locally