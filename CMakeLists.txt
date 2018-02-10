cmake_minimum_required(VERSION 3.9)
project(AirportManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(AirportManager src/main.cpp src/Worker.cpp src/Worker.h src/Pilot.cpp src/Pilot.h src/Dispatcher.cpp src/Dispatcher.h src/Aircraft.cpp src/Aircraft.h src/AircraftOnParking.cpp src/AircraftOnParking.h src/AircraftOnFly.cpp src/AircraftOnFly.h src/Airport.cpp src/Airport.h src/AirportManager.cpp src/AirportManager.h)