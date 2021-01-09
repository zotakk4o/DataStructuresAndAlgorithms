#include "EulerianPath.h"
#include "GraphAPI.h"
#include <stdexcept>
#include <vector>
#include <queue>

EulerianPath::Edge::Edge(const int& _v, const int& _w, const bool& _used) : v(_v), w(_w), used(_used) {}

int EulerianPath::Edge::otherVertex(const int& v) {
	if (v != this->v && v != this->w) {
		throw std::invalid_argument("Vertex not found!");
	}

	return this->v == v ? this->w : this->v;
}

EulerianPath::EulerianPath(const UGraph& g) : path(nullptr) {
	int vertices = g.V();
	int odd = 0;
	int start = GraphAPI::nonIsolatedVertex(g);
	//Check whether there are exacly 2 vertices of odd degree
	for (int v = 0; v < vertices; v++)
	{
		if (GraphAPI::degree(g, v) % 2 != 0) {
			odd++;
			start = v; //We need a vertex of odd degree to start the algorithm
		}
	}

	if (odd != 2 && odd != 0) {
		return;
	}

	if (start == -1) {
		start = 0;// No edges
	}

	//populate edges
	std::vector<std::queue<Edge*>> edgesByVertex{ (unsigned int)vertices };
	for (int v = 0; v < vertices; v++)
	{
		std::list<int> adj = g.adjacent(v);
		int selfLoops = 0; // since UGraph is undirected every selfLoop will be added twice, thus at an even selfLoop value we will add an edge
		for (int w : adj) {
			if (v == w) {
				if (selfLoops % 2 == 0) {
					Edge* newEdge = new Edge{ v, w };
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

	//fill the path - iterative dfs
	std::stack<int> s;
	s.push(start);
	this->path = new std::stack<int>();

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

		this->path->push(v);//Vertex with no unused leaving edges
	}

	if (this->path->size() != g.E() + 1) {
		delete this->path;
		this->path = nullptr;
	}
}

bool EulerianPath::hasEulerianPath() {
	return this->path != nullptr;
}

std::stack<int> EulerianPath::eulerianPath() {
	return *this->path;
}

EulerianPath::~EulerianPath() {
	delete this->path;
}
