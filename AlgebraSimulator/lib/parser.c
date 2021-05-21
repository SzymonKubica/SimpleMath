#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

static const int MAX_NUMBER_LENGTH = 10;

enum Operator {Plus, Minus, Times, Divide, NotAnOperator};

typedef enum Operator Operator;

enum TokenType {OperatorType, NumberType} ;

typedef enum TokenType TokenType;

struct Number {
	int value;
};

typedef struct Number Number;

struct Token {
	TokenType type;
	Operator operator;
	Number number;
};

typedef struct Token Token;

bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}

bool isOperator(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isWhiteSpace(char ch) {
	return ch == ' ';
}


Operator parseOperator(char op) {
	assert(isOperator(op));

	switch (op) {
		case '+':
			return Plus;
			break;
		case '-':
			return Minus;
			break;
		case '*':
			return Times;
			break;
		case '/':
			return Divide;
			break;
	}
	return NotAnOperator;
}

int countSpaces(char *str) {
	int counter = 0;
	char *ptr = str;
	for(; *ptr != '\0'; ptr++) {
		if (isWhiteSpace(*ptr)) {
			counter++;
		}
	}
	return counter;
}

char * trim(char *str, int length) {
	int spacesCount = countSpaces(str);
	char * trimmedString = (char*) malloc(length - spacesCount);
	char * trimmedPtr = trimmedString;
	for (int i = 0; i < length; i++) {
		if (!isWhiteSpace(*(str + i))) {
			*trimmedPtr = *(str + i);	
			trimmedPtr++;
		}
	}
	return trimmedString;
}

Token * tokenise(char *str, int length) {
	char *strTrimmed = trim(str, length);
	int spacesCount = countSpaces(str);
	Token *tokens = (Token*) malloc(length - spacesCount);
	while (*strTrimmed != '\0') {
		if (isDigit(*strTrimmed)) {
			char *number = strTrimmed;
			char *buffer = (char*) malloc(MAX_NUMBER_LENGTH);
			int numberLength = 1;
			while (isDigit(*number)) {
				*buffer = *number;
				buffer++;
				numberLength++;
			}
			Number num = {atoi(buffer)};
			Token token; 
			token.type = NumberType;
			token.number = num;
			*tokens = token;
			free(buffer);
			tokens++;
			strTrimmed += numberLength;
		} else if (isOperator(*strTrimmed)) {
			Operator op = parseOperator(*strTrimmed);
			Token token;
			token.type = OperatorType;
			token.operator = op;
			*tokens = token;
			tokens++;
			strTrimmed++;
		}
	}
	return tokens;

}

int main(void) {
	char input[] = "2 + 3 * 6";

	Token *tokens = tokenise(input, sizeof(input));

	return 0;
}
