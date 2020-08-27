//Name: YC(Yucheng Qiu)
//NetID : yqiu56

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <utility>
#include "UnionFind.h"

template<typename T> using Edge = std::pair<T, T>;

template<typename T>
class Graph {

	using Edge = std::pair<T, T>;

private:
	std::vector<T> vertices;
	std::vector<Edge> edges;

public:
	Graph(std::vector<T> v, std::vector<Edge> e) :
			vertices(v), edges(e) {
	}
	void addEdge(Edge e) {
		edges.push_back(e);
	}
	;
	bool containsCycle();
};

/*
This function finds the root of two vertice for each edge. If they have the same root, so there must
be at least one way that connects these two vertice other than that edge. And the connecting way and 
the edge will together form a cycle. 
*/
template<typename T>
bool Graph<T>::containsCycle() {
	UnionFind<T> uFind(vertices);
	for (Edge &e : edges) {
		SetUF<T> &xRoot = uFind.find(e.first);
		SetUF<T> &yRoot = uFind.find(e.second);
		if (xRoot == yRoot)
			return true;
		uFind.unionOp(xRoot, yRoot);
	}
	return false;
}

#endif
