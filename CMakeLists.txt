cmake_minimum_required(VERSION 3.16)
project(RomanArabicConverterApp)
enable_testing()

add_subdirectory(RomanArabicConverter)
add_subdirectory(tests)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    RomanArabicConverter
)
