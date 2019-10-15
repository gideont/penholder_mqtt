cmake_minimum_required(VERSION 3.1.0)

set(projectName penHolder)

project(${projectName})
set(CMAKE_BUILD_TYPE Release)

find_package(Threads REQUIRED)

# include paho.mqtt.c lib header files
include_directories(include)
# lib include paho.mqtt.c .a static library
LINK_DIRECTORIES(lib)

add_executable(penholder_mqtt penholder_mqtt.cpp greetings.cpp)
target_link_libraries(penholder_mqtt paho-mqtt3c Threads::Threads)
