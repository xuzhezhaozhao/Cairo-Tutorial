CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-lines: cairo-lines.o
	$(CC) -o cairo-lines cairo-lines.o $(LIBS)

cairo-lines.o: cairo-lines.c
	$(CC) $(CFLAGS) cairo-lines.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-lines lines.png
