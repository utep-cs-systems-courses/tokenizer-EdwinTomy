#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

List* init_history()
{
  List* list = (List*) malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str)
{
  Item* new_word = (Item*) malloc(sizeof(Item));
  (*new_word).str = str;

  Item* temp = (*list).root;
  int id = 0;
  
  if(!temp){
    (*new_word).id = id;
    (*list).root = new_word;
  }
  
  while ((*temp).next){
    temp = (*temp).next;
    id = (*temp).id + 1;
  }
  
  (*new_word).id = id;
  (*temp).next = new_word;
  (*new_word).next = NULL;
  return;
}

char *get_history(List *list, int id)
{
  Item* temp = (*list).root;

  while (temp) {
    if((*temp).id == id)
      return (*temp).str;
    temp = (*temp).next;
  }
  
  puts("No history exists with inputted id.");
  return "";
}

void print_history(List *list)
{
  puts("Printing History:\n");

  Item* temp = (*list).root;
  while (temp) {
    printf("History #%d: %s\n", (*temp).id, (*temp).str);
    temp = (*temp).next;
  }
}

void free_history(List *list)
{
  Item* temp = (*list).root;
  
  while (temp){
    Item* next_word = (*temp).next;
    free(temp);
    temp = next_word;
  }
  
  free(list);
}
