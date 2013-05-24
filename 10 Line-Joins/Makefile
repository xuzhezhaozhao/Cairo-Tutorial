CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-joins: cairo-joins.o
	$(CC) -o cairo-joins cairo-joins.o $(LIBS)

cairo-joins.o: cairo-joins.c
	$(CC) $(CFLAGS) cairo-joins.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-joins joins.png
