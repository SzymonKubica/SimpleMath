#include<stdio.h>
#include<stdint.h>

void toBinary(uint32_t n) {
	uint32_t mask = 1 << 31;

	for (int i = 0; i < 32; i++) {
		if (((mask & n) >> (31 - i)) == 1) {
			printf("%d", 1);
		} else {
			printf("%d", 0);
		}
		mask = mask >> 1;
	}
	printf("\n");
}

int main(void) {
	printf("Enter the number you want to convert to binary: \n");
	uint32_t n;
	scanf("%d", &n);
	toBinary(n);
}
