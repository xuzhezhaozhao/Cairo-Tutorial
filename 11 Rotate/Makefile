CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-rotate: cairo-rotate.o
	$(CC) -o cairo-rotate cairo-rotate.o $(LIBS)

cairo-rotate.o: cairo-rotate.c
	$(CC) $(CFLAGS) cairo-rotate.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-rotate rotate.png
