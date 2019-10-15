# Smart Pen Holder's Daily Greeting Daemon

This source code is part of the smart pen holder project.  The smart pen holder has a LCD which could display useful news and information.  This source code serves as a daily update daemon which randomly pick a greeting messages for the day and broadcast the MQTT message for all the pen holders' displays.

## Technical Details

The source code is written in C/C++ using CMake build tools.  It was only tested under Ubuntu 16.04 and 18.04.  The project uses paho.mqtt.c library for its MQTT client and a prebuilt static library is included in the lib directory.

# Basic Build instructions for GNU Make
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

The MQTT server information is located in the penholder_mqtt.cpp file.  
