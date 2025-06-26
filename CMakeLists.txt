cmake_minimum_required(VERSION 3.31)
project(Contact_Manager)

set(CMAKE_CXX_STANDARD 23)

add_executable(Contact_Manager main.cpp
        contact.cpp
        contact.h
        contact_manager.cpp
        contact_manager.h
        user_interface.cpp
        user_interface.h)
