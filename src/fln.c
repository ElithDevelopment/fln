#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(char *program_name) {
  printf("FLN Programming Language\n");
  printf("Usage: %s [--keep-assembly] [-o <file>] <file>", program_name);
}

int main(int argc, char **argv) {
  if (argc < 2 || argc > 5) print_usage(argv[0]);
  
  int keep_assembly = 0;
  char *filename = malloc(1024);
  char *output_filename = malloc(1024);

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "--keep-assembly")) keep_assembly = 1;
    else if (strcmp(argv[i], "-o") == 0 && argv[i + 1] != NULL && strcmp(argv[i + 1], "") != 0) output_filename = argv[i + 1];
    else filename = argv[i];
  }
  
  Token *t = lex("Hello, world! 0+1 2 + 3 * 4!!! !(test) \"hello, world!\"");

  for (int i = 0; i < sizeof(t); i++) {
    printf(t[i]->type);
  }

  return 0;
}
