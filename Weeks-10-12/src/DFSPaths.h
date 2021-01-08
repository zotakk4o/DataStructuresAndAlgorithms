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
	
		void dfs(const UGraph&, const int&); // recurvise
		void iterativeDFS(const UGraph&, const int&); // iterative
	
	public:
		DFSPaths(const UGraph&, const int&, const bool& = false);
		DFSPaths(const DFSPaths&) = delete;
		DFSPaths& operator=(const DFSPaths&) = delete;
		~DFSPaths();
	
		bool hasPathTo(const int&);
		std::stack<int> pathTo(const int&);
};

#endif

