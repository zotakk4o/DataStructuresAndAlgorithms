#include "BFSPaths.h"
#include <queue>

void BFSPaths::bfs(const UGraph& g, const int& start) {
	std::queue<int> q;
	q.push(start);
	this->visited[start] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		std::list<int> adj = g.adjacent(v);
		for (int w : adj) {
			if (!this->visited[w]) {
				this->visited[w] = true;
				this->edgeTo[w] = v;
				q.push(w);
			}
		}
	}
}

BFSPaths::BFSPaths(const UGraph& g, const int& start) {
	this->edgeTo = new int[g.V()];
	this->visited = new bool[g.V()];
	this->start = start;

	int vertices = g.V();
	for (int v = 0; v < vertices; v++)
	{
		this->edgeTo[v] = v;
		this->visited[v] = false;
	}

	this->bfs(g, start);
}

BFSPaths::~BFSPaths() {
	delete[] this->edgeTo;
	delete[] this->visited;
}

bool BFSPaths::hasPathTo(const int& v) {
	return this->visited[v];
}

std::stack<int> BFSPaths::pathTo(const int& v) {
	std::stack<int> res;

	if (!this->hasPathTo(v)) {
		return res;
	}

	for (int curr = v; curr != this->start; curr=this->edgeTo[curr])
	{
		res.push(curr);
	}

	res.push(start);

	return res;
}