#include "list_int.h"
#include <stdio.h>
#include <stdlib.h>

Item* ElementiPari(const Item* i) {
	Item*pari = CreateEmptyList();
	if (!i) { return pari; }
	int count = 0;
	pari = InsertBackList(pari, GetHeadValueList(i));
	i = GetTailList(i);
	count++;

	while (!IsEmptyList(i)) {
		if (count % 2 == 0) {
			pari = InsertBackList(pari, GetHeadValueList(i));
		}
		i = GetTailList(i);
		count++;
	}
	return pari;

}

