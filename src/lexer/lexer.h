#ifndef LEXER_H
#define LEXER_H

typedef enum TokenType TokenType;
typedef struct Token Token;

Token *lex(char *);

#endif // LEXER_H
