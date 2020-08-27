# Description of My Program
## Yucheng (YC) Qiu
### CS @ UW-Madison


This program is to implement the Union-Find (or Disjoint-set) data structure and use it to check whether an undirected graph contains a cycle or not.

**SetUF.h**
T value
▪ A member variable of generic type T
unsigned rank
▪ A member variable to store the rank of a set.
SetUF *parent
▪ A member variable to store the parent node of this node of the set.
SetUF(T v)
▪ A Parametrized constructor to set the value of the node.
SetUF(const SetUF &a)
SetUF& operator=(const SetUF &a)
▪ A copy constructor and assignment operator to create a new singleton.
operator T () const
▪ A conversion function to implicitly cast SetUF object to type T.

**UnionFind.h**
std::vector<SetUF<T>> sets
▪ A container to store all the set singletons.
UnionFind(const std::vector<T> &singletons)
▪ A parametrized constructor to add the singletons to the container sets
SetUF<T>& find(T node)
▪ gives the root of the set to which the node belongs to.
void unionOp(SetUF<T> &x, SetUF<T> &y)
void unionOp(T x, SetUF<T> &y)
void unionOp(SetUF<T> &x, T y)
void unionOp(T x, T y)
▪ find if argument is a node of the set and not the set itself

**Compile instruction**
g++ -o demo -c demo.cpp Graph.h SetUF.h UnionFind.h