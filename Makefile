CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I./include -Wno-conversion-null -Wno-deprecated-declarations -Ilib/muparserx/parser
EXEC     =  GradientDescent
LDFLAGS ?= -Llib/muparserx/mybuild/ # this is a very stange path! Use always a . to indicate relative paths 
# LDFLAGS ?= -L./lib/muparserx/mybuild/ like here
LIBS  ?= -lmuparserx

all: $(EXEC)

%.o: %.cpp
	$(RM) GradientDescent
	$(CXX) -c src/Point.cpp src/GradientDescentSolver.cpp $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC): %: %.o 
	$(CXX) $(CXXFLAGS) Point.o GradientDescentSolver.o $(LDFLAGS) $< $(LIBS) -o $@
	make clean
	clear
	./GradientDescent

clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
	$(RM) GradientDescent
	$(RM) plot_script/points.dat
	clear
