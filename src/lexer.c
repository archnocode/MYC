#include "lexer.h"

TOKEN next(){
	TOKEN token;

	while (isspace(curr_char)) curr_char = fgetc(file);

	if (curr_char == EOF){
		token.type = TOKEN_EOF;
		return token;
	}

	if (isdigit(curr_char)){
		int num = 0;
        while (isdigit(curr_char)) {
            num = num * 10 + (curr_char - '0');
            curr_char = fgetc(file);
        }
        token.type = TOKEN_INT;
        token.value = num;
        return token;
	}

	switch (curr_char){
	case '+':
		token.type = OP_PLUS;
		break;
	case '-':
		token.type = OP_MINUS;
		break;
	case '*':
		token.type = OP_MULTIPLY;
		break;
	case '/':
		token.type = OP_DIVIDE;
		break;
	case '=':
		token.type = OP_EQ;
		break;
	default:
		token.type = UNKNOWN;
		break;
	}

	return token;
}