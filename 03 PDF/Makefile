CC = gcc
CFLAGS += -Wall -O2 -c $(shell pkg-config --cflags cairo) 
LIBS += $(shell pkg-config --libs cairo) 

cairo-pdf: cairo-pdf.o
	$(CC) -o cairo-pdf cairo-pdf.o $(LIBS)

cairo-pdf.o: cairo-pdf.c
	$(CC) $(CFLAGS) cairo-pdf.c

.PHONY: clean

clean:
	rm -rf *.o *~ *.swp cairo-pdf pdffile.pdf
