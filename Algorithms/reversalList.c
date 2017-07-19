/*
输入一个链表，反转链表后，输出链表的所有元素。
*/
#include <stdio.h>
#include <stdlib.h> 
struct list{

      int value;
      struct list *next;
};
typedef struct list ListNode;

ListNode * add_node(ListNode * head,ListNode *p){

           if(head==NULL){
                   p->next=NULL;
           }else{
		   p->next =head;
           }
           return p;
}

ListNode * relist(ListNode *pHead){
      if(pHead==NULL)return NULL;
      ListNode * BeforeNode = pHead;
      ListNode * CurrentNode= pHead->next;
      ListNode * NextNode   ;
      if(CurrentNode == NULL) return pHead;
      else  NextNode= pHead->next->next;


      while(NextNode!=NULL){
               CurrentNode->next=pHead;
               BeforeNode->next = NextNode;


               pHead=CurrentNode;
               CurrentNode=NextNode;
               NextNode=CurrentNode->next;
      }
      BeforeNode->next = NextNode;
      CurrentNode->next=pHead;
      pHead=CurrentNode;
      return pHead;




}

void main(void){

   ListNode * node,*head=NULL;


   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =1;
   head=add_node(head,node);

   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =2;
   head=add_node(head,node);
/*
   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =3;
   head=add_node(head,node);

   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =4;
   head=add_node(head,node);

   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =5;
   head=add_node(head,node);

   node=(ListNode *)malloc(sizeof(ListNode));
   node->value =6;
   head=add_node(head,node);
*/
   ListNode *p=head;
   while(p!=NULL){
       
          printf("node value :%d\n",p->value);
          p=p->next;
   }

   head=relist(head);

   p=head;
   while(p!=NULL){
       
          printf("reversal list value :%d\n",p->value);
          p=p->next;
   }

}
