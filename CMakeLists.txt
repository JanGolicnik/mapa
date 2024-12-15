cmake_minimum_required(VERSION 3.10)

project(mapa)

set(CMAKE_C_STANDARD 11)

set(SOURCES src/mapa.c)

add_library(mapa STATIC ${SOURCES})

target_include_directories(mapa PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../marrow
)
