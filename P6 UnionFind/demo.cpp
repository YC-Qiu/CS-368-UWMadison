//Name: YC(Yucheng Qiu)
//NetID : yqiu56
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

class Student {
	friend ostream& operator<<(ostream &strm, const Student &stud) {
		return strm << "student(" << stud.id << ", " << stud.name << ")";
	}
	friend bool operator==(const Student &lhs, const Student &rhs) {
		return lhs.id == rhs.id;
	}
	friend bool operator!=(const Student &lhs, const Student &rhs) {
		return !(lhs == rhs);
	}

public:
	Student() = default;
	Student(int id, string name) :
			id(id), name(name) {
	}

private:
	int id;
	string name;
};

int main() {
	Student marc(0, "Marc");
	Student kyle(1, "Kyle");
	Student hemant(2, "Hemant");
	Student shanmathi(3, "Shanmathi");
	Student kate(4, "Kate");

	vector<Student> vertices { marc, kyle, hemant, shanmathi, kate };
	vector<Edge<Student>> edges { { marc, kyle }, { marc, hemant }, { kyle,
			shanmathi }, { kyle, kate } };
	Graph<Student> graph(vertices, edges);
	//No cycle
	if(graph.containsCycle())
		cout << "The graph contains a cycle" << endl;
	else
		cout << "The graph does not contain a cycle" << endl;

	cout << "Adding an edge to the current graph" << endl;
	graph.addEdge( { hemant, shanmathi });

	//cycle
	if(graph.containsCycle())
			cout << "The graph contains a cycle" << endl;
		else
			cout << "The graph does not contain a cycle" << endl;

	/*
	 * Add your graph examples below
	 */
	vector<int> intvertices { 1, 2, 3, 4, 5 };
	vector<Edge<int>> intedges{ { 1, 2 }, { 1, 3 }, { 4,
			5 }, { 2, 3 } };
	Graph<int> intgraph(intvertices, intedges);

	if (intgraph.containsCycle())
		cout << "The int graph contains a cycle" << endl;
	else
		cout << "The int graph does not contain a cycle" << endl;

	vector<int> treevertices{};
	for (int i = 0;i < 15;i++) {
		treevertices.push_back(i);
	}
	vector<Edge<int>> treeedges{
		{1, 2}, {2, 4}, {3, 11}, {4, 10},{4, 9}
	};
	Graph<int> treegraph(treevertices, treeedges);

	if (treegraph.containsCycle())
		cout << "The tree graph contains a cycle" << endl;
	else
		cout << "The tree graph does not contain a cycle" << endl;
}
