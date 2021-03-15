#include "list_int.h"
#include <stdlib.h>
#include <stdio.h>


Item* CreaDaMinori(const Item* i, int v) {

	
	Item *ris = CreateEmptyList();

	if (IsEmptyList(i)) {
		return ris;
	}

	while (!IsEmptyList(i)) {

		if (*GetHeadValueList(i) <= v) {
			ris = InsertBackList(ris, GetHeadValueList(i));
		}
		i = GetTailList(i);
	}

	return ris;
}

