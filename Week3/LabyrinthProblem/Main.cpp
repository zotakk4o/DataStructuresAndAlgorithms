#include <iostream>
#include <utility>
#include "include/LQueue.cpp"
#include "include/String.h"
#include "include/Vector.cpp"

int findShortestPathTo(Vector<Vector<unsigned int>>& matrix, const unsigned int& startX, const unsigned int&  startY, const unsigned int&  destX, const unsigned int&  destY) {
	if (matrix[destX][destY] == 2 || matrix[startX][startY] == 2) {
		return -1;
	}

	Vector<Vector<std::pair<int, int>>> parent;
	LQueue<std::pair<unsigned int, unsigned int>> cells;

	unsigned int matrixSize = matrix.getSize();
	for (size_t i = 0; i < matrixSize; i++)
	{
		parent.pushBack(Vector<std::pair<int, int>>{});
		for (size_t j = 0; j < matrixSize; j++)
		{
			parent[i].pushBack(std::pair<int, int>{-1, -1});
		}
	}
	
	parent[startX][startY] = std::pair<int, int>{ startX, startY };
	cells.enqueue(std::pair<unsigned int, unsigned int>{startX, startY});

	while (!cells.isEmpty()) {
		std::pair<unsigned int, unsigned int> currCell = cells.dequeue();

		for (int i = -1; i <= 1; i++)
		{
			if (currCell.first + i < 0 || currCell.first + i >= matrixSize) {
				continue;
			}

			for (int j = -1; j <= 1; j++)
			{
				if (currCell.second + j < 0 || currCell.second + j >= matrixSize || i == j || i == -j) {
					continue;
				}
				int adjX = currCell.first + i;
				int adjY = currCell.second + j;

				while (adjX >= 0 && adjX < matrixSize && adjY >= 0 && adjY < matrixSize && matrix[adjX][adjY] != 2) {
					if (matrix[adjX][adjY] == 0) {
						matrix[adjX][adjY] = 1;
						parent[adjX][adjY] = currCell;
						cells.enqueue(std::pair<unsigned int, unsigned int>{adjX, adjY});
					}

					adjX += i;
					adjY += j;
				}
			}
		}

		matrix[currCell.first][currCell.second] = 2;
	}

	int lastX = destX;
	int lastY = destY;
	int tempX = destX;
	int distance = 0;
	std::pair<int, int> currCell{destX, destY};
	std::cout << "Reversed Path: " << std::endl;
	while (currCell.first != startX || currCell.second != startY) {
		tempX = lastX;
		lastX = parent[lastX][lastY].first;
		lastY = parent[tempX][lastY].second;

		if (lastX != currCell.first || lastY != currCell.second) {
			distance++;
			std::cout << "(" << currCell.first << " " << currCell.second << ")" << std::endl;
		}

		currCell.first = lastX;
		currCell.second = lastY;
	}
	
	std::cout << "(" << currCell.first << " " << currCell.second << ")" << std::endl;
	return distance;
}


int main() {
	Vector<Vector<unsigned int>> matrix;
	unsigned int matrixSize;
	String row;
	unsigned int startX, startY, destX, destY;

	std::cin >> matrixSize;
	std::cin.ignore();

	for (size_t i = 0; i < matrixSize; i++)
	{
		String::getLine(std::cin, row);
		matrix.pushBack(Vector<unsigned int>{});
		for (size_t j = 0; j < matrixSize; j++)
		{
			if (row[j] == '.') {
				matrix[i].pushBack(0);
			}
			else {
				matrix[i].pushBack(2);
			}
		}
	}

	std::cin >> startX;
	std::cin >> startY;
	std::cin >> destX;
	std::cin >> destY;

	std::cout << findShortestPathTo(matrix, startX, startY, destX, destY);

	return 0;
}