# Roman numerals converter
## General info
Simple program for converting roman numerals to Arabic and vice versa. It operates on basic roman numerals (up to 4999). Unit tests for the project are written in a Data-Driven approach.
Due to efficiency, the converter is based on look-up tables.

## Build
The project uses CMake build system. To build the project just type:
```
git submodule update --init // fetch google test framework
mkdir build
cd build 
cmake .. && make
ctest // if you want to run tests
```
## Structure of the project

* Converter is placed in RomanArabicConverter directory and it is built as a static library. 
* main.cpp contains an example of library usage.
* tests folders contains unit tests for the project
