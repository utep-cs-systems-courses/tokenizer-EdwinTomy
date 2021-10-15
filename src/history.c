#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List* newList = (List*)malloc(sizeof(List));
  newList->root = NULL;
  return newList;
}

void add_history(List* list, char*str) {
  //list is empty
  
  printf("Inside add\n");
  char *temp = str;
  while (*temp != '\0') {
    temp++;
  }
  int len = temp - str;
  char *new_str = copy_str(str, len);
  
  if(list->root == NULL) {
    list->root = (Item*)malloc(sizeof(Item));
    printf("Inside add root\n");
    list->root->id = 0;
    printf("Inside add id\n");
    printf("String:%s\n", str);
    char* start = word_start(str);
    printf("String start:%s\n", start);
    char* end = word_terminator(word_start(str));
    printf("String end:%s\n", end);
    printf("String len:%d\n", (end-start));

   
    list->root->str = new_str;
    printf("Inside add str\n");
    list->root->next = NULL;
    printf("Inside add next\n");
    return;
  }
  
  printf("After null\n");
  int cnt = 1;
  Item* temp = list->root;
    
  printf("Before while\n");
  while(temp->next != NULL) {
    temp = temp->next;
    ++cnt;
  }

  printf("After while\n");
  temp->next = (Item*)malloc(sizeof(Item));
  temp = temp->next;
  temp->id = cnt;
  temp->str = new_str;
  temp->next = NULL; 
}

char* get_history(List* list, int id) {
  if (id < 0) {
    return "";
  }
  
  Item* temp = list->root;
  
  while(temp != NULL) {
    if(temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  printf("Id not found\n");
  return "";
}

void print_history(List* list) {
  Item* temp = list->root;
  int cnt = 0;
  
  while(temp != 0) {
    printf("Id# %d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_items(Item* item) {
  if(item->next != 0) {
    free_items(item->next);
  }
  printf("Freeing item: %s on address %x\n", item->str, item);
  free(item);
  printf("\n\n");
}

void free_history(List* list) {
  if(list->root != 0) {
    free_items(list->root);
  }
  free(list);
}
