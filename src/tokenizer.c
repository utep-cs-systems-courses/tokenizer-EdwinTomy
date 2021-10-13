#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  return ((c == '\t' || c == ' ')) ? 1 : 0;
}

int non_space_char(char c)
{
  return (space_char(c) || c == '\0') ? 0 : 1;
}


char *word_start(char *str)
{
  while(space_char(*str++));

  if(*str == '\0') {
    char *pointer = NULL;
    return pointer;
  }
  
  str--;
  return str;
}

char *word_terminator(char *str)
{
  while(non_space_char(*str++));
  str--;
  return str;
}

int count_words(char *str)
{
  int cnt = 0;
  str = word_start(str);
  
  while (str) {
    cnt++;
    str = word_terminator(str);
    str = word_start(str);
  }
  
  return cnt;
}


char *copy_str(char *inStr, short len)
{
  char *copy = (char *) malloc((len + 1) * sizeof(char));
  
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  
  copy[len] = '\0';
  return copy;
}


char **tokenize(char* str)
{
  int cnt = count_words(str);
  char **tokens = (char **) malloc((cnt + 1) * sizeof(char));

  for(int i = 0; i < cnt; i++) {
    str = word_start(str);
    tokens[i] = copy_str(str, word_terminator(str) - str);
    str = word_terminator(str);
  }
  
  printf("workin\n");
  tokens[cnt] = '\0'; 
  return tokens;
}

void print_tokens(char **tokens)
{
  printf("Printing tokens:\n");
  int cnt = 0;
  while (*tokens[cnt] != '\0') {
    printf("Token[%d] is %s\n", cnt+1, tokens[cnt]);
    cnt++;
  }
}

void free_tokens(char **tokens)
{
  printf("Freeing tokens...\n");
  int i = 0;
  while (tokens[i] != NULL) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
  printf("Freed tokens!\n");
}
