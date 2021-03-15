#include "list_int.h"
#include <stdlib.h>
#include <stdio.h>


ElemType sommacifra(const ElemType *e1, const ElemType *e2, int *carry) {

	int ris, n1, n2;

	if (!e1) { n1 = 0; }
	else { n1 = *e1; }
	if (!e2) { n2 = 0; }
	else { n2 = *e2; }

	if (n1 + n2 + *carry >= 10) {

		ris = n1 + n2 + *carry - 10;
		*carry = 1;
		return ris;
	}
	else {
		ris = n1 + n2 + *carry;
		*carry = 0;
		return ris;

	}
}



Item* Sum(const Item *i1, const Item *i2) {
	Item *s = CreateEmptyList();

	if (IsEmptyList(i1) && IsEmptyList(i2)) {
		return s;
	}

	if (IsEmptyList(i1)) {

		while(!IsEmptyList(i2))
		{
			s = InsertBackList(s, GetHeadValueList(i2));
			i2 = GetTailList(i2);
		}

		return s;
	}

	if (IsEmptyList(i2)) {
		while (!IsEmptyList(i1))
		{
			s = InsertBackList(s, GetHeadValueList(i1));
			i1 = GetTailList(i1);
		}

		return s;
	}

	if (IsEmptyList(i2) && IsEmptyList(i1)) {
		return s;
	}
	int carry = 0;

	while (!IsEmptyList(i1) && !IsEmptyList(i2)) {
		int cifra = sommacifra(GetHeadValueList(i1), GetHeadValueList(i2), &carry);
		s = InsertBackList(s, &cifra);

		i1 = GetTailList(i1);
		i2 = GetTailList(i2);


	}

	if (IsEmptyList(i1)) {
		while (!IsEmptyList(i2)) {

			int cifra = sommacifra(NULL, GetHeadValueList(i2), &carry);
			s = InsertBackList(s, &cifra);
			i2 = GetTailList(i2);

		}
	}
	
	if (IsEmptyList(i2)) {
		while (!IsEmptyList(i1)) {

			int cifra = sommacifra(GetHeadValueList(i1), NULL, &carry);
			s = InsertBackList(s, &cifra);
			i1 = GetTailList(i1);

		}
	}

	if (carry == 1) {
		s = InsertBackList(s, &carry);
	}

	return s;


}