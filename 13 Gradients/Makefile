CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

all: cairo-linear-gradients cairo-radial-gradients

cairo-linear-gradients: cairo-linear-gradients.o
	$(CC) -o cairo-linear-gradients cairo-linear-gradients.o $(LIBS)

cairo-radial-gradients: cairo-radial-gradients.o
	$(CC) -o cairo-radial-gradients cairo-radial-gradients.o $(LIBS)

cairo-linear-gradients.o: cairo-linear-gradients.c
	$(CC) $(CFLAGS) cairo-linear-gradients.c

cairo-radial-gradients.o: cairo-radial-gradients.c
	$(CC) $(CFLAGS) cairo-radial-gradients.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp *.png cairo-linear-gradients cairo-radial-gradients
