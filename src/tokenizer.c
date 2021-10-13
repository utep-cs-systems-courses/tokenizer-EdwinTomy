#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  printf("space\n");
  return (c == ' ' || c == '\t');
}

int non_space_char(char c)
{
  printf("nonspace\n");
  return !(space_char(c) || c == '\0');
}

char *word_start(char *str)
{
  printf("start\n");
  while(space_char(*str)){
    str++;
  }
  
  if(*str == '\0') {
    char *p = NULL;
    return p;
  }
  
  return str;
}

char *word_terminator(char *str)
{
  printf("term\n");
  str = word_start(str);
  
  if(*str == '\0') {
    char *p = NULL;
    return p;
  }
  
  str++;
    
  while(non_space_char(*str)){
    str++;
  }

  return str;
}

int count_words(char *str)
{
  printf("count\n");
  int cnt = 0;
  str = word_start(str);

  while(*str != '\0'){
    printf("/n");
    printf(str);
    printf("/n");
    printf("/n");
    cnt++;
    str = word_terminator(str);
    str = word_start(str);
  }
  
  return cnt;
}

char *copy_str(char *str, short len)
{
  printf("copy\n");
  char *copy = malloc(len+1);
  
  int i;
  for(int i = 0; i < len; i++)
    copy[i] = str[i];
  
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str)
{
  printf("tok\n");
  int cnt = count_words(str);
  char **tokens = malloc((cnt + 1) * sizeof(char *));
 
  for(int i = 0; i < cnt; i++){
      char* str_word = word_start(str);
      char* end_word = word_terminator(str_word);
      tokens[i] = copy_str(str, str_word - end_word);
      str = end_word;
  }
 
  tokens[cnt] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  int i=0;
  while (tokens[i]){
      printf("Token[%d] = %s\n", i, tokens[i]);
      i++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]){
      free(tokens[i]);
      i++;
  }
  free(tokens);
}
