#include<stdio.h>
#include<stdbool.h>

enum Operator {Plus, Minus, Times, Divide};

struct Number {
	int value;
}

bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}

int main(void) {
	char[] input = "2 + 3 * 6"
	char *pointer = input;
	int inputSize = sizeof(input);
	Operator operators[inputSize];
	Number numbers[inputSize];

	while(*pointer != \0) {
		char ch = *pointer;
		if (isDigit(ch) {
			
		}
	}


	
	return 0;
}
