# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: demo.o MathLib.cpp.o MathLib.h.o
 $(CXX) $(CXXFLAGS) -o demo demo.o MathLib.cpp.o MathLib.h.o

# The main.o target can be written more simply

demo.o: demo.cpp MathLib.h MathLib.cpp
 $(CXX) $(CXXFLAGS) -c demo.cpp

MathLib.cpp.o: MathLib.cpp MathLib.h
 $(CXX) $(CXXFLAGS) -c MathLib.cpp

MathLib.h.o: MathLib.h
