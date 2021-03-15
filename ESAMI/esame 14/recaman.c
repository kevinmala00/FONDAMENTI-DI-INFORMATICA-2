#include <stdio.h>
#include <stdlib.h>



int Recaman(int n) {

	if (n < 1) { return -1; }
	if (n == 1 || n == 2) {
		return 1;
	}
	if ((Recaman(n - 1) % (n - 1)) == 0) {
		
		return Recaman(n - 1) / (n - 1);
	}
	return Recaman(n - 1) * (n - 1);
	
}
