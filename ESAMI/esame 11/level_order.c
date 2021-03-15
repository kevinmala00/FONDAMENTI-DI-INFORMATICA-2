#include"tree_int.h"

#include <stdio.h>
#include <stdlib.h>

int altezza(const Node *t) {

	if (!t) {
		return 0;
	}

	int altezza_l =  1 + altezza(LeftTree(t));
	int altezza_r =  1 + altezza(RightTree(t));

	if (altezza_l > altezza_r) {
		return altezza_l;
	}
	else {
		return altezza_r;
	}

}

void printlevel(const Node *t, int level) {

	if (!t) {
		return;
	}
	if (level == 1) {
		printf("%d ", *GetRootValueTree(t));
	}
	if (level > 1) {
		printlevel(LeftTree(t), level - 1);
		printlevel(RightTree(t), level - 1);
	}
}

void LevelOrder(const Node *t) {

	int a = altezza(t);
	for (int i = 0; i < a; i++) {
		printlevel(t, i);
	}
}