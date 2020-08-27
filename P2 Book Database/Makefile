
# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: demo.o BookDB.cpp.o BookDB.h.o
 $(CXX) $(CXXFLAGS) -o main demo.o BookDB.cpp.o BookDB.h.o

# The main.o target can be written more simply

demo.o: demo.cpp BookDB.h BookDB.cpp
 $(CXX) $(CXXFLAGS) -c demo.cpp

BookDB.cpp.o: BookDB.cpp BookDB.h
 $(CXX) $(CXXFLAGS) -c BookDB.cpp

BookDB.h.o: BookDB.h