# Name: YC (Yucheng Qiu)
#NetID: yqiu56

CXX = g++
CXXFLAGS = -Wall

all: build

clean:
        -rm UnionFind.h.o
        -rm main

main: demo.o Graph.h.o SetUF.h.o
 $(CXX) $(CXXFLAGS) -o main demo.o Graph.h.o SetUF.h.o


demo.o: demo.cpp Graph.h UnionFind.h SetUF.h
 $(CXX) $(CXXFLAGS) -c demo.cpp

Graph.h.o: SetUF.h UnionFind.h Graph.h
 $(CXX) $(CXXFLAGS) -c Graph.h

SetUF.h.o: SetUF.h UnionFind.h