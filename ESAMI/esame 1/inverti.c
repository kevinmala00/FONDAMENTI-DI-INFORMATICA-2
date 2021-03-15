#include <stdio.h>
#include <stdlib.h>

void inverti_ric(int *v, int primo, int ultimo) {

	if (primo <= ultimo) {
		int tmp = v[primo];
		v[primo] = v[ultimo];
		v[ultimo] = tmp;
		inverti_ric(v, primo + 1, ultimo - 1);
	}
	return;

}

void Inverti(int *v, int v_size) {
	int i = 0;

	inverti_ric(v, i, v_size - 1);

	return;

}