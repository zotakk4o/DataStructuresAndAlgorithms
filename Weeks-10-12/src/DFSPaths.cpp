#include "DFSPaths.h"

void DFSPaths::iterativeDFS(const UGraph& g, const int& start) {
	std::stack<int> s;
	s.push(start);
	this->visited[start] = true;

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		if (!this->visited[v]) {
			this->visited[v] = true;
		}

		std::list<int> adj = g.adjacent(v);
		for (int w : adj) {
			if (!this->visited[w]) {
				this->edgeTo[w] = v;
				s.push(w);
			}
		}
	}
}

void DFSPaths::dfs(const UGraph& g, const int& v) {
	this->visited[v] = true;
	std::list<int> adj = g.adjacent(v);

	for (int w : adj)
	{
		if (!this->visited[w]) {
			this->edgeTo[w] = v;
			this->dfs(g, w);
		}
	}
}

DFSPaths::DFSPaths(const UGraph& g, const int& start, const bool& iterative) {
	this->edgeTo = new int[g.V()];
	this->visited = new bool[g.V()];
	this->start = start;

	int vertices = g.V();
	for (int v = 0; v < vertices; v++)
	{
		this->edgeTo[v] = v;
		this->visited[v] = false;
	}

	if (iterative) {
		this->iterativeDFS(g, start);
	}
	else {
		this->dfs(g, start);
	}
}

DFSPaths::~DFSPaths() {
	delete[] this->edgeTo;
	delete[] this->visited;
}

bool DFSPaths::hasPathTo(const int& v) {
	return this->visited[v];
}

std::stack<int> DFSPaths::pathTo(const int& v) {
	std::stack<int> res;

	if (!this->hasPathTo(v)) {
		return res;
	}

	for (int curr = v; curr != this->start; curr = this->edgeTo[curr])
	{
		res.push(curr);
	}

	res.push(start);

	return res;
}