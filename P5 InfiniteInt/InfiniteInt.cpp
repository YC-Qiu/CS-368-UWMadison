/*
YC (Yucheng) Qiu
yqiu56@wisc.edu
*/
#include "InfiniteInt.h"


vector<unsigned int>* InfiniteInt::getDigits() {
	return digits;
}

InfiniteInt::InfiniteInt() {
	digits = new vector<unsigned int>;
	digits->push_back(0);
}

InfiniteInt::InfiniteInt(unsigned long long val) {
	digits = new vector<unsigned int>;
	if (val == 0) digits->push_back(0);
	while (val > 0) {
		digits->insert(digits->begin(),val % radix);
		val /= radix;
	}
}

InfiniteInt::InfiniteInt(std::vector<unsigned int>* new_digits) {
	digits = new_digits;
}

InfiniteInt::InfiniteInt(const InfiniteInt& obj) {
	digits = new vector<unsigned int>;
	for (auto i = obj.digits->begin(); i != obj.digits->end(); i++) {
		digits->push_back(*i);
	}
}

InfiniteInt& InfiniteInt::operator=(const InfiniteInt& obj) {
	if (this != &obj) {
		digits->clear();
		for (auto i = obj.digits->begin(); i != obj.digits->end(); i++) {
			digits->push_back(*i);
		}
	}
	return *this;
}
InfiniteInt::~InfiniteInt() {
	delete digits;
}

ostream& operator<<(ostream& os, const InfiniteInt& obj) {
	for (auto i = obj.digits->begin(); i != obj.digits->end(); i++) {
		os << *i;
	}
	return os;
}

istream& operator >>(istream& is, InfiniteInt& obj) {
	string str;
	is >> str;
	auto digits = new vector<unsigned int>();
	for (int i = 0; i < str.length();i++) {
		if (str[i] > '9' || str[i] < '0') {
			cout << "Invalid entry" << endl;
			return is;
		}
		digits->push_back((unsigned int)(str[i]-'0'));
	}
	obj.digits = digits;
	return is;
}

bool operator<(const  InfiniteInt& a, const InfiniteInt& b) {
	if (a.digits->size() > b.digits->size()) return false;
	else if (a.digits->size() < b.digits->size())return true;

	for (int i = 0;i < a.digits->size();i++) {
		if (a.digits->at(i) < b.digits->at(i)) return true;
		else if (a.digits->at(i) > b.digits->at(i)) return false;
	}
	return false;
}

bool operator>(const  InfiniteInt& a, const InfiniteInt& b) {
	return b < a;
}

bool operator==(const  InfiniteInt& a, const InfiniteInt& b) {
	return !(a > b) && !(a < b);
}

bool operator<=(const  InfiniteInt& a, const InfiniteInt& b) {
	return (a < b) || (a == b);
}

bool operator>=(const  InfiniteInt& a, const InfiniteInt& b) {
	return (a > b) || (a == b);
}

bool operator!=(const  InfiniteInt& a, const InfiniteInt& b) {
	return !(a == b);
}

InfiniteInt operator+(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	InfiniteInt sum;
	sum.digits->clear();
	const InfiniteInt& large = (lhs > rhs) ? lhs : rhs;
	const InfiniteInt& small = (lhs > rhs) ? rhs : lhs;
	int i = large.digits->size() - 1, j = small.digits->size() - 1;
	bool carryout = false;
	for (;i >= 0;i--, j--) {
		unsigned int firstop = large.digits->at(i);
		unsigned int secondop;
		if (j >= 0) secondop = small.digits->at(j);
		else secondop = 0;
		int tempsum = firstop + secondop;
		if (carryout) {
			tempsum += 1;
			carryout = false;
		}
		if (tempsum >= large.radix) {
			tempsum -= large.radix;
			carryout = true;
		}
		sum.digits->insert(sum.digits->begin(), (unsigned int)tempsum);
	}
	if(carryout) sum.digits->insert(sum.digits->begin(),1);
	return sum;
}

InfiniteInt operator-(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	InfiniteInt difference;
	difference.digits->clear();
	if (lhs <= rhs) return InfiniteInt();
	int i = lhs.digits->size() - 1, j = rhs.digits->size() - 1;
	bool carryout = false;
	for (;i >= 0;i--, j--) {
		
		unsigned int firstop = lhs.digits->at(i);
		unsigned int secondop;
		if (j >= 0) secondop = rhs.digits->at(j);
		else secondop = 0;
		int diff = firstop - secondop;
		if (carryout) diff -= 1;
		if (diff < 0) {
			carryout = true;
			diff += lhs.radix;
		}
		difference.digits->insert(difference.digits->begin(),(unsigned int)diff);
	}
	while(difference.digits->at(0) == 0){
		if (difference.digits->size() == 1) break;
		difference.digits->erase(difference.digits->begin());
	}
	return difference;
}

InfiniteInt& InfiniteInt::operator+=(const InfiniteInt& a) {
	*this = *this + a;
	return *this;
}

InfiniteInt& InfiniteInt::operator-=(const InfiniteInt& a) {
	*this = *this - a;
	return *this;
}

InfiniteInt& InfiniteInt::operator++() {
	*this += InfiniteInt(1);
	return *this;
}

InfiniteInt InfiniteInt::operator++(int) {
	InfiniteInt newnum(*this);
	*this += InfiniteInt(1);
	return newnum;
}

InfiniteInt& InfiniteInt::operator--() {
	*this -= InfiniteInt(1);
	return *this;
}

InfiniteInt InfiniteInt::operator--(int) {
	InfiniteInt newnum(*this);
	*this -= InfiniteInt(1);
	return newnum;
}
