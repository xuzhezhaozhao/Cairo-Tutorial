CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

all: cairo-transparancy cairo-puff

cairo-transparancy: cairo-transparancy.o
	$(CC) -o cairo-transparancy cairo-transparancy.o $(LIBS)

cairo-puff: cairo-puff.o
	$(CC) -o cairo-puff cairo-puff.o $(LIBS)

cairo-transparancy.o: cairo-transparancy.c
	$(CC) $(CFLAGS) cairo-transparancy.c

cairo-puff.o: cairo-puff.c
	$(CC) $(CFLAGS) cairo-puff.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp *.png cairo-transparancy cairo-puff
