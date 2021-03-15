#include "list_int.h"
#include <stdlib.h>
#include <stdio.h>


const Item* CommonTail(const Item* i1, const Item* i2) {

	if (IsEmptyList(i1) || IsEmptyList(i2)) {
		return NULL;
	}
	const Item *start = i2;
	const Item *inizio = CreateEmptyList();

	while (i1 != i2 && !IsEmptyList(i1)) {
		
		while (i1 != i2 && !IsEmptyList(i2)) {


			i2 = GetTailList(i2);

		}
		i1 = GetTailList(i1);
		i2 = start;
	}

	if (i1 == i2) {
		inizio = i2;
	}

	return inizio;


	
	
}

