#include "minheap_int.h"
#include <stdio.h>
#include <stdlib.h>

void fromvector(Heap *h, int *v, int size) {

	for (int i = 0; i < size; i++) {

		InsertNodeMinHeap(h, &v[i]);
	}

}


Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap *m = CreateEmptyHeap();

	if (IsEmptyHeap(h1) && IsEmptyHeap(h2)) {
		return m;
	}

	if (IsEmptyHeap(h1)) {
		fromvector(m, h2->data, h2->size);
		return m;
	}
	if (IsEmptyHeap(h2)) {
		fromvector(m, h1->data, h1->size);
		return m;
	}



	fromvector(m, h1->data, h1->size);
	fromvector(m, h2->data, h2->size);


	return m;



}