// Name : YC (Yucheng) Qiu
// NetID: yqiu56
// Description: Implement a class InfiniteInt for lots of operations.

#ifndef INFINITE_INT
#define INFINITE_INT

#include<vector>
#include<iostream>
using namespace std;

class InfiniteInt {
	friend ostream& operator<<(ostream&, const InfiniteInt&);
	friend istream& operator>>(istream&, InfiniteInt&);
	friend bool operator<(const  InfiniteInt&, const InfiniteInt&);
	friend bool operator>(const  InfiniteInt&, const InfiniteInt&);
	friend bool operator==(const  InfiniteInt&, const InfiniteInt&);
	friend bool operator<=(const  InfiniteInt&, const InfiniteInt&);
	friend bool operator>=(const  InfiniteInt&, const InfiniteInt&);
	friend bool operator!=(const  InfiniteInt&, const InfiniteInt&);
	friend InfiniteInt operator+(const InfiniteInt&, const InfiniteInt&);
	friend InfiniteInt operator-(const InfiniteInt&, const InfiniteInt&);
private:
	vector<unsigned int>* digits;
	const unsigned int radix = 10;

public:
	InfiniteInt();
	InfiniteInt(unsigned long long val);
	explicit InfiniteInt(std::vector<unsigned int>* new_digits);
	InfiniteInt(const InfiniteInt& obj);
	InfiniteInt& operator=(const InfiniteInt&);
	InfiniteInt& operator+=(const InfiniteInt&);
	InfiniteInt& operator-=(const InfiniteInt&);
	InfiniteInt& operator++();
	InfiniteInt operator++(int);
	InfiniteInt& operator--();
	InfiniteInt operator--(int);
	vector<unsigned int>* getDigits();
	~InfiniteInt();
};



#endif