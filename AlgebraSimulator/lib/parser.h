#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/*
 * Parser: a tool to parser algebraic expressions.
 */
static const int MAX_NUMBER_LENGTH = 10;

enum Operator {
	Plus,
	Minus,
	Times,
	Divide, 
	LParen,
	RParen,
	NotAnOperator, 
	SentinelOp
};

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

extern bool isDigit(char ch);
extern bool isOperator(char ch);
extern bool isWhiteSpace(char ch);

extern Operator parseOperator(char op);
extern int countSpaces(char *str);
extern char * trim(char *str, int length);

extern Token * tokenise(char *str, int length);
extern void printToken(Token token);

extern int countChars(char *input);

extern void printTokens(char *buffer);
extern void printPromptMessage(void);
