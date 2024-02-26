# pidp11-rpi5
Modified version of pidp11 for Raspberry Pi 5

This is a copy of the official PiDP-11 software modified
to run on the Raspberry Pi 5

Download the PiDP-11 manual from this link:
https://www3.ispnet.net/pidp11/PiDP-11%20Manual%20v0.2.odt

Use the installation instructions page 7 to install the
PiDP11 software with the following exceptions:

Instead of step 2 and 3 perform the following steps

...
sudo apt update
sudo apt upgrade
sudo apt install git
git clone https://github.com/rricharz/pidp11-rpi5
cp -r pidp11-rpi5/. /opt/pidp11
...

Proceed with step 4 as described in the manual

Please report problems to rricharz77@gmail.com

Thanks to the following PiDP-11 users who helped with the
modifications. Sorry if I forgot anybody, just let me know

Clem Cole
Ian Schofield
isysxp@gmail.com
John Anderson
Mike Katz
Steven A. Falco