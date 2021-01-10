#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "DGraph.h"
#include<stack>

class TopologicalSort
{
	private:
		bool* visited;
		bool* marked;
		std::stack<int> sorted;
		void dfs(const DGraph& , const int&);
	
	public:
		TopologicalSort(const DGraph&);
		~TopologicalSort();

		std::stack<int> reversePost();	
};

#endif

