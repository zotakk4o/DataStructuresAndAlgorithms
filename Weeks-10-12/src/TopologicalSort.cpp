#include "TopologicalSort.h"
#include <stdexcept>

void TopologicalSort::dfs(const DGraph& g, const int& v) {
	this->visited[v] = true;
	std::list<int> adj = g.adjacent(v);
	
	for (int w : adj)
	{
		if (!this->visited[w]) {
			this->dfs(g, w);
		}
		else if (!this->marked[w]){
			throw std::invalid_argument("Graph is not DAG!");
		}
	}

	this->marked[v] = true;
	this->sorted.push(v);
}

TopologicalSort::TopologicalSort(const DGraph& g) {
	int vertices = g.V();
	this->visited = new bool[vertices];
	this->marked = new bool[vertices];
	for (int v = 0; v < vertices; v++)
	{
		this->visited[v] = false;
		this->marked[v] = false;
	}

	for (int v = 0; v < vertices; v++)
	{
		if (!this->marked[v]) {
			this->dfs(g, v);
		}
	}
}

TopologicalSort::~TopologicalSort() {
	delete[] this->visited;
	delete[] this->marked;
}

std::stack<int> TopologicalSort::reversePost() {
	return this->sorted;
}
