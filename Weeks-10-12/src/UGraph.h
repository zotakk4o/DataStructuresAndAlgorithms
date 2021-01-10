#ifndef UGRAPH_H
#define UGRAPH_H

#include<vector>
#include<list>

class UGraph
{
	private:
		std::vector<std::list<int>> adj;
		int vertices;
		int edges;
	public:
		UGraph(const int&);

		void addEdge(const int&, const int&);
		void removeEdge(const int&, const int&);
		std::list<int> adjacent(const int&) const;

		int V() const;
		int E() const;
};

#endif

