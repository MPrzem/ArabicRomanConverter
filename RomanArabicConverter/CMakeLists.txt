cmake_minimum_required(VERSION 3.16)
project(RomanArabicConverter)

add_library(${PROJECT_NAME}  STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Roman_Arabic_conv.cpp        
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR} 
)
message(WARRNING  ${CMAKE_CURRENT_SOURCE_DIR})

