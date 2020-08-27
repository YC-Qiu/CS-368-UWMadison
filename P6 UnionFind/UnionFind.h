//Name: YC(Yucheng Qiu)
//NetID : yqiu56
#ifndef  UNION_FIND
#define UNION_FIND
#include<vector>
#include<iostream>
#include "SetUF.h"
template <typename T>
class UnionFind{
private:
	std::vector<SetUF<T>> sets;
public:
	UnionFind(const std::vector<T>& singletons) {
		for (T x : singletons) {
			sets.push_back(SetUF<T>(x));
		}
	}

	SetUF<T>& find(T node) {
		
		for (SetUF<T>& x : sets) {

			if (x.value != node) continue;
			if (x.parent != &x) {
				x.parent = &find(x.parent->value);
			}
			return *x.parent;
		}

		
	}

	void unionOp(SetUF<T>& x, SetUF<T>& y) {
		SetUF<T>& xRoot = find(x);
		SetUF<T>& yRoot = find(y);
		if (xRoot.rank < yRoot.rank) xRoot.parent = &yRoot;
		else if (xRoot.rank > yRoot.rank) yRoot.parent = &xRoot;
		else {
			yRoot.parent = &xRoot;
			xRoot.rank += 1;
		}
	}

	void unionOp(T x, SetUF<T>& y) {
		for (SetUF<T>& temp : sets) {

			if (temp.value != x) continue;
			unionOp( temp, y);
			return;
		}
	}

	void unionOp(SetUF<T>& x, T y) {
		unionOp(y, x);
	}

	void unionOp(T x, T y) {
		for (SetUF<T>& temp1 : sets) {
			if (temp1.value == x) {
				unionOp(temp1, y);
				return;
			}
		}
	}


	
};

#endif // ! UNION_FIND

