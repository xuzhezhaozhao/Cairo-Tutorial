CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) $(shell pkg-config --cflags gtk+-2.0)
LIBS += $(shell pkg-config --libs cairo) $(shell pkg-config --libs gtk+-2.0)

cairo-gtk: cairo-gtk.o
	$(CC) -o cairo-gtk cairo-gtk.o $(LIBS)

cairo-gtk.o: cairo-gtk.c
	$(CC) $(CFLAGS) cairo-gtk.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-gtk
