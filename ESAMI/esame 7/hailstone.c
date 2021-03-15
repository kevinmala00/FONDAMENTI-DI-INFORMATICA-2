#include <stdio.h>
#include <stdlib.h>


size_t Hailstone(int n) {

	if (n <= 0) { return 0; }
	if (n == 1) {
		printf("%d ", n);
		return 1; 
	}

	printf("%d, ", n);

	if (n % 2 == 0) {
		return 1 + Hailstone(n / 2); 
	}
	return 1 + Hailstone(3 * n + 1);



}