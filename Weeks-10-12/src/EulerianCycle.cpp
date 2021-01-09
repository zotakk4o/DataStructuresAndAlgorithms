#include "EulerianCycle.h"
#include <stdexcept>
#include <queue>
#include "GraphAPI.h"

EulerianCycle::Edge::Edge(const int& _v, const int& _w, const bool& _used) : v(_v), w(_w), used(_used) {}

int EulerianCycle::Edge::otherVertex(const int& v) {
	if (v != this->v && v != this->w) {
		throw std::invalid_argument("Vertex not found!");
	}

	return this->v == v ? this->w : this->v;
}

EulerianCycle::EulerianCycle(const UGraph& g) : cycle(nullptr) {
	int vertices = g.V();
	//Check whether all vertices have even degree
	for (int v = 0; v < vertices; v++)
	{
		if (GraphAPI::degree(g, v) % 2 != 0) {
			return;
		}
	}
	//populate edges
	std::vector<std::queue<Edge*>> edgesByVertex{(unsigned int)vertices};
	for (int v = 0; v < vertices; v++)
	{
		std::list<int> adj = g.adjacent(v);
		int selfLoops = 0; // since UGraph is undirected every selfLoop will be added twice, thus at an even selfLoop value we will add an edge
		for (int w : adj) {
			if (v == w) {
				if (selfLoops % 2 == 0) {
					Edge* newEdge = new Edge{v, w};
					edgesByVertex[v].push(newEdge);
					edgesByVertex[w].push(newEdge);
				}
				selfLoops++;
			}
			else if (v > w) {
				Edge* newEdge = new Edge{ v, w };
				edgesByVertex[v].push(newEdge);
				edgesByVertex[w].push(newEdge);
			}
		}
	}

	//fill the cycle - iterative dfs
	std::stack<int> s;
	int start = GraphAPI::nonIsolatedVertex(g);
	if (start == -1) {
		return;
	}
	this->cycle = new std::stack<int>();
	s.push(start);

	while (!s.empty()) {
		int v = s.top();
		s.pop();
		while (!edgesByVertex[v].empty()) {
			Edge* e = edgesByVertex[v].front();
			edgesByVertex[v].pop();
			if (e->used) {
				continue;
			}
			e->used = true;
			s.push(v);
			v = e->otherVertex(v);
		}

		//vertex with no unsued leaving edges
		this->cycle->push(v);
	}

	//final step -> check whether every edge was visited
	if (this->cycle->size() != g.E() + 1)
	{
		delete cycle;
		cycle = nullptr;
	}
}

EulerianCycle::~EulerianCycle() {
	delete this->cycle;
}

std::stack<int> EulerianCycle::eulerianCycle() {
	return *this->cycle;
}

bool EulerianCycle::hasEulerianCycle() {
	return this->cycle != nullptr;
}