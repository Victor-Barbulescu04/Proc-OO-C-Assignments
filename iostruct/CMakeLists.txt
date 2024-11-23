cmake_minimum_required(VERSION 3.26)
project(iostruct C)

set(CMAKE_C_STANDARD 17)

add_executable(iostruct main.c
        reportio.c
        readevents.c)
