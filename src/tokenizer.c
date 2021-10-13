#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  printf("..........\n");
  printf("space with:%c\n",c);
  printf("..........\n");
  return (c == ' ' || c == '\t');
}

int non_space_char(char c)
{
  printf(".............\n");
  printf("nonspace with:%c\n",c);
  printf(".............\n");
  return !(space_char(c) || c == '\0');
}

char *word_start(char *str)
{
  printf("---------------\n");
  printf("start with:%s\n", str);
  while(space_char(*str)){
    printf("entering start while with:%s\n", str);
    str++;
    printf("after add:%s\n", str);
  }
  printf("exittin start while:%s\n", str);
  
  if(*str == '\0') {
    printf("is null\n");
    char *p = NULL;
    printf("---------------\n");
    return p;
  }
  
  printf("returning %s\n", str);
  printf("\n");
  printf("---------------\n");
  return str;
}

char *word_terminator(char *str)
{
  printf("--------------------\n");
  printf("term with:%s\n", str);
  
  str = word_start(str);
  printf("term after start with:%s\n", str);
 
  if(*str == '\0') {
    printf("is null\n");
    char *p = NULL;
    printf("--------------------\n");
    return p;
  }
    
  while(non_space_char(*str)){
    printf("entering end while with:%s\n", str);
    str++;
    printf("after add:%s\n", str);
  }

  printf("returning end:%s\n", str);
  printf("--------------------\n");
  return str;
}

int count_words(char *str)
{
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("count with:%s\n", str);
  int cnt = 0;
  printf("count start with:%s\n", str);
  str = word_start(str);

  while(str){
    printf("count while:%s\n", str);
    cnt++;
    str = word_terminator(str);
    if(str == NULL)
      break;
    str = word_start(str);
  }
  
  printf("returnin cnt:%d\n", cnt);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return cnt;
}

char *copy_str(char *str, short len)
{
  printf("copy\n");
  char *copy = (char *) malloc((len + 1) * sizeof(char));
  
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
  char **tokens = (char **) malloc((cnt + 1) * sizeof(char));
 
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
