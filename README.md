# pidp11-rpi5
Modified version of pidp11 for Raspberry Pi 5

This is a copy of the official PiDP-11 software modified
to run on the Raspberry Pi 5

Download the PiDP-11 manual from this link:
https://www3.ispnet.net/pidp11/PiDP-11%20Manual%20v0.2.odt

Use the installation instructions page 7 to install the
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

If you want to use it on the Raspberry Pi 4, just type the following
after having completed the instructions in the manual:

    /opt/pidp11/bin/setrpi4.sh

The following command reverts back to the Raspberry
Pi 5:

    /opt/pidp11/bin/setrpi5.sh

Thanks to the following PiDP-11 users who helped with the
modifications. Sorry if I forgot anybody, just let me know

Clem Cole, Ian Schofield, isysxp@gmail.com, John Anderson,
Mike Katz,Steven A. Falco