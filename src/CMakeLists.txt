# Copyright (C) 2025 Nicolo' Sireti. All rights reserved.
#
# This software is the property of Nicolo' Sireti.  
# Copying, modifying, distributing, or unauthorized use
# is strictly prohibited without the explicit written permission
# of the owner.

add_executable(Boterino main.cpp)

# Link heads
target_include_directories(Boterino PRIVATE ${cpr_SOURCE_DIR}/include
                                            ${dpp_SOURCE_DIR}/include
                                            ${nlohmann_json_SOURCE_DIR}/single_include
                                            )

# Link libs
target_link_libraries(Boterino PRIVATE cpr
                                       dpp
                                       )

set_target_properties(Boterino PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)