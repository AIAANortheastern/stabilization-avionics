# stabilization-avionics

# Overview
Active stabilization is currently trying to create a controls system for the Karman line rocket.
Data collection and processing will eventually be handled on the new avionics board, however that will not be ready in time for active's preliminary tests.
This repository contains the short term avionics system for active's tests and potentially their proof of concept flight.
Eventually the top half of this code will hopefully be ported directly to the new avionics board.
For this reason, the code should be written in c for compatiblity purposes and abstraction away from the hardware is essential.

	
# Hardware

Our current MCU is a Teensy 3.6 running from Arduino.
We are using a 10 DoF IMU to recieve flight data, and
solenoids will be actuated to control the flow through the cold gas thrusters
	
	
# Getting Started
	
If you do not have Arduino installed, start there. I'm not going to include a link because the assumption that everyone working on this project already has some Arduino experience seems safe.

Then download Teensyduino from here: https://www.pjrc.com/teensy/td_download.html

Then clone this repository and open the code in Arduino

Before compiling and loading the board, select the Teensy 3.6 as your board
* located under Tools->Board->Teensy 3.6

Then you should be able to upload as if the Teensy were an Arduino board


# Good Practices:

Naming conventions:

To keep everything consistent and readable, some naming conventions should be used. We can discuss these if you think they're terrible, but for some basic guidelines:

* filenames should start with a capital letter, and try to have everything else be lowercase. The only caracters that should be used are A-Z, 0-9, and underscore. Avod dash or em-dash, or any other special characters.

* every .c file MUST have an accompanying header file (.h). In the header you will declare every function that's in your .c file.
	
* make sure everything in the body of your header files is within the "include guards". These ensure that the body of the header file is only included once. This makes the compiler much happier.
	
* also include extern "C" at the beginning of your header to avoid issues with Arduino being based in c++

* use camelCase for variables and snake_case for functions (that's what avionics is doing, so things will mess nicely later)