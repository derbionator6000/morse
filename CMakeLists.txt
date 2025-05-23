cmake_minimum_required(VERSION 3.10)

project(morse 
    VERSION 1.0 
    DESCRIPTION "Morse Code Converter Application")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Besonderheiten fuer Debug- und Release
set(CMAKE_C_FLAGS_DEBUG_INIT "-Wall -g3 -O0")
set(CMAKE_C_FLAGS_RELEASE_INIT "-Wall -O3")

# Includes
include_directories(${PROJECT_SOURCE_DIR}/include)

# Die Datei die das main enthaelt hier eintragen
add_executable(${PROJECT_NAME} 
    src/main.c
    src/io.c
    src/morse.c
    src/options.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)