IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o APV.o transition.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/APV.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/APV.o: $(ODIR)/APV.cpp $(IDIR)/APV.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/transition.o: $(ODIR)/transition.cpp $(IDIR)/transition.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~

