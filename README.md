# EV
Before running, make sure xmms2 is playing and that gpsd is running.

Something like this appended to the end of your .bashrc should do:

xmms2 play
# Skip to a random song
xmms2 playlist shuffle
xmms2 next
# Start the gpsd daemon
sudo gpsd /dev/ttyAMA0 -F /var/run/gpsd.sock
nav_ui

