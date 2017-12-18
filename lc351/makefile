CXX = g++
CXXFLAGS = -g -Wall -std=c++11

SRCS = test.cpp solution.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = test

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^

test.o: solution.h

clean:
	rm $(EXE) $(OBJS)

