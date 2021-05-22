#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdint.h>

static const int MAX_NUMBER_LENGTH = 10;

enum Operator {Plus, Minus, Times, Divide, NotAnOperator, SentinelOp};

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
	*trimmedPtr = '\0';
	return trimmedString;
}

Token * tokenise(char *str, int length) {
	char *strTrimmed = trim(str, length);
	int spacesCount = countSpaces(str);
	Token *tokens = (Token*) malloc(length - spacesCount);
	Token *tokensPtr = tokens;
	while (*strTrimmed != '\0') {
		if (isDigit(*strTrimmed)) {
			char *number = strTrimmed;
			char *buffer = (char*) malloc(MAX_NUMBER_LENGTH);
			char *ptr = buffer;
			int numberLength = 0;
			while (isDigit(*number)) {
				*ptr = *number;
				ptr++;
				number++;
				numberLength++;
			}
			Number num = {atoi(buffer)};
			Token token; 
			token.type = NumberType;
			token.number = num;
			*tokensPtr = token;
			tokensPtr++;
			strTrimmed += numberLength;
		} else if (isOperator(*strTrimmed)) {
			Operator op = parseOperator(*strTrimmed);
			Token token;
			token.type = OperatorType;
			token.operator = op;
			*tokensPtr = token;
			tokensPtr++;
			strTrimmed++;
		}
	}
	Token terminalToken;
	terminalToken.type = OperatorType;
	terminalToken.operator = SentinelOp;
	*tokensPtr = terminalToken; 
	return tokens;
}

void printOperator(Operator operator) {
	switch (operator) {
		case Plus:
			printf(" (+) ");
			break;
		case Minus:
			printf(" (-) ");
			break;
		case Times:
			printf(" (*) ");
			break;
		case Divide:
			printf(" (/) ");
			break;
		case NotAnOperator:
			printf("NOT AN OPERATOR!");
			break;
		case SentinelOp:
			printf("\n");
			break;
	}
}

void printToken(Token token) {
	if (token.type == NumberType) {
		printf("(Number: %d)", token.number.value);
	} else {
		printOperator(token.operator);
	}
}

int countChars(char *input) {
	int counter = 0;
	for (; *input != '\n'; input++) {
		counter++;
	}
	return counter;
}


int main(void) {
	printf("Enter the expression you want to parse: \n");

	char *buffer = NULL;
	int read;
	size_t len;

	read = getline(&buffer, &len, stdin);

	if (-1 != read) {
		Token *tokens = tokenise(buffer, countChars(buffer));
		int i = 0;
		while ((*(tokens + i)).operator != SentinelOp) {
			printToken(*(tokens + i));
			i++;
		}
		printf("\n");
	} else {
		printf("No line entered.");
	}

	return 0;
}
