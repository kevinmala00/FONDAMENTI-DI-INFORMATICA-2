#include "minheap_int.h"

#include <stdio.h>
#include <stdlib.h>


void HeapDeleteNode(Heap* h, int k) {

	if (IsEmptyHeap(h)) { return; }

	if (k < 0 || k >= (int)h->size) {
		return;
	}


	ElemSwap(&h->data[k], &h->data[h->size - 1]);

	ElemDelete(&h->data[h->size - 1]);

	h->size--;

	MoveDownMinHeap(h, k);



}