#include <stdio.h>
#include "src/lexer/lexer_.h"
#include "src/read_file.h"
#include "src/parser/parser.h"

void help() {
    fprintf(stderr,"\nTo run a Bite file, run:\n./main.o <filename>.b\n\n");
    exit(EXIT_FAILURE);
}

int main(int args, char* args_[]) {

    if(args < 2) help();

    Lexer_* lexer = init_lexer(read_file(args_[1]));
    Parser_* parser = init_parser(lexer);

    return 0;
}