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
		Bipartite(const Bipartite&) = delete;
		Bipartite& operator=(const Bipartite&) = delete;
		~Bipartite();

		bool isBipartite();
};

#endif

