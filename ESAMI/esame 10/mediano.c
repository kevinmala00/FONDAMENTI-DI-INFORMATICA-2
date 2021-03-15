#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

int _ceil(int a, int b) {
	if ((a%b) != 0) { 
		int ris = (int)(a / b) + 1; 
	return ris;
	}
	return a/b;
}


 void contanodi(const Node *t, int *count, double k, ElemType *ris) {

	 if (IsEmptyTree(t)) {
	
		 return;
	 }



	 contanodi(LeftTree(t), count, k, ris);
	 (*count)++;
	 if ((*count) == k) {
		 *ris = *GetRootValueTree(t);
	 }
	
	 contanodi(RightTree(t), count, k, ris);

}


double Mediano(const Node *t) {

	if (IsEmptyTree(t)) {
		return DBL_MAX;
	}

	int count = 0;
	ElemType e = 0;
	contanodi(t, &count, 0, &e);

	if ((count % 2) != 0) {
		int m = 0;
		contanodi(t, &m, _ceil((count) , 2), &e);
		return e;
	}

	else {
		int i = 0;
		ElemType ris1;
		ElemType ris2;
		contanodi(t, &i, (count / 2) + 1 , &ris1);
		i = 0;
		contanodi(t, &i, (count / 2), &ris2);
		double tot = ((double)ris1 + (double)ris2) / 2;
		return tot;
	}




}