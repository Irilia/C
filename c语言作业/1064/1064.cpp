#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main() {
	double balance;
	double sum = 0;
	for (int i = 0; i < 12; ++i) {
		scanf("%lf", &balance);
		sum += balance;
	}
	printf("$%.2f\n", sum / 12.0);
	return 0;
}