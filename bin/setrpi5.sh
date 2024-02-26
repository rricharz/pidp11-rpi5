# setrpi5 - patch to convert the software
# to run on the Raspberry Pi 5

sed -i 's/gpiochip0/gpiochip4/g' /opt/pidp11/src/11_pidp_server/pidp11/gpio.c
sed -i 's/gpiochip0/gpiochip4/g' /opt/pidp11/src/11_pidp_server/scanswitch/scansw.c
cd /opt/pidp11/src
sudo ./makeserver.sh
cd 11_pidp_server/scanswitch
sudo make