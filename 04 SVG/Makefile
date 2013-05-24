CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-SVG: cairo-SVG.o
	$(CC) -o cairo-SVG cairo-SVG.o $(LIBS)

cairo-SVG.o: cairo-SVG.c
	$(CC) $(CFLAGS) cairo-SVG.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-SVG svgfile.svg
