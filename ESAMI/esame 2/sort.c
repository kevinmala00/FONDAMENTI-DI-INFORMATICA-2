#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void scambia(int *sorg, int * dest) {
	int tmp = *sorg;
	*sorg = *dest;
	*dest = tmp;
}

bool BubbleSort(int *v, int v_size){
	if ((v == NULL) || !(v_size > 0)) { return false; }

	bool ordinato = false;
	while ((v_size > 1) && (!ordinato)) {
		ordinato = true;
		for (int i = 0; i < v_size - 1; i++) {

			if (v[i] > v[i + 1]) {
				scambia(&v[i], &v[i + 1]);
				ordinato = false;
			}
			
		}
		v_size--;
	
	}
	return true;
}