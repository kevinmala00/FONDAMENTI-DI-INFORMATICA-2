#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool IsPalindromoREC(const char* str, int i, int j) {

	if (i >= j) {
		return true;
	}

	if (str[i] != str[j]) {
		return false;
	}




	return IsPalindromoREC(str, i + 1, j - 1);




}


 bool IsPalindromo(const char* str) {

	 if (!str) {
		 return false;
	 }
	 if (strlen(str) == 0) {
		 return true;
	 }

	 
	 return IsPalindromoREC(str, 0, strlen(str) - 1);

}


