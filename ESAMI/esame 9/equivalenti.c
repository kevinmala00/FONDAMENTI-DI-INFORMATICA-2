#include "tree_int.h"
#include <stdio.h>
#include <stdlib.h>

// file funzionante provato su olj

bool Equivalenti(const Node *t1, const Node *t2) {

	if (IsEmptyTree(t1) && IsEmptyTree(t2)) {
		return true;
	}

	if (IsLeafTree(t1) && IsLeafTree(t2) && (t1->value % t2->value == 0 || t2->value % t1->value == 0)) {
		return true;
	}
	if (!IsEmptyTree(t1) && !IsEmptyTree(t2) && t1->value == t2->value) {
		if (!IsLeafTree(t1) && !IsLeafTree(t2)) {
			return Equivalenti(LeftTree(t1), LeftTree(t2)) && Equivalenti(RightTree(t1), RightTree(t2));
		}
	}
	return false;

}

