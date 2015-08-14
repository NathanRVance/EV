nav_ui:
	gcc -o nav_ui *.c *.h -lncurses -lm -lgps
clean:
	rm -f nav_ui
