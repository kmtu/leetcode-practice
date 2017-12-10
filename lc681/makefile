CXX = g++
CXXFLAGS = -g -Wall -std=c++11

SRCS = test.cpp nct.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = test

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^

test.o: nct.h

clean:
	rm -rf $(OBJS) $(EXE)

