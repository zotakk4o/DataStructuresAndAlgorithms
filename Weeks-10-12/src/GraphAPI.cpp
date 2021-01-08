#include "GraphAPI.h"

int GraphAPI::degree(const UGraph& g, const int& v) {
	return g.adjacent(v).size();
}

int GraphAPI::maxDegree(const UGraph& g) {
	int vertices = g.V();
	int maxDeg = 0;

	for (int v = 0; v < vertices; v++)
	{
		int currDeg = GraphAPI::degree(g, v);
		if (currDeg > maxDeg) {
			maxDeg = currDeg;
		}
	}

	return maxDeg;
}

double GraphAPI::avgDegree(const UGraph& g) {
	return g.E() * 2 / g.V();
}

int GraphAPI::numberOfSelfLoops(const UGraph& g) {
	int selfLoops = 0;
	int vertices = g.V();

	for (int v = 0; v < vertices; v++)
	{
		for (int w : g.adjacent(v))
		{
			if (v == w)
			{
				selfLoops++;
			}
		}
	}

	return selfLoops / 2; // Because of the addEdge implementation in UGraph
}