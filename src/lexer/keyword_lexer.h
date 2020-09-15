#ifndef KEYWORD_LEXER
#define KEYWORD_LEXER
#include "lexer_.h"
#include "../tokens/tokenizer.h"

typedef struct KeywordLexer {
    char* keyword;
    int keyword_index;
} KeywordLex;

KeywordLex* init_keyword_lex();
Keyword_Token* gather_keyword(struct Lexer* lexer);

#endif