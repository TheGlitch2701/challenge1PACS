CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations -Imuparser/include

EXEC     =  GradientDescent
#EXEC     = mainGetPotLambda
#EXEC     = mainMuParserJSON
LDFLAGS ?= -L../pacs-examples/Examples/lib
LIBS  ?= -lmuparser

all: $(EXEC)

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
