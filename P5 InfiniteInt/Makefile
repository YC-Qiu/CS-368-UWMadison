
# Name: YC (Yucheng Qiu)
#NetID: yqiu56

CXX = g++
CXXFLAGS = -Wall

all: build

clean:
        -rm InfiniteInt.h.o
        -rm main

main: demo.o InfiniteInt.cpp.o InfiniteInt.h.o
 $(CXX) $(CXXFLAGS) -o main demo.o InfiniteInt.cpp.o InfiniteInt.h.o


demo.o: demo.cpp InfiniteInt.h InfiniteInt.cpp
 $(CXX) $(CXXFLAGS) -c demo.cpp

InfiniteInt.cpp.o: InfiniteInt.cpp InfiniteInt.h
 $(CXX) $(CXXFLAGS) -c InfiniteInt.cpp

InfiniteInt.h.o: InfiniteInt.h