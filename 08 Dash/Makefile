CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-dash: cairo-dash.o
	$(CC) -o cairo-dash cairo-dash.o $(LIBS)

cairo-dash.o: cairo-dash.c
	$(CC) $(CFLAGS) cairo-dash.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-dash dash.png
