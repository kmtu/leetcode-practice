CXX = g++
CXXFLAGS = -g -Wall -std=c++11
SRC = main.cpp solution.cpp test.cpp
OBJ = $(subst .cpp,.o,$(SRC))
BIN = test

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

test.o: test.h solution.h

main.o: solution.h test.h

clean:
	rm -f $(BIN) $(OBJ)

