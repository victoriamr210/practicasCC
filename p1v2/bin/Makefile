IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o APVs.o transition.o ftrans.o state.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/APVs.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/APVs.o: $(ODIR)/APVs.cpp $(IDIR)/APVs.hpp $(IDIR)/transition.hpp $(IDIR)/transition_function.hpp $(IDIR)/state.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/transition.o: $(ODIR)/transition.cpp $(IDIR)/transition.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/state.o: $(ODIR)/state.cpp $(IDIR)/state.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/ftrans.o: $(ODIR)/transition_function.cpp $(IDIR)/transition_function.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~

