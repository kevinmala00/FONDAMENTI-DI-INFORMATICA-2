

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int AToIRec(const char* str, int dim, int p) {

	if (dim < 0) {
		return 0;
	}


	return ((str[dim] - '0')*p) + AToIRec(str, dim - 1, p * 10);

}

int AToI(const char *str) {
	if (str == NULL) {
		return 0;
	}
	return AToIRec(str, strlen(str) - 1, 1);
}