CXX = g++
CXXFLAGS = -g -Wall -std=c++14

SRCS = test.cpp boldtag.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = test

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^

test.o: boldtag.h

clean:
	rm -f $(EXE) $(OBJS)

