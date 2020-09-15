#include "lexer_.h"
#include "keyword_lexer.h"
#define DEFINE_ALL
#include "../quick_use.h"

Lexer_* init_lexer(char* file_contents) {
    Lexer_* lexer = calloc(1,sizeof(*lexer));

    lexer->current_char_index = 0;
    lexer->file_content = file_contents;
    lexer->current_char = lexer->file_content[lexer->current_char_index];
    lexer->K_L_ = init_keyword_lex();
    lexer->line = 1;

    return lexer;
}

void lexer_move(Lexer_* lexer) {
    if(!(lexer->current_char_index > strlen(lexer->file_content) && lexer->current_char != '\0')) {
        lexer->current_char_index++;
        lexer->current_char = lexer->file_content[lexer->current_char_index];

        if(lexer->current_char == '\n') lexer->line++;
    }
}

static inline void lexer_skip_whitespace(Lexer_* lexer) {
    if(lexer->current_char == ' ' || lexer->current_char == 0xC) {
        do {
            printf("HERE");
            lexer_move(lexer);
        } while(lexer->current_char == ' ' || lexer->current_char == 0xC);
    }
}

Tokens_* lexer_move_to_next_token(Lexer_* lexer) {
    struct Lexer* lexer_ = lexer;
    do {

        if(lexer->current_char == ' ' || lexer->current_char == 0xC)
            lexer_skip_whitespace(lexer);
        
        if(isalnum(lexer->current_char))
            gather_keyword(lexer_);
        
    } while(lexer->current_char != '\0' && lexer->current_char_index < strlen(lexer->file_content));
}