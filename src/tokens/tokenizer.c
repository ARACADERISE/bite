#include "tokenizer.h"
#define DEFINE_ALL
#include "../quick_use.h"

#define AMOUNT_OF_K_W 2
const char* const keywords[AMOUNT_OF_K_W] = {
    "set", "Int"
};

#define AMOUNT_OF_PUNC 19
const char punctuation[AMOUNT_OF_PUNC] = {
    '(', ')', '{', '}', '[', ']',
    ':', ';', '\'', '"', '$', '#',
    '/', '\\', '<', '>', '.', '*', '%'
};

Tokens_* init_token(Punctuation_Token* p_t, Keyword_Token* k_t) {
    Tokens_* tokens = calloc(1,sizeof(*tokens));

    tokens->p_t = p_t;
    tokens->k_t = k_t;

    return tokens;
}
Keyword_Token* init_keyword_token(int KEYWORD_TOKEN_ID, char* keyword) {
    Keyword_Token* k_t = calloc(1,sizeof(*k_t));

    int index = 0, is_found = 1;
    do {
        if(strcmp(keywords[index],keyword)==0) is_found = 0;

        index++;
        if(index == AMOUNT_OF_K_W) {
            RaiseError("\n%s is not a keyword\n\n",keyword);
        }
    } while(index < AMOUNT_OF_K_W&&is_found == 1);

    k_t->keyword = keyword;
    k_t->KeywordTokenId = KEYWORD_TOKEN_ID;

    return k_t;
}
Punctuation_Token* init_punc_token(int PUNCTUATION_TOKEN_ID, char punc) {
    Punctuation_Token* p_t = calloc(1,sizeof(*p_t));

    int index = 0, is_punc = 1;
    do {

        if(punctuation[index] == punc) is_punc = 0;

        index++;
        if(index == AMOUNT_OF_PUNC) {
            RaiseError("\n%c is a invalid punctuation\n\n",punc);
        }
    } while(index < AMOUNT_OF_PUNC && is_punc == 1);
    
    p_t->punc = punc;
    p_t->PuncTokenId = PUNCTUATION_TOKEN_ID;

    return p_t;
}