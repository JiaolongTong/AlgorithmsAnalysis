#include <stdio.h>
#include <stdlib.h>


struct node {
   int value;
   struct node * next;
}
struct list{
   struct node * head;  
   struct node * tail;
}

struct list * init_list(){
    struct list * l =  (struct list *) malloc(struct list);
    l->head =NULL;
    l->tail =NULL;
}

struct list * push_back(struct list *a,int value){

      struct node *p = (struct node *) malloc(struct node);
      p->value = value;
      list->next = p;
      p->next =NULL;
}



