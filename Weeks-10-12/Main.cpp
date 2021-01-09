#include "src/UGraph.h"
#include "src/DFSPaths.h"
#include "src/EulerianCycle.h"
#include "src/EulerianPath.h"
#include<iostream>
#include<stack>

template<typename T>
void printStack(std::stack<T> s) {
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
}


int main() {
	UGraph g{ 5 };
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 4);

	for (int i = 0; i < 5; i++)
	{
		DFSPaths iter{ g, i, true };
		DFSPaths rec{ g, i };

		for (int j = 0; j < 5; j++)
		{
			printStack<int>(iter.pathTo(j));
			printStack<int>(iter.pathTo(j));
			std::cout << "-------------" << std::endl;
		}
	}

	UGraph euPath{ 5 };
	euPath.addEdge(0, 1);
	euPath.addEdge(0, 2);
	euPath.addEdge(1, 2);
	euPath.addEdge(0, 3);
	euPath.addEdge(3, 4);

	UGraph euCycle{ 5 };
	euCycle.addEdge(0, 1);
	euCycle.addEdge(0, 2);
	euCycle.addEdge(0, 4);
	euCycle.addEdge(0, 3);
	euCycle.addEdge(1, 2);
	euCycle.addEdge(3, 4);
	
	UGraph fail{ 5 };
	fail.addEdge(0, 1);
	fail.addEdge(0, 2);
	fail.addEdge(1, 2);
	fail.addEdge(0, 3);
	fail.addEdge(3, 4);
	fail.addEdge(1, 3);

	EulerianCycle cycle{ euCycle };
	EulerianPath path{ euPath };

	std::cout << "Cycle: ";
	printStack<int>(cycle.eulerianCycle());
	std::cout << "Path: ";
	printStack<int>(path.eulerianPath());

	EulerianPath pathFail{ fail };
	EulerianCycle cycleFail{ fail };
	std::cout << "Has cycle? " << cycleFail.hasEulerianCycle() << std::endl;
	std::cout << "Has path? " << pathFail.hasEulerianPath() << std::endl;
	return 0;
}