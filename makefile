CXX = g++
CXXFLAGS = -g -Wall -std=c++11

SRCS = test.cpp prod.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = test

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^

test.o: prod.h

clean:
	rm -rf $(EXE) $(OBJS)

