#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SubsetEqualRec(int *vcurr, int i, int n, int s, int scurr, int**elenco) {

	if (scurr == s) {
		//hp non è mai stata stampata
		int check = 0;

		//se gli elementi della soluzione sono tutti presenti in uno dei vettori già stampati allora non lo stampo
		//se non è presente lo inserisco 
		for (int m = 0; m < n&&*elenco == NULL; m++) {
			int countelemuguali = 1;
			for (int n = 0; n < i; n++) {
				// counto gli elementi uguali se count == i non stampo
				for (int h = 0; h < i; h++) {
					if (vcurr[n] == *elenco[h]) {
						countelemuguali++;
					}
				}
				if (countelemuguali == i) { check = 1; break; }
			}
			if (check == 1) {
				break;
			}

		}

		if (!check) {
			printf("{ ");

			for (int j = 0; j < i; j++) {
				printf("%d ", vcurr[j]);
			}


			printf("}, ");
			int z = 0;
			for (; !(elenco[z]); z++);

			for (int y = 0; y < i; y++) {
			elenco[z][y] = vcurr[y];
			}
		


		}
		return;
	}
	if (i == n) { return; }

	for (int j = 1; j <= n; j++) {


		int presente = 0;
		for (int x = 0; x < i; x++) {
			if (vcurr[x] == j) {
				presente = 1;
			}
		}

		// prendo elemento se scurr < s && scurr + elem <= s && !presente
		if (scurr < s && scurr + j <= s && !presente) {

			vcurr[i] = j;
			SubsetEqualRec(vcurr, i + 1, n, s, scurr + vcurr[i], elenco);
		}
		

	}
}




void SubsetEqual(int n, int s) {

	if (n <= 0 || s <= 0) {
		return;
	}
	int **elenco = calloc(n, sizeof(*elenco));
	for (int z = 0; z < n; z++) {
		elenco[z] = calloc(n, sizeof(*elenco));
	}
	int *vcurr = (int*)calloc(n, sizeof(*vcurr));
	SubsetEqualRec(vcurr, 0, n, s, 0, elenco);
	for (int z = 0; z < n; z++) {
		free(elenco[z]);
	}
	free(elenco);
	free(vcurr);

}