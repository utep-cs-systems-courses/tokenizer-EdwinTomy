#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  return (c == ' ' || c == '\t');
}

int non_space_char(char c)
{
  return !(space_char(c) || c == '\0');
}

char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *str)
{
  str = word_start(str);
    
  while(space_char(*str)){
    str++;
  }

  return str;
}

int count_words(char *str)
{
  int cnt = 0;

  while(1){
    str = word_start(str);

    if(*str == '\0')
      break;
    
    cnt++;

    str = word_terminator(str);
  }
  return cnt;
}

char *copy_str(char *str, short len)
{
  char *copy = malloc(len);
  
  int i;
  for(int i = 0; i < len; i++)
    copy[i] = str[i];
  
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str)
{
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
