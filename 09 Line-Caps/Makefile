CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-caps: cairo-caps.o
	$(CC) -o cairo-caps cairo-caps.o $(LIBS)

cairo-caps.o: cairo-caps.c
	$(CC) $(CFLAGS) cairo-caps.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-caps caps.png
