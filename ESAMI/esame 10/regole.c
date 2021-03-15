#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void appoggio(const char *r, int n, int i, int *nsol, int *vcurr) {

	if (i == n) {
		(*nsol)++;
		printf("%d)\t", *nsol);
		for (int i = 0; i <= n; i++) {

			printf("%d ", vcurr[i]);

		}
		printf("\n\n");
		return;
	}

	for (int j = 0; j <= n; j++) {

		vcurr[i] = j + 1;

		if (r[i] == 'i' || r[i] == 'I') {
			//metti in vcurr[i+1] un valore  maggiore di vcurr[i] appartenente a [1,n+1]
			int x = 1;
			while (x <= n + 1) {

				if (x > vcurr[i]) {
					//devo controllare che non sia presente in vcurr
					for (int h = 0; h <= n; h++) {
						if (x == vcurr[h]) {
							goto qui;
						}
					}
					//non è presente
					//lo metto in vcurr[i+1] ed esco dal ciclo
					vcurr[i + 1] = x;
					appoggio(r, n, i + 1, nsol, vcurr);
					break;
				}
				//incremento fino a che non è maggiore
				qui:
				x++;
			}		
			
		}

		if (r[i] == 'd' || r[i] == 'D') {
			//metti in vcurr[i+1] un valore  minore di vcurr[i] appartenente a [1,n+1]
			int x = 1;
			while (x <= n + 1) {

				if (x < vcurr[i]) {
					//devo controllare che non sia presente in vcurr
					for (int h = 0; h <= n; h++) {
						if (x == vcurr[h]) {
							break;
						}
					}
					//non è presente
					//lo metto in vcurr[i+1] ed esco dal ciclo
					vcurr[i + 1] = x;
					appoggio(r, n, i + 1, nsol, vcurr);
					break;
				}
				//incremento fino a che non è minore
				x++;
			}
		
		}
		
		

	}

}

void Regole(const char *r) {
	if (r == NULL) {
		printf("1");
		return;
	}

	int n = strlen(r);
	

	int *v = (int *)calloc(n+1, sizeof(*v));

	if (n == 0) {
		printf("1");
		return;
	}
	int nsol = 0;
	

	appoggio(r, n, 0, &nsol, v);
	
	v = realloc(v, 1);
	free(v);
	


}
