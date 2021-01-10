#include "UGraph.h"

UGraph::UGraph(const int& _vertices) : vertices(_vertices), edges(0), adj(_vertices) {}

void UGraph::addEdge(const int& v, const int& w) {
	this->adj[v].push_back(w);
	this->adj[w].push_back(v);
	this->edges++;
}

void UGraph::removeEdge(const int& v, const int& w) {
	this->adj[v].remove(w);
	this->adj[w].remove(v);
	this->edges--;
}

std::list<int> UGraph::adjacent(const int& v) const {
	return this->adj[v];
}

int UGraph::V() const {
	return this->vertices;
}

int UGraph::E() const {
	return this->edges;
}
