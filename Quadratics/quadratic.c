#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>

int determinant(int a, int b, int c) {
	return (b * b) - (4 * a * c);
}

double * quadroots(int a, int b, int c) {
  int delta = determinant(a, b, c);
	assert(delta >= 0);

	double root1 = (-b + sqrt((double)delta)) / (2 * a);
	double root2 = (-b - sqrt((double)delta)) / (2 * a);

	static double roots[2];
	roots[0] = root1;
	roots[1] = root2;
	return roots;
}

int main(void) {
	printf("Enter the coefficients a, b, c of the quadratic ax^2 + bx + c: ");	
	int a;
	int b;
	int c;

	scanf("%d %d %d", &a, &b, &c);

	int delta = determinant(a, b, c);
	double *roots = malloc(2 * sizeof(double));
	
	if (delta < 0) {
		printf("No real solutions");
		return 0;
	} else if (delta == 0) {
		roots = quadroots(a, b, c);
		printf("There is one real solution: %f.", roots[0]);
		return 0;
	} else {
		roots = quadroots(a, b, c);
		printf("There are two real solutions: %f and %f.", roots[0], roots[1]);
		return 0;
	} 
}
