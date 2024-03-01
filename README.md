# pidp11-rpi5
Modified version of the pidp11 software for the Raspberry Pi 5

This is a copy of the official PiDP-11 software modified
to run on the Raspberry Pi 5

Download the PiDP-11 manual from this link:
http://pidp.net/pidp11/PiDP-11_Manual.odt

Use the installation instructions on page 7 to install the
PiDP11 software with the following exceptions:

Instead of step 2 and 3 perform the following steps


    sudo apt update
    sudo apt upgrade
    sudo apt install git
    cd
    git clone https://github.com/rricharz/pidp11-rpi5
    sudo cp -r pidp11-rpi5/.  /opt/pidp11
    rm -r pidp11-rpi5
    cd /opt/pidp11

Proceed with step 4 as described in the manual

Please report problems to rricharz77@gmail.com

This software has been modified to allow any user, not
just pi, to install it, and to run on the 64-bit OS. It might
therefore also be of interest for Raspberry 4 users running
the 64-bit version of the OS.

The following files are modified as compared to the original version:

Fixed to work for any user, not just pi

    /opt/pidp11/bin/makeball.sh
    /opt/pidp11/bin/makesys.sh
    /opt/pidp11/install/install.sh

Fixed to work with 64 OS:

    /opt/pidp11/src/02.3_simh/4.x+realcons/src/PDP11/pdp11_cpu.c
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/PDP11/pdp11_dl.c
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/PDP11/pdp11_io_lib.c
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/PDP11/pdp11_td.c
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/quickmake
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/scp.c
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/scp.h
    /opt/pidp11/src/02.3_simh/4.x+realcons/src/sim_tmxr.c 
    /opt/pidp11/src/11_pidp_server/pidp11/gpio.c
    /opt/pidp11/src/11_pidp_server/pidp11/makefile
    /opt/pidp11/src/11_pidp_server/scanswitch/Makefile
    /opt/pidp11/src/11_pidp_server/scanswitch/scansw.c

It is also possible to install this software on a Raspberry
Pi 4 with 64-bit OS, but you need to follow
[these instructions](rpi4.txt)
very carefully. Make a backup copy of your SD card before
attempting to install this software on a Raspberry Pi 4.

Thanks to the following PiDP-11 users who helped with the
modifications. Sorry if I forgot anybody, just let me know

Clem Cole, Ian Schofield, John Anderson, Mike Katz,Steven A. Falco

The contributions in this repository are distributed in the hope that they will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. 
Please report any problems or suggestions for improvements to r77@bluewin.ch



