#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  
  printf(count_words("fcfc vchjgt tvjh tjhkv "));
  printf("Welcome!:\n)");
  List* list = init_history();
  while(1){
    printf("Select one of the following inputs, please:\n");
    printf("1. Print full history (type <h>)\n");
    printf("2. Get specific node i from history (type <!i>, where i is a n)\n");
    printf("3. Quit program (type <q>)\n");
    printf("4. Tokenize! (type anything else)\n");
          
    char *input = malloc(sizeof(char*));
    fgets(input, 100, stdin);

    if(input[0] == 'h'){
      print_history(list);

    } else if(input[0] == '!'){
      int x = input[1] - '0';
      printf("Node at id[%d]:  %s\n", x, get_history(list, x));

    } else if(input[0] == 'q'){
      puts("Goobdbye! :(");
      break;
      
    } else{
      puts("Tokenized String:");
      char** tokens = tokenize(input);
      add_history(list, input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }
  return 0;
}
