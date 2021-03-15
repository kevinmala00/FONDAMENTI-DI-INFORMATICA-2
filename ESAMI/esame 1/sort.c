#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void scambia(int *sorg, int *dest) {

	int tmp = *sorg;
	*sorg = *dest;
	*dest = tmp;
}

bool QuickSort(int *v,int v_size, int first, int last) {

	if ((first < 0) || (last >= v_size) || (last < first) || (v == NULL)) {
		return false;
	}

	int pivot = (v[first] + v[last]) / 2;
	int i = first;
	int j = last;
	if (first < last) {
		do {

			while (v[i] < pivot) { i++; }
			while (v[j] > pivot) { j--; }

			if (i <= j) {
				scambia(&v[i], &v[j]);
				i++;
				j--;
			}


		} while (i <= j);

		QuickSort(v, v_size, first, j);

		QuickSort(v, v_size, i, last);
	}
	return true;
}

/*

bool QuickSort(int *v, int v_size, int first, int last) {

	if ((first < 0) || (last >= v_size) || (last < first) || (v == NULL)) {
		return false;
	}

	QuickSort_rec(v, first,last);

	return true;


	
}*/