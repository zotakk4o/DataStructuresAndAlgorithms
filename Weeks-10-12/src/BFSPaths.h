#ifndef BFSPATHS_H
#define BFSPATHS_H

#include <stack>
#include "UGraph.h"


class BFSPaths
{
	private:
		bool* visited;
		int* edgeTo;
		int start;
	
		void bfs(const UGraph&, int);
	
	public:
		BFSPaths(const UGraph&, int);
		~BFSPaths();
	
		bool hasPathTo(int);
		std::stack<int> pathTo(int);
};

#endif