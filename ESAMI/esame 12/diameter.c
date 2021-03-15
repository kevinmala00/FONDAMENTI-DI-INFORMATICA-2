#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>

int max_(int a, int b) {

	if (a > b) { return a; }
	return b;

}

int altezza(Node *t) {

	if (!t) {
		return 0;
	}

	return 1 + max_(altezza(LeftTree(t)), altezza(RightTree(t)));

}

int Diameter(const Node *t) {

	if (!t) {
		return 0;
	}

	int altezzar = altezza(RightTree(t));
	int altezzal = altezza(LeftTree(t));

	return max_(altezzar + altezzal + 1, max_(Diameter(LeftTree(t)), Diameter(RightTree(t))));


}