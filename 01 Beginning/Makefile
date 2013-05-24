CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-hello: cairo-hello.o
	$(CC) -o cairo-hello cairo-hello.o $(LIBS)

cairo-hello.o: cairo-hello.c
	$(CC) $(CFLAGS) cairo-hello.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-hello hello.png
