#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

List* init_history()
{
  List* list = (List*) malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  int count = 0;
  Item* temp = list->root;
    
  while(temp->next != NULL) {
    temp = temp->next;
    ++count;
  }

  temp->next = (Item*)malloc(sizeof(Item));
  temp = temp->next;
  temp->id = count;
  temp->str = str;
  temp->next = NULL; 
}

char *get_history(List *list, int id)
{
  Item* temp = list->root;

  while (temp != NULL) {
    if(temp->id == id)
      return temp->str;
    temp = temp->next;
  }
  
  puts("No history exists with inputted id.");
  return "";
}

void print_history(List *list)
{
  puts("Printing History:\n");

  Item* temp = *list->root;
  while (temp != NULL) {
    printf("History #%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item* temp = list->root;
  
  while (temp){
    Item* next_word = temp->next;
    free(temp);
    temp = next_word;
  }
  
  free(list);
}
