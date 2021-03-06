# Introduction

This library contains low level modules designed to interface with STM32F103 perihperals.
These modules are designed to be compatible with other low level common libraries and 
microcontroller modules as demonstrated on the [mainpage](https://github.com/stuianna/globLib).

There are two options for flashing binaries onto the target MCU, using a USB bootloader or with the ST-LinkV2 programmer. A template for each options is location in the template directories. Note that the bootloader has to be flashed to the MCU at least one with the ST-LinkV2 programmer before it can be used.

Development has been tested on Ubuntu 16.04LTS and 18.04LTS.

# Installation

## Toolchain

The GNU arm embedded tool chain https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads is used to develop this library. It can be installed with

```
sudo apt-get update
sudo apt-get install gcc-arm-none-eabi
```

Installation can be checked with 

```
arm-none-eabi-gcc -v
```

Which should print something like this (or newer)

```
gcc version 4.9.3 (prerelease) (15:4.9.3+svn231177-1) 
```

## subsection Debugger

Open OCD http://openocd.org/ is used to flash binaries to the target and debug.

To install:

- Download the source from sourceforge (link in Openocd website)
- Extract file into home directory
- run:

```
sudo apt-get install libusb-1.0-0-dev
./configure --enable-stlink
./make
./sudo make install
```

Check the installation with

```
openocd -v
```

Which should print

```
Open On-Chip Debugger 0.10.0
Licensed under GNU GPL v2
For bug reports, read
    http://openocd.org/doc/doxygen/bugs.html
```
## STLINKV2

STLINK V2 http://www.st.com/en/development-tools/st-link-v2.html provides a hardware interface between the PC and MCU.

To use STLINK V2, the following needs to be done:

Make a new file
```
sudo vim /etc/udev/rules.d/99-stlink.rules
```
Add the following:
```
ATTRS{idVendor}=="0483",ATTRS{idProduct}=="3748",MODE="0666"
```
Reload the rules
```
sudo udevadm control --reload-rules
```
Plug in the programmer (STLINK) and ensure it is working by using
```
lsusb
```
The list should include
```
BUS xxx Device XXX: ID 0483:3748 STMicroelectronics ST-LINK/V2
```
## DFU Programmer

A DFU (device firmware update) programmer is used to communicate with the USB bootloader on the device.

dfu-util http://dfu-util.sourceforge.net/ can be installed with:

```
sudo apt-get install dfu-util
```
Udev should be configured to change file permissions for STM devices in DFU mode. Create a new file with

```
sudo vim /etc/udev/rules.d/99-dfu.rules
```
Add the following
```
# STMicroelectronics STM Device in DFU Mode (and clones)
SUBSYSTEM=="usb", ATTR{idVendor}=="0483", ATTR{idProduct}=="df11", MODE="660", GROUP="plugdev"
```

Reload the rules:
```
sudo udevadm control --reload-rules
```

## Dialout

The user needs to be a member of group "dialout" to access the tty ports. This can be done with

```
sudo adduser $USER dialout
```

# Usage

This assumes a complete copy of glob_lib is available locally. 

There are two project templates located in the templates directory. Each of these templates contain instructions specific
for their usage.
