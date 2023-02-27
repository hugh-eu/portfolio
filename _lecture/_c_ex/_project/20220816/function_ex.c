#include <stdio.h>

int sum(int value1, int value2) {
	return value1 + value2;
}

void main(void) {
	int a = 100, b = 200, result = sum(a, b);
	printf("100 + 200 = %d\n", result);
}