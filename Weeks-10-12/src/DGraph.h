#ifndef DIGRAPH
#define DIGRAPH
#include <vector>
#include <list>

class DGraph
{
private:
	std::vector<std::list<int>> adj; 
	std::vector<int> indegree;
	int vertices;             
	int edges;                

public:
	DGraph(const int&);

	std::list<int> adjacent(const int&) const;
	void addEdge(const int&, const int&);
	void removeEdge(const int&, const int&);
	int getIndegree(const int&) const;
	int getOutdegree(const int&) const;

	int V() const;
	int E() const;
};

#endif