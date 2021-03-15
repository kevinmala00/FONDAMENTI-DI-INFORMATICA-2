#include "list_int.h"
#include <stdio.h>
#include <stdlib.h>

Item * listcopy(const Item *l) {
	
	Item *list = CreateEmptyList();

	while (!IsEmptyList(l)) {

		list = InsertBackList(list, GetHeadValueList(l));

		l = GetTailList(l);
	}

	return list;

}



Item* CopiaDaN(const Item* i, int n) {

	if (IsEmptyList(i)) {
		return NULL;
	}

	int j = 1;
	while (!IsEmptyList(i) && j < n) {
		i = GetTailList(i);
		j++;
	}

	return listcopy(i);
}