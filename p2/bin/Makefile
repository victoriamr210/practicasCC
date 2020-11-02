IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o machine.o state.o transition.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/machine.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/machine.o: $(ODIR)/machine.cpp $(IDIR)/machine.hpp $(IDIR)/tape.hpp $(IDIR)/state.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/state.o: $(ODIR)/state.cpp $(IDIR)/state.hpp $(IDIR)/transition.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/transition.o: $(ODIR)/transition.cpp $(IDIR)/transition.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~

