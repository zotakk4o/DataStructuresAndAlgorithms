#ifndef CONNECTEDCOMPONENT_H
#define CONNECTEDCOMPONENT_H
#include "UGraph.h"

class ConnectedComponent
{
	private:
		bool* marked;
		int count;
		int* components;
	
		void dfs(const UGraph&, const int&);
	
	public:
		ConnectedComponent(const UGraph&);
	
		int getCount() const;
		int getComponent(const int&) const;
		bool connected(const int&, const int&) const;
	
		~ConnectedComponent();
};

#endif

