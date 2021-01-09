#ifndef CYCLE_H
#define CYCLE_H

#include "UGraph.h"

class Cycle
{
	private:
		bool cycle;
		bool* marked;
		void dfs(const UGraph&, const int&, const int&); // can be done with BFS as well
	
	public:
		Cycle(const UGraph&);
		bool hasCycle();
		~Cycle();
};

#endif

