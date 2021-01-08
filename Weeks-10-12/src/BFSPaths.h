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
	
		void bfs(const UGraph&, const int&);
	public:
		BFSPaths(const UGraph&, const int&);
		BFSPaths(const BFSPaths&) = delete;
		BFSPaths& operator=(const BFSPaths&) = delete;
		~BFSPaths();
	
		bool hasPathTo(const int&);
		std::stack<int> pathTo(const int&);
};

#endif