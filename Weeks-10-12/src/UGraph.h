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
		UGraph(const UGraph&);
		UGraph& operator=(const UGraph&);

		void addEdge(int, int);
		void removeEdge(int, int);
		std::list<int> adjacent(int) const;

		int V() const;
		int E() const;
};

#endif

