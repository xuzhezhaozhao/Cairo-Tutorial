CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

all: cairo-sharps1 cairo-sharps2 cairo-pattern

cairo-sharps1: cairo-sharps1.o
	$(CC) -o cairo-sharps1 cairo-sharps1.o $(LIBS)

cairo-sharps2: cairo-sharps2.o
	$(CC) -o cairo-sharps2 cairo-sharps2.o $(LIBS)

cairo-pattern: cairo-pattern.o
	$(CC) -o cairo-pattern cairo-pattern.o $(LIBS)

cairo-sharps1.o: cairo-sharps1.c
	$(CC) $(CFLAGS) cairo-sharps1.c

cairo-sharps2.o: cairo-sharps2.c
	$(CC) $(CFLAGS) cairo-sharps2.c

cairo-pattern.o: cairo-pattern.c
	$(CC) $(CFLAGS) cairo-pattern.c


.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-sharps1 cairo-sharps2 cairo-pattern sharps*.png \
		pattern.png
