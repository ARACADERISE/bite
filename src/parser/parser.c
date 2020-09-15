#include "parser.h"
#define DEFINE_ALL
#include "../quick_use.h"

Parser_* init_parser(Lexer_* lexer) {
    Parser_* parser = calloc(1,sizeof(*parser));

    parser->lexer = lexer;
    parser->current_token = lexer_move_to_next_token(parser->lexer);
    parser->last_token = parser->current_token;

    return parser;
}