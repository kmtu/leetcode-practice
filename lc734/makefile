CPPFLAGS = -I../test/include
CXXFLAGS = -g -Wall -std=c++11
SRC = main.cpp solution734.cpp
OBJ = $(SRC:%.cpp=%.o)
DEP = $(SRC:%.cpp=%.d)
BIN = test

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEP)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) $(CPPFLAGS) -MM $< | sed -E 's/(.*)\.o[ :]*/\1.o $@: /g' > $@

clean:
	rm -f $(BIN) $(OBJ) $(DEP)

