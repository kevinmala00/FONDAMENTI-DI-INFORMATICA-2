#include <stdio.h>
#include <stdlib.h>

int MCD(int m, int n) {

	if (n == 0) {
		return m;
	}

	if (n == 0) {
		return n;
	}

	if (m == n) {
		return m;
	}

	if (m > n) {
		return MCD(n, m - n);
	}


	return MCD(n - m, m);



}