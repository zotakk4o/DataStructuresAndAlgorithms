#include "include/DLList.cpp"
#include<iostream>
int main() {
	DLList<int> test;
	DLList<int> test2;
	test2.pushBack(1);
	test2.pushBack(2);
	test2.pushBack(3);
	test2.pushBack(4);
	test = test2;

	auto end1 = test.begin();
	auto end2 = test.end();
	std::cout << (*------------end2) << std::endl;
	std::cout << (*++++++end1) << std::endl;
	std::cout << (end1 == end2) << std::endl;
	std::cout << (test.end() == test.end()) << std::endl ;

	for (int x : test)
	{
		std::cout << x << std::endl;
	}

	for (auto it = test.end(); it != test.begin(); --it)
	{
		std::cout << (*it) << std::endl;
	}
	return 0;
}