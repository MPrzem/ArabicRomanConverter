cmake_minimum_required(VERSION 3.16)
project(Tests)

include(GoogleTest)

add_subdirectory(googletest)
add_executable(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/CorrectValuesTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrongValuesTests.cpp
)
target_link_libraries(${PROJECT_NAME} 
    gtest
    gtest_main
    RomanArabicConverter
)
gtest_discover_tests(${PROJECT_NAME})
