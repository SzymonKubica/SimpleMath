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


