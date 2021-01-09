#include "Bipartite.h"

void Bipartite::dfs(const UGraph& g, const int& v) {
	this->marked[v] = true;

	std::list<int> adj = g.adjacent(v);
	for (int w : adj)
	{
		if (!this->marked[w]) {
			this->color[w] = !this->color[v];
			this->dfs(g, w);
		}
		else if (this->color[v] == this->color[w]) {
			this->bipartite = false;
		}
	}
}

Bipartite::Bipartite(const UGraph& g) : bipartite(true) {
	int vertices = g.V();
	this->color = new bool[vertices];
	this->marked = new bool[vertices];

	for (int v = 0; v < vertices; v++)
	{
		this->marked = false;
		this->color = false;
	}

	for (int v = 0;  v < vertices;  v++)
	{
		if (!this->marked[v]) {
			this->dfs(g, v);
		}
	}
}

Bipartite::~Bipartite() {
	delete[] this->marked;
	delete[] this->color;
}

bool Bipartite::isBipartite() {
	return this->bipartite;
}