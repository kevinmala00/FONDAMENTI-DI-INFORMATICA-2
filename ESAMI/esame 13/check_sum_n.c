
#define _CRT_SECURE_NO_WARNINGS
#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




bool backtrack(int *v, int somma, int size ) {
	bool ris = false;
	for (int i = 0; i <= size; i++) {

		for (int j = 0; j <= size; j++) {

			if (v[i] == v[j]) {

				ris = true;
			}
		}


	}
	return ris;


}


bool CheckSumN(const Node *t, int n) {

	if (IsEmptyTree(t) || IsLeafTree(t)) { return false; }
	
	FILE *f = fopen("treeelem.txt", "w");
	WriteInOrderTree(t, f);


	int *v = calloc(1, sizeof(int));
	int i = 0;

	while (fscanf(f, "%d", &v[i]) > 0) {

		i++;
		v = realloc(v, (i + 1) * sizeof(int));

	}

	
	bool ris = backtrack(v, n, i);
	fclose(f);
	free(v);
	return ris;

}