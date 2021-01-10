#include "ConnectedComponent.h"

void ConnectedComponent::dfs(const UGraph& g, const int& v) {
	this->marked[v] = true;
	this->components[v] = this->count;
	std::list<int> adj = g.adjacent(v);
	for (int w : adj)
	{
		if (!this->marked[w]) {
			this->dfs(g, w);
		}
	}
}

ConnectedComponent::ConnectedComponent(const UGraph& g) : count(0) {
	int vertices = g.V();
	this->marked = new bool[vertices];
	this->components = new int[vertices];

	for (int v = 0; v < vertices; v++)
	{
		this->marked[v] = false;
		this->components[v] = v;
	}

	for (int v = 0; v < vertices; v++)
	{
		if (!this->marked[v]) {
			this->dfs(g, v);
			this->count++;
		}
	}
}

int ConnectedComponent::getCount() const {
	return this->count;
}

int ConnectedComponent::getComponent(const int& v) const {
	return this->components[v];
}

bool ConnectedComponent::connected(const int& v, const int& w) const {
	return this->components[v] == this->components[w];
}

ConnectedComponent::~ConnectedComponent() {
	delete[] this->marked;
	delete[] this->components;
}