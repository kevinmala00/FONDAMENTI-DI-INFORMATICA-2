#include <stdio.h>
#include <stdlib.h>

int Quoziente(size_t x, size_t y) {
	if (y == 0) { return -1; }
	if (x == y) { return 1; }
	if (x < y) { return 0; }
	return 1 + Quoziente(x - y, y);
}