#include "minheap_int.h"

#include <stdio.h>
#include <stdlib.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap *merge = CreateEmptyHeap();

	if (IsEmptyHeap(h2)) {
		for (size_t i = 0; i < h1->size; i++) {

			InsertNodeMinHeap(merge, &h1->data[i]);

		}
		return merge;
	}

	if (IsEmptyHeap(h1)) {
		for (size_t i = 0; i < h2->size; i++) {

			InsertNodeMinHeap(merge, &h2->data[i]);

		}
		return merge;
	}



	for (size_t i = 0; i < h1->size; i++) {

		InsertNodeMinHeap(merge, &h1->data[i]);

	}
	for (size_t i = 0; i < h2->size; i++) {

		InsertNodeMinHeap(merge, &h2->data[i]);

	}
	return merge;

}