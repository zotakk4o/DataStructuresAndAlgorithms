#ifndef DFSPATHS_H
#define DFSPATHS_H

#include <stack>
#include "UGraph.h"

class DFSPaths
{
	private:
		bool* visited;
		int* edgeTo;
		int start;
	
		void dfs(const UGraph&, int); // recurvise
		void iterativeDFS(const UGraph&, int); // iterative
	
	public:
		DFSPaths(const UGraph&, int);
		~DFSPaths();
	
		bool hasPathTo(int);
		std::stack<int> pathTo(int);
};

#endif

