
# Name: YC (Yucheng Qiu)
#NetID: yqiu56

CXX = g++
CXXFLAGS = -Wall

all: build

clean:
        -rm SummarizeGrades.h.o
        -rm main

main: demo.o SummarizeGrades.cpp.o SummarizeGrades.h.o
 $(CXX) $(CXXFLAGS) -o main demo.o SummarizeGrades.cpp.o SummarizeGrades.h.o


demo.o: demo.cpp SummarizeGrades.h SummarizeGrades.cpp
 $(CXX) $(CXXFLAGS) -c demo.cpp

SummarizeGrades.cpp.o: SummarizeGrades.cpp SummarizeGrades.h
 $(CXX) $(CXXFLAGS) -c SummarizeGrades.cpp

SummarizeGrades.h.o: SummarizeGrades.h