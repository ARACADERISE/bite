#ifndef TOKENIZER
#define TOKENIZER

typedef struct KeywordToken {
    char* keyword;

    enum {
        DEFAULT_ID,
        PKG,
        SET,
        INT,
        K_NONE // no keyword was picked up, or '\0' was incountered
    } KeywordTokenId;
} Keyword_Token;

typedef struct PunctuationToken {
    char punc;

    enum {
        COLON,
        SEMI,
        EOF_
    } PuncTokenId;
} Punctuation_Token;

typedef struct Tokens {
    Keyword_Token* k_t;
    Punctuation_Token* p_t;
} Tokens_;

Tokens_* init_token();
Keyword_Token* init_keyword_token(int KEYWORD_TOKEN_ID, char* keyword);
Punctuation_Token* init_punc_token(int PUNCTUATION_TOKEN_ID, char punc);

#endif