# EV
Before running, make sure that mpc is playing and that gpsd is running.

Something like this appended to the end of your .bashrc should do. Note that nav_ui is run as sudo because it uses GPIO pins:

mpc update

mpc clear

mpc ls | mpc add

mpc random on

mpc play

sudo gpsd /dev/ttyAMA0 -F /var/run/gpsd.sock  

sudo nav_ui

