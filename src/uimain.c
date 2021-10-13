#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char user_input[1000];
  List *list = init_history();
  int bool = 1; 
  
  puts("Welcome to Tokenizer!\n");
  
  while (bool) {
    puts("Input a string to tokenize it,  !<n> to obtain nth node, !h for history, !q to quit:\n");
    printf("->");
    fgets(user_input,1000, stdin);
    
    if (user_input[0] == '!' && user_input[1] == 'h') {
      print_history(list);
    }
    
    else if (user_input[0] == '!' && user_input[1] == 'q') {
      bool = 0;
      printf("Bye! >:(\n");
    }
    
    else if (user_input[0] == '!') {
      char *history_val = get_history(list, user_input[1] - '0');
      printf("Node[%d] is:%s\n", user_input[1] - '0', history_val);
    }
    
    else {
      char **tokens = tokenize(user_input);
      printf("%s\n", tokens[0]);
      print_tokens(tokens);
      add_history(list, user_input);
    }
  }
  
  free_history(list);
  return 0;
}
