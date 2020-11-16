IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o sumFPR.o basicFPR.o prodFPR.o powFPR.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp  $(IDIR)/prodFPR.hpp $(IDIR)/sumFPR.hpp $(IDIR)/powFPR.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/powFPR.o: $(ODIR)/powFPR.cpp $(IDIR)/powFPR.hpp $(IDIR)/FPR.hpp $(IDIR)/prodFPR.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/prodFPR.o: $(ODIR)/prodFPR.cpp $(IDIR)/prodFPR.hpp $(IDIR)/FPR.hpp $(IDIR)/sumFPR.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/sumFPR.o: $(ODIR)/sumFPR.cpp $(IDIR)/sumFPR.hpp $(IDIR)/FPR.hpp $(IDIR)/basicFPR.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/basicFPR.o: $(ODIR)/basicFPR.cpp $(IDIR)/basicFPR.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~

