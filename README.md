# EV
Before running, make sure xmms2 is playing and that gpsd is running.

Something like this appended to the end of your .bashrc should do. Note that nav_ui is run as sudo because it uses GPIO pins:

xmms2 play
xmms2 playlist shuffle
xmms2 next
sudo gpsd /dev/ttyAMA0 -F /var/run/gpsd.sock
sudo nav_ui

