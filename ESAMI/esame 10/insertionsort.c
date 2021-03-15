#include <stdio.h>
#include <stdlib.h>



void inserimento(int *v, size_t lastpos, size_t size) {

	int x = v[lastpos];
	size_t i = lastpos - 1;
	while (i >= 0 && x<v[i]) {
		v[i + 1] = v[i];
		i--;
	}

	v[i + 1] = x;



}

void InsertionSort(int *v, size_t v_size) {

	size_t i = 1;
	while (i < v_size) {

		inserimento(v, i, v_size);
		i++;
	}

}

