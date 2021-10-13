#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List* newList = (List*)malloc(sizeof(List));
  newList->root = NULL;
  return newList;
}

void add_history(List* list, char*str) {
  //list is empty
  if(list->root == NULL) {
    list->root = (Item*)malloc(sizeof(Item));
    list->root->id = 0;
    list->root->str = str;
    list->root->next = NULL;
    return;
  }
  
  int count = 1;
  Item* currItem = list->root;
    
  while(currItem->next != NULL) {
    currItem = currItem->next;
    ++count;
  }

  //allocate memory for this new node
  currItem->next = (Item*)malloc(sizeof(Item));
  currItem = currItem->next;
  //initialize attributes
  currItem->id = count;
  currItem->str = str;
  currItem->next = NULL; 
}

char* get_history(List* list, int id) {
  if (id < 0) {
    return "";
  }
  
  Item* currItem = list->root;
  
  while(currItem != NULL) {
    if(currItem->id == id) {
      return currItem->str;
    }
    currItem = currItem->next;
  }
  printf("Id not found\n");
  return "";
}

void print_history(List* list) {
  Item* currItem = list->root;
  int count = 0;
  
  while(currItem != 0) {
    printf("Id# %d: %s\n", currItem->id, currItem->str);
    currItem = currItem->next;
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
