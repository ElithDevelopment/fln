#ifndef PARSER_H
#define PARSER_H

#include "../lexer/lexer.h"

typedef struct Parser Parser;

Parser *create_parser(Token *);

void destroy_parser(Parser *);

Token get_current_token(Parser *);

void consume_token(Parser *);

int parse_expr(Parser *);
int parse_stmt(Parser *);
int parse_condition(Parser *);
int parse

#endif // PARSER_H
