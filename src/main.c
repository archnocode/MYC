#include <stdio.h>
#include <stdlib.h>
#include "generate.h"
#include "syntax.h"
#include "lexer.h"
#include "parser.h"

#define filename argv[2]

FILE* file;
char curr_char;

int main(int argc, char* argv[]){
	if (argc <= 1){
		printf("No input files!\n");
		return -1;
	}

	file = fopen(filename, "r");

	TOKEN token;
    do {
        token = next();
        printf("Token: %d", token.type);
        if (token.type == TOKEN_INT) printf(" (Value: %d)", token.value);
        printf("\n");
    } while (token.type != TOKEN_EOF);

	fclose(file);
	return 0;
}