#ifndef PARSER
#define PARSER
#include "../lexer/lexer_.h"
#include "../tokens/tokenizer.h"

typedef struct Parser {
    Lexer_* lexer;
    Tokens_* current_token;
    Tokens_* last_token;
} Parser_;

Parser_* init_parser(Lexer_* lexer);

#endif