#include "newton.h"

double calcolo_funzione(const polinomio *pol, double xn){

	double fxn = 0;

	size_t i = 0;
	while (i <= (pol->size - 1)) {
		fxn = fxn + (pol->coeffs[i] * pow(xn, i));
		i++;
	} 


	return fxn;
}


double Newton_rec(const polinomio * p, const polinomio * d, double xn, double t, int max_iter, int iter) {


	double  fxn = calcolo_funzione(p, xn);
	double dxn = calcolo_funzione(d, xn);
	double xn_1 = xn - (fxn / dxn);

	iter++;

	if (max_iter > 0) {
		if (iter == max_iter) { return xn_1; }
		if (fabs(xn_1 - xn) <= t) { return xn_1; }
	}
	if (fabs(xn_1 - xn) <= t) { return xn_1; }

	xn = xn_1;	//xn_1 diventerà xn alla prosssima chiamata


	return Newton_rec(p, d, xn, t, max_iter, iter);
	
}


double Newton(const polinomio * p, const polinomio * d, double xn, double t, int max_iter)
{


	int iter = 0;	

	return Newton_rec(p, d, xn, t, max_iter, iter);
}

