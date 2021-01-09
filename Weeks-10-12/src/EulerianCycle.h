#ifndef EULERIANCYCLE_H
#define EULERIANCYCLE_H

#include "UGraph.h"
#include <stack>

class EulerianCycle
{
	private:
		std::stack<int>* cycle;
		struct Edge {
			int v;
			int w;
			bool used;

			Edge(const int&, const int&, const bool& = false);
			int otherVertex(const int&);
		};
	
	public:
		EulerianCycle(const UGraph&);
		EulerianCycle(const EulerianCycle&) = delete;
		EulerianCycle& operator=(const EulerianCycle&) = delete;
		~EulerianCycle();

		std::stack<int> eulerianCycle();
		bool hasEulerianCycle();
};

#endif

