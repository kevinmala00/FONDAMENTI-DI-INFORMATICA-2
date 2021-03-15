#include "tree_int.h"

#include <stdio.h>
#include <stdlib.h>


bool treeismirrorrec(Node *t1, Node *t2) {

	if (IsEmptyTree(t1) && IsEmptyTree(t2)) {
		return true;
	}
	if (!IsEmptyTree(t1) && !IsEmptyTree(t2) && t1->value == t2->value) {

	
			return treeismirrorrec(LeftTree(t1), RightTree(t2)) && treeismirrorrec(RightTree(t1), LeftTree(t2));
	
	}
	return false;

}

bool TreeIsMirror(Node *t) {


	return treeismirrorrec(LeftTree(t), RightTree(t));


}