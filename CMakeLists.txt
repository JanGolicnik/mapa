cmake_minimum_required(VERSION 3.10)

project(mapa)

set(CMAKE_C_STANDARD 11)

set(SOURCES main.c include/mapa.c)

add_executable(mapa ${SOURCES})

target_include_directories(mapa PUBLIC
    ${CMAKE_SOURCE_DIR}/../marrow
)
