#define DEFINE_ALL
#include "../quick_use.h"
#include "keyword_lexer.h"

KeywordLex* init_keyword_lex() {
    KeywordLex* keyword_lexer = calloc(1,sizeof(*keyword_lexer));

    keyword_lexer->keyword_index = 0;
    keyword_lexer->keyword = (void*)0;

    return keyword_lexer;
}

Keyword_Token* gather_keyword(struct Lexer* lexer) {
    
    //universal_convert_to_string('a');
    printf("here");

    return init_keyword_token(K_NONE, "\0");
}