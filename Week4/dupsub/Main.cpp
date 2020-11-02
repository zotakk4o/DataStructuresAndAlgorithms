#include "node.h"

/***********************************************************************
  Задача 3. Да се дефинира шаблон на булева функция dupsub, която
  приема два параметъра: указател към линеен едносвързан списък и
  неотрицателно число k. Функцията да връща истина, ако в списъка има
  поне два различни подсписъка с дължина k, които са с еднакви
  елементи. Примери за такива списъци са 1, 2, 3, 4, 1, 2, 5 и 1, 2,
  3, 3, 3, 4 за k = 2.
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

template <typename T>
bool dupsub(node<T>* l, unsigned k) {
	if (!l || k <= 0) {
		return false;
	}

	node<T>* first = l;
	node<T>* currFirst = l;
	node<T>* currSubFirst;
	node<T>* lReset;
	unsigned currK = 1;
	while (currFirst) {
		currSubFirst = currFirst;
		int occurrencesFound = 0;
		while (l) {
			int numsMatched = 0;
			lReset = l;
			while (currK <= k) {
				if (l && currSubFirst && currSubFirst->data == l->data) {
					currSubFirst = currSubFirst->next;
					numsMatched++;
				}

				if (!l) {
					break;
				}

				l = l->next;
				currK++;
			}
			l = lReset->next;

			if (numsMatched == k) {
				occurrencesFound++;
				if (occurrencesFound == 2) {
					return true;
				}
			}
			else {
				currSubFirst = currFirst;
			}

			currK = 1;
		}

		l = first;
		currFirst = currFirst->next;
	}

	return false;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob5_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
