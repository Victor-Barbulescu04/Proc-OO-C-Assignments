cmake_minimum_required(VERSION 3.29)
project(Alien_Hunt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Alien_Hunt
        Entity.h
        Weapon.cpp
        Weapon.h
        Entity.cpp
        Hazard.cpp
        Hazard.h
        Treasure.cpp
        Treasure.h
        Survivor.cpp
        Survivor.h
        Alien.cpp
        Alien.h
        Person.cpp
        Person.h
        Room.cpp
        Room.h
        GameController.cpp
        GameController.h
        Driver.cpp
)
