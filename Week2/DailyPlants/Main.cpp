#include "include/Stack.cpp"
#include "include/String.h"
#include<iostream>

int main() {
	int plants;
	String plantsStr;
	Stack<int> plantsStack;
	String currPlant;
	int daysToImmortality = 0;

	std::cin >> plants;
	std::cin.ignore();
	String::getLine(std::cin, plantsStr);

	unsigned int plantsStrLength = plantsStr.getLength();
	for (size_t i = 0; i < plantsStrLength; i++)
	{
		if (plantsStr[i] == ' ') {
			plantsStack.push(String::toInt(currPlant));
			currPlant = "";
			continue;
		}

		currPlant += plantsStr[i];
	}

	plantsStack.push(String::toInt(currPlant));

	int currentDeaths = 0;
	Stack<int> helperStack;
	while (true) {
		while (!plantsStack.isEmpty()) {

			int firstPlant = plantsStack.pop();

			if (plantsStack.isEmpty()) {
				break;
			}

			if (plantsStack.peek() < firstPlant) {
				currentDeaths++;
			}
			else {
				helperStack.push(firstPlant);
			}

		}

		if (currentDeaths == 0) {
			break;
		}

		daysToImmortality++;
		currentDeaths = 0;

		while (!helperStack.isEmpty()) {
			plantsStack.push(helperStack.pop());
		}
	}

	std::cout << daysToImmortality;

	return 0;
}