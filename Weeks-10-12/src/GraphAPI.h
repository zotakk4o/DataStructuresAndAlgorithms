#ifndef GRAPHAPI_H
#define GRAPHAPI_H

#include "UGraph.h"

class GraphAPI
{
	public:
		GraphAPI() = delete;
		static int degree(const UGraph&, const int&);
		static int maxDegree(const UGraph&);
		static double avgDegree(const UGraph&);
		static int numberOfSelfLoops(const UGraph&);
};

#endif