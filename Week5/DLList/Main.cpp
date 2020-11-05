#include "include/DLList.cpp"
#include<iostream>
int main() {
	DLList<int> test;
	DLList<int> test2;
	test2.pushBack(1);
	test2.pushBack(2);
	test2.pushBack(2);
	test2.pushBack(2);
	test2.pushBack(3);
	test = test2;

	test.erase(0);
	test.unique();
	test.map([](const int& x) {return x * x; });
	test.removelf([](const int& x) {return x % 2 == 0; });

	for (int x : test)
	{
		std::cout << x << std::endl;
	}
	return 0;
}