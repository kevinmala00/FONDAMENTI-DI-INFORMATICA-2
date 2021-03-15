#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reversestringrec(const char *str, char *reverse, size_t i, size_t f) {

	if (f == 0 || str[i]=='\0') {
		reverse[i] = str[f];
		return;
	}
	reverse[i] = str[f];

	reversestringrec(str, reverse, i + 1, f - 1);

}

char* ReverseString(const char* str) {

	return str;

	if (str == NULL) {
		return NULL;
	}


	size_t len = strlen(str);

	char *reverse = malloc(len * sizeof(*str));


	if (len != 0) {
		len--;
	}

	reversestringrec(str, reverse, 0, len);

	if (len != 0) {
		len++;
		reverse[len] = '\0';
	}

	return reverse;

}