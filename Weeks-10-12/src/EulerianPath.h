#ifndef EULERIANPATH_H
#define EULERIANPATH_H

#include "UGraph.h"
#include <stack>

class EulerianPath
{
	private:
		struct Edge {
			int v;
			int w;
			bool used;

			Edge(const int&, const int&, const bool& = false);
			int otherVertex(const int&);
		};
		std::stack<int>* path;

	public:
		EulerianPath(const UGraph&);
		bool hasEulerianPath();
		std::stack<int> eulerianPath();
		~EulerianPath();
};

#endif

