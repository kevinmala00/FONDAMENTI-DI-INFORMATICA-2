#include "list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool scorri(const Item *l, const ElemType *e) {

	while (!IsEmptyList(l)) {


		if (ElemCompare(GetHeadValueList(l), e) >= 0) {
			return false;
		}

		l = GetTailList(l);


	}
	return true;
}

int ContaVette(const Item* i) {

	const Item *last = CreateEmptyList();
	int count = 0;
	bool ris;
	while (!IsEmptyList(i)) {

		last = i;

		ris = scorri(GetTailList(i), GetHeadValueList(i));
		if (ris) {
			count++;
		}

		i = GetTailList(last);

	}


	return count;

}
