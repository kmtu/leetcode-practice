CPPFLAGS = -I../test/include
CXXFLAGS = -g -Wall -std=c++11
SRC = main.cpp solution294.cpp
OBJ = $(SRC:%.cpp=%.o)
DEP = $(SRC:%.cpp=%.d)
BIN = test

all: $(BIN)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CPPFLAGS) $< | sed -E 's/(.*)\.o[ :]*/\1.o $@ : /g' > $@


$(BIN): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEP)

clean:
	rm -f $(BIN) $(OBJ) $(DEP)
