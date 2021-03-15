#include "minheap_int.h"
#include <stdlib.h>
#include <stdio.h>

int posmax(int *v, size_t dim) {
	int pos;
	int max = v[0];
	for (size_t i = 0; i < dim; i++) {

		if (v[i] > max) {
			pos = i;
		}
	}
	return pos;
}


void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void naivesort(int *v, size_t dim) {
	size_t p;

	while (dim > 1) {
		p = posmax(v, dim);
		if (p < dim) {
			swap(&v[p], &v[dim - 1]);
		}
		dim--;
	}

}


ElemType KthLeast(const Heap* h, int k) {

	
	int *vett = malloc(sizeof((h->size) * sizeof(int)));

	for (size_t i = 0; i < h->size; i++) {

		vett[i] = h->data[i];


	}

	naivesort(vett, (h->size));

	
	int ris = vett[k - 1];
	vett = realloc(vett, sizeof(int));

	free(vett);

	return ris;



}