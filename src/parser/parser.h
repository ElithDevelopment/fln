#ifndef PARSER_H
#define PARSER_H

#include "../lexer/lexer.h"

typedef struct Parser Parser;

Parser *create_parser(Token *);

void destroy_parser(Parser *);

Token get_current_token(Parser *);

void consume_token(Parser *);

void parse_if(Parser *); 

#endif // PARSER_H
