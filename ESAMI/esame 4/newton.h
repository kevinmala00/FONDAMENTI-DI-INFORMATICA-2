#ifndef NEWTON_H
#define NEWTON_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	int *coeffs;
	size_t size;
}polinomio;

extern double calcolo_funzione(const polinomio *pol, double xn);

extern double Newton(const polinomio *p, const polinomio *d, double xn, double t, int max_iter);

#endif // !NEWTON_H
