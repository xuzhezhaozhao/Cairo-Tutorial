CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-png: cairo-png.o
	$(CC) -o cairo-png cairo-png.o $(LIBS)

cairo-png.o: cairo-png.c
	$(CC) $(CFLAGS) cairo-png.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-png image.png
