cmake_minimum_required(VERSION 4.2)
project(02_11_2026)

set(CMAKE_CXX_STANDARD 20)

add_executable(02_11_2026 main.cpp
        Vehicle.cpp
        Vehicle.h
        Car.cpp
        Car.h
        Bicycle.cpp
        Bicycle.h
        Lorry.cpp
        Lorry.h
        Garage.cpp
        Garage.h)
