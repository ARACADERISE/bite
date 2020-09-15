#ifndef LEXER
#define LEXER
#include "../tokens/tokenizer.h"
#include "keyword_lexer.h"

/* The lexer is split in 2 parts: 1 - keywords, second - punctuation*/
typedef struct Lexer {
    char* file_content;
    char current_char;
    int line;
    int current_char_index;
    struct KeywordLexer* K_L_;
} Lexer_;

Lexer_* init_lexer(char* file_contents);
void lexer_move(Lexer_* lexer);
Tokens_* lexer_move_to_next_token(Lexer_* lexer);

#endif