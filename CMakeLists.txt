cmake_minimum_required(VERSION 3.28)
project(MatMul)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatMul main.cpp
        Matrix.cpp
        Matrix.h
)
