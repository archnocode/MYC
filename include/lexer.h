#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include <stdio.h>

extern FILE* file;
extern char curr_char;
extern int pos;

enum TOKENS{
	NAME,
	TOKEN_INT,
	OP_PLUS,
	OP_MINUS,
	OP_DIVIDE,
	OP_MULTIPLY,
	OP_POWER,
	OP_EQ,
	TOKEN_EOF,
	UNKNOWN
};

typedef struct {
	enum TOKENS type;
	int value;
} TOKEN;

TOKEN next();

#endif //LEXER_H