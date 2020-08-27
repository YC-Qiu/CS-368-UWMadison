/*
YC (Yucheng) Qiu
yqiu56@wisc.edu
*/
#include "InfiniteInt.h"

int main() {
	InfiniteInt a;
	cout << "Please input a: " << endl;
	cin >> a;
	cout << "b = 94" << endl;
	InfiniteInt b(94);
	cout << "a + b = " << a + b << endl;
	b.getDigits();
	InfiniteInt(10000);
	vector<unsigned int> c = { 1,3,5 };
	vector<unsigned int> *d = &c;
	InfiniteInt(d);
	InfiniteInt(a);
	InfiniteInt e = b;
	a < b;
	a > b;
	a >= b;
	a <= b;
	a == b;
	a != b;
	a++;
	++b;
	a += 1;
	b -= 1;
	return 0;
}