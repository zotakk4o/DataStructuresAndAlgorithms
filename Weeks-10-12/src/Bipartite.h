#ifndef BIPARTITE_H
#define BIPARTITE_H

#include "UGraph.h"

class Bipartite
{
	private:
		bool* marked;
		bool* color;
		bool bipartite;

		void dfs(const UGraph&, const int&);
	public:
		Bipartite(const UGraph&);
		~Bipartite();

		bool isBipartite();
};

#endif

