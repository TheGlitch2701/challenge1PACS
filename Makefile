CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations -Ilib/muparserx/parser

EXEC     =  GradientDescent
LDFLAGS ?= -Llib/muparserx/mybuild/
LIBS  ?= -lmuparserx

all: $(EXEC)

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC): %: %.o 
	$(CXX) $(CXXFLAGS) Point.cpp $(LDFLAGS) $< $(LIBS) -o $@

clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
	$(RM) GradientDescent