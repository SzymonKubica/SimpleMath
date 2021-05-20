#include<stdio.h>

int helperfib(int a, int b, int n) {
	if (n < 1) 
		return b;
	return helperfib(b, a + b, n - 1);
}

int goodfib(int n) {
	return helperfib(0, 1, n);
}

int main(void) {
	printf("Enter the number n to compute the n-th Fibonacci number.\n");
	int n;
	scanf("%d", &n);
	printf("%d\n", goodfib(n));
	return 0;
}
