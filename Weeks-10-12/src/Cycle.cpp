#include "Cycle.h"

void Cycle::dfs(const UGraph& g, const int& v, const int& w) {
	this->marked[v] = true;

	std::list<int> adj = g.adjacent(v);
	for (int z : adj)
	{
		if (!this->marked[z]) {
			this->dfs(g, z, v);
		}
		else if (z != w) {
			this->cycle = true;
		}
	}
}

Cycle::Cycle(const UGraph& g) : cycle(false) {
	int vertices = g.V();
	this->marked = new bool[vertices];

	for (int v = 0; v < vertices; v++)
	{
		this->marked[v] = false;
	}

	for (int v = 0; v < vertices; v++)
	{
		if (!this->marked[v])
		{
			dfs(g, v, v);
		}
	}
}

bool Cycle::hasCycle() {
	return this->cycle;
}

Cycle::~Cycle() {
	delete[] this->marked;
}
