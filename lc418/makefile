CXX = g++
CPPFLAGS = -g -Wall -std=c++11
LDFLAGS = -g -Wall

SRCS = test.cpp sentence-screen-fitting.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

EXE = test

all: $(EXE)

test: $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@

test.o: sentence-screen-fitting.h

clean:
	rm -f $(OBJS) $(EXE)

