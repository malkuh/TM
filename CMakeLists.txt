# Malte Kuhlmann 30.9.2014
# mkuhlmann@tuebingen.mpg.de

cmake_minimum_required (VERSION 2.8)

set(PROJ_NAME      "TMsimulation" )
set(PROJ_SOURCES   "src/main.cpp" "src/TM.cpp" "src/Tape.cpp" "src/NTM.cpp")

project(${PROJ_NAME})

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_executable(${PROJ_NAME} ${PROJ_SOURCES})