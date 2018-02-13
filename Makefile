SHELL = /bin/sh
CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Werror
BIN = chip8
SRC = $(wildcard *.cc)
OBJ = *.o
SRCDIR = src

all: game_loop.o
	$(CXX) $(CXXFLAGS) $(OBJ) -o chip8

game_loop.o: $(SRCDIR)/game_loop.cc chip8.o
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

chip8.o: $(SRCDIR)/chip8.cc $(SRCDIR)/chip8.h chip8_ops
	$(CXX) $(CXXFLAGS) $(SRCDIR)/chip8.cc -c

chip8_ops: $(SRCDIR)/chip8_*.cc $(SRCDIR)/chip8.h
	$(CXX) $(CXXFLAGS) $(SRCDIR)/chip8_*.cc -c

clean:
	rm -f *.o *.gch
	rm $(BIN)