CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Werror
BIN = chip8
SRC = $(wildcard *.cc)
OBJ = $(SRC:%.cc=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)