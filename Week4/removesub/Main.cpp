#include "node.h"
#include<iostream>
/***********************************************************************
  Задача 6. Да се дефинира шаблон на функция removesub, която приема
  два параметъра first и second — указатели към линейни едносвързани
  списъци. Функцията да изтрива от списъка с начало first
  последователно всички срещания на подсписъци, които съвпадат със
  списъка с начало second. Например, при списък first с елементи 1, 2,
  3, 3, 3, 4, 5, 3, 3, 6 и second с елементи 3, 3, first да се
  преобразува до списъка 1, 2, 3, 4, 5, 6.
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

template <typename T>
void removesub(node<T>*& first, node<T>* second){
	if (!first || !second) {
		return;
	}

	node<T>* prev = nullptr;
	node<T>* oldFirst = first;
	node<T>* oldSecond = second;
	while (first) {
		if (first->data != second->data) {
			prev = first;
			first = first->next;
			continue;
		}

		node<T>* currFirst = first;
		while (currFirst && second && currFirst->data == second->data) {
			currFirst = currFirst->next;
			second = second->next;
		}

		if (second == nullptr) {
			if (prev) {
				prev->next = currFirst;
			}
			else {
				oldFirst = currFirst;
			}
			first = currFirst;
			second = oldSecond;
		}
	}

	first = oldFirst;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob7_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
