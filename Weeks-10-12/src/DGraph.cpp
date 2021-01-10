#include "DGraph.h"

DGraph::DGraph(const int& _vertices) : vertices(_vertices), edges(0), adj(_vertices), indegree(_vertices) {}

std::list<int> DGraph::adjacent(const int& v) const {
	return this->adj[v];
}

void DGraph::addEdge(const int& v, const int& w) {
	this->adj[v].push_back(w);
	this->indegree[w]++;
	this->edges++;
}

void DGraph::removeEdge(const int& v, const int& w) {
	this->adj[v].remove(w);
	this->indegree[w]--;
	this->edges--;
}

int DGraph::getIndegree(const int& v) const {
	return this->indegree[v];
}

int DGraph::getOutdegree(const int& v) const {
	return this->adj[v].size();
}

int DGraph::V() const {
	return this->vertices;
}

int DGraph::E() const {
	return this->edges;
}