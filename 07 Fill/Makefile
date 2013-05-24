CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-fill: cairo-fill.o
	$(CC) -o cairo-fill cairo-fill.o $(LIBS)

cairo-fill.o: cairo-fill.c
	$(CC) $(CFLAGS) cairo-fill.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-fill circle.png
