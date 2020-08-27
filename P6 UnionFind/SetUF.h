//Name: YC(Yucheng Qiu)
//NetID : yqiu56
#ifndef SETUF
#define SETUF


template <typename T>
class SetUF{
	template <typename F> friend class UnionFind;
private:
	T value;
	unsigned rank;
	SetUF* parent;
	
public:

	SetUF(T v) {
		value = v;
		rank = 0;
		parent = this;
	}


	SetUF(const SetUF& a) {
		value = a.value;
		rank = a.rank;
		if (a.parent == &a) parent = this;
		else parent = a.parent;
	}

	SetUF& operator=(const SetUF& a) {
		value = a.value;
		rank = a.rank;
		if (a.parent == &a) parent = this;
		else parent = a.parent;
		return *this;
	}

	operator T () const { return value; }



};

#endif 

