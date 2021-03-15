
#include "list_int.h"
#include <stdlib.h>
#include <stdio.h>


Item* CopyList(const Item* i) {
	Item *list_copy = CreateEmptyList();
	for (; !IsEmptyList(i); i = GetTailList(i)) {
		list_copy = InsertBackList(list_copy, GetHeadValueList(i));
	}

	return list_copy;
}

void BucketSortRec(Item *l, Item **ris) {

	

	int size;
	int min;
	int max;
	GetMinMaxSize(l, &min, &max, &size);



	if (IsEmptyList(l) || size == 1) {
		if (IsEmptyList(l)) {
			return;
		}
		*ris = InsertBackList(*ris, GetHeadValueList(l));
		DeleteList(l);
		return;
	}

	Item **v = malloc(size * sizeof(*v));
	for (int i = 0; i < size; i++) {

		v[i] = CreateEmptyList();

	}


	for (; !IsEmptyList(l); l = GetTailList(l)) {

		ElemType e = *GetHeadValueList(l);
//		int size;
//		int min;
//		int max;
//		GetMinMaxSize(l, &min, &max, &size);
//		if (max - min == 0) { 
//			v[1] = InsertBackList(v[1], &e);
//		}
//		else {
			int pos = ((size - 1)*(e - min)) / (max - min);
			v[pos] = InsertBackList(v[pos], &e);
//		}



	}
	

	for (int i = 0; i < size; i++) {

		BucketSortRec(v[i], ris);

	}



}


Item* BucketSort(Item *l) {



	int size;
	int min;
	int max;
	GetMinMaxSize(l, &min, &max, &size);

	if (IsEmptyList(l) || size == 1) {
		return l;
	}


	Item *copia = CopyList(l);
	
	DeleteList(l);
	l = CreateEmptyList();

	BucketSortRec(copia, &l);


	return l;

	


}