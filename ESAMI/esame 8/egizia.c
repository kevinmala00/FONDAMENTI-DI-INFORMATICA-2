#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int _ceil(int a, int b) {
	if (a%b != 0) {
		return (int)(a / b) + 1;
	}
	else return (int)(a / b);
}


void nuovafrazione(int n, int d, int *newn, int *newd) {

	*newd = d * _ceil(d , n);
	*newn = ((*newd)/d)*n - (*newd)/ _ceil(d, n);;;
}

void FrazioneEgiziaRec(int n, int d) {

	//caso base d multiplo di n => d%n ==0
	if ((d % n) == 0) {
		int a = _ceil(d, n);
		printf(" + 1/%d", a);
		return;
	}
	int a = _ceil(d , n);
	printf(" + 1/%d", a);
	nuovafrazione(n, d, &n, &d);
	FrazioneEgiziaRec(n, d);


}

void FrazioneEgizia(int n, int d) {

	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}


	int a = _ceil(d , n);
	printf("1/%d", a);
	nuovafrazione(n, d, &n, &d);
	FrazioneEgiziaRec(n, d);

}