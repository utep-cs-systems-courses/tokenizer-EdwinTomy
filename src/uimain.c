#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char user_input[100];
  struct s_List *list = init_history();
  int if_continue = 1; 
  puts("Welcome! :) \n");
  
  while (if_continue) {
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Input !<num> to access string at index num,");
    puts("or input !h for full history of strings,");
    puts("or input !q to quit tokenizer,");
    puts("or input any other string to tokenize it:");
    printf("-->");
    fgets(user_input,100, stdin);
    
    if (user_input[0] == '!' && user_input[1] == 'h') {
      print_history(list);
    }
    
    else if (user_input[0] == '!' && user_input[1] == 'q') {
      if_continue = 0;
      printf("Goodbye! >:( \n");
    }
    
    else if (user_input[0] == '!') {
      char *string_at_idx = get_history(list, user_input[1] - '0');
      printf("String at #id[%d]:%s\n", user_input[1] - '0', string_at_idx);
    }
    
    else {
      char **tokens = tokenize(user_input);
      print_tokens(tokens);
      add_history(list, user_input);
    }
     puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  }
  
  free_history(list);
  return 0;
}
