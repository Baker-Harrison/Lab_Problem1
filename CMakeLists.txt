cmake_minimum_required(VERSION 3.28)
project(Lab_Problem1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_Problem1 main.cpp
        src/Exceptions/FileNotFoundException.cpp
        include/Exceptions/FileNotFoundException.h
        src/Exceptions/ColorFileFormatException.cpp
        include/Exceptions/ColorFileFormatException.h
        src/Exceptions/CoordinateOutOfRangeException.cpp
        include/Exceptions/CoordinateOutOfRangeException.h
        src/Exceptions/ColorVectorOutOfRangeException.cpp
        include/Exceptions/ColorVectorOutOfRangeException.h
        include/Color.h
        src/Color.cpp)
