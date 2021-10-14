
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  return ((c == '\t' || c == ' ' || c == '\n')) ? 1 : 0;
}

int non_space_char(char c)
{
  return (space_char(c) || c == '\0') ? 0 : 1;
}


char *word_start(char *str)
{
  printf("---------------\n");
  printf("Start started with:%s\n", str);

  
  if(str == NULL || *str == '\0') {
    char *p = NULL;
    printf("Start ended (null) with:%s\n", str);
    printf("---------------\n");
    return p;
  }
  
  while(space_char(*str)){
    str++;
  }

  printf("Start ended with:%s\n", str);
  printf("---------------\n");
  return str;
}

char *word_terminator(char *str)
{
  printf("--------------------\n");
  printf("Terminator:%s\n", str);
  str = word_start(str);
 
  
  if(str == NULL || *str == '\0') {
    printf("is null\n");
    char *p = NULL;
    printf("Terminator ended with:%s\n", p);
    printf("--------------------\n");
    return p;
  }
  
  while(non_space_char(*str)){
    str++;
  }

  printf("Terminator ended with:%s\n", str);
  printf("--------------------\n");
  return str;
}

int count_words(char *str)
{
  printf("~~~~~~~~~~~~~~~~~~~~\n");
  printf("Count with:%s\n", str);
  int cnt = 0;
  str = word_start(str);
   
  while (str) {
    cnt++;
    str = word_terminator(str);
    str = word_start(str);
  }
   
  printf("Count with:%d\n", cnt);
  printf("~~~~~~~~~~~~~~~~~~~~\n");
  return cnt;
}


char *copy_str(char *inStr, short len)
{
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Copy with:%s;and len:%d\n", inStr, len);
  char *copy = (char *) malloc((len + 1) * sizeof(char));
   
  int i;
  for (i = 0; i < len && inStr[i] != '\0'; i++) {
    copy[i] = inStr[i];
  }
   
  copy[i] = '\0';
  printf("End Copy with:%s\n", copy);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return copy;
}

char **tokenize(char* str)
{
  printf("#########################\n");
  printf("Tokenize:%s\n", str);
  int cnt = count_words(str);
  char **tokens = (char **) malloc((cnt + 1) * sizeof(char*));
  printf("cnt is %d\n", cnt);

  for(int i = 0; i < cnt; i++) {
    str = word_start(str);
    tokens[i] = copy_str(str, word_terminator(str) - str);
    printf("Print token %s\n", tokens[i]);
    str = word_terminator(str);
  }
  
  tokens[cnt] = 0; 
  printf("End of tokenize\n");
  printf("#########################\n");
  return tokens;
}

void print_tokens(char **tokens)
{
  printf("##############################\n");
  printf("Printing tokens\n");
  int cnt = 0;
   
  while (tokens[cnt] != NULL) {
    printf("Token[%d]:%s\n", cnt+1, tokens[cnt]);
    cnt++;
    printf("Print cnt:%d\n",cnt);
  }
  
  printf("Printed tokens\n");
  printf("##############################\n");
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
  printf("Tokens freed!\n");
}
