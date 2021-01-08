#include "src/UGraph.h"
#include "src/DFSPaths.h"
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
	return 0;
}