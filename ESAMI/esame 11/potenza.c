#include <stdlib.h>
#include <stdio.h>


int Potenza(int a, int b) {



	if ((a == 0 && b == 0) || b == 0) {
		return 1;
	}
	if (a == 0) {
		return 0;
	}

	return a * Potenza(a, b - 1);
}