#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

typedef enum TokenType {
  IDENTIFIER,
  STRING,
  DOT,
  PLUS,
  MINUS,
  DIV,
  MUL,
  LESSTHAN,
  GREATERTHAN,
  LESSEQTHAN,
  GREATEREQTHAN,
  COMMENT,
  AND,
  OR,
  LPAREN,
  RPAREN,
  LCURLY,
  RCURLY,
  LBRACE,
  RBRACE,
  BANG,
  IF,
  ELSE,
  ELIF,
  FUNC,
  VRFUNC,
  LET,
  CONV,
  RET,
  FOR,
  WHILE,
} TokenType;

typedef struct Token {
  TokenType type;
  void *value;
} Token;

Token *lex(char *text) {
  Token *tokens = malloc(strlen(text) * sizeof(Token));
  int token_count = 0;
  int in_string = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '"') {
      in_string = !in_string;

      if (in_string) {
        char str[2048];
        int j = 0;
        i++;

        while (text[i] != '"' && text[i] != '\0') {
          if (text[i] == '\\' && text[i + 1] == '"') {
            str[j++] = '"';
            i++;
          } else if (text[i] == '\\' && text[i + 1] == 'n') {
            str[j++] = '\n';
            i++;
          } else {
            str[j++] = text[i];
          }
          i++;
        }

        char *value = malloc((j + 1) * sizeof(char));
        strncpy(value, str, j);
        value[j] = '\0';

        tokens[token_count].type = STRING;
        tokens[token_count].value = value;
        token_count++;
      }
    } else if (text[i] == '.') {
      tokens[token_count].type = DOT;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '+') {
      tokens[token_count].type = PLUS;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '-') {
      tokens[token_count].type = MINUS;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '/') {
      tokens[token_count].type = DIV;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '*') {
      tokens[token_count].type = MUL;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '<') {
      tokens[token_count].type = LESSTHAN;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '>') {
      tokens[token_count].type = GREATERTHAN;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '=') {
      if (text[i+1] == '=') {
        tokens[token_count].type = GREATEREQTHAN;
        tokens[token_count].value = NULL;
        token_count++;
        i++;
      } else {
        tokens[token_count].type = LESSEQTHAN;
        tokens[token_count].value = NULL;
        token_count++;
      }
    } else if (text[i] == '&') {
      if (text[i+1] == '&') {
        tokens[token_count].type = AND;
        tokens[token_count].value = NULL;
        token_count++;
        i++;
      }
    } else if (text[i] == '|') {
      if (text[i+1] == '|') {
        tokens[token_count].type = OR;
        tokens[token_count].value = NULL;
        token_count++;
        i++;
      }
    } else if (text[i] == '(') {
      tokens[token_count].type = LPAREN;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == ')') {
      tokens[token_count].type = RPAREN;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '{') {
      tokens[token_count].type = LCURLY;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '}') {
      tokens[token_count].type = RCURLY;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '[') {
      tokens[token_count].type = LBRACE;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == ']') {
      tokens[token_count].type = RBRACE;
      tokens[token_count].value = NULL;
      token_count++;
    } else if (text[i] == '!') {
      tokens[token_count].type = BANG;
      tokens[token_count].value = NULL;
      token_count++;
    }
  }

  tokens[token_count].type = -1;
  tokens[token_count].value = NULL;

  return tokens;
}

