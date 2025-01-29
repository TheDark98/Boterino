# Copyright (C) 2025 Nicolo' Sireti. All rights reserved.
#
# This software is the property of Nicolo' Sireti.  
# Copying, modifying, distributing, or unauthorized use
# is strictly prohibited without the explicit written permission
# of the owner.

cmake_minimum_required(VERSION 3.31)

project(Boterino VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Aggiungi la cartella lib e src come sottodirectory
add_subdirectory(libs)
add_subdirectory(src)
