nav_ui:
	gcc -ggdb -o nav_ui *.c *.h -lncurses -lm -lgps -l wiringPi -lpthread
clean:
	rm -f nav_ui
