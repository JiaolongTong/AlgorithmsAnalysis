#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000

/*
    顺序存储结构的线性表
（1）初始化:initList()
（2）插入节点:addNode()
（3）删除节点:delNode()
（4）获取节点值:getNodevalue()
（5）获取链表长度:getLength()

*/


typedef struct{

     int list[MaxSize];
     int size;
}SeqList;



 SeqList *initList(){

    SeqList *list = ( SeqList *) malloc(sizeof(SeqList));
    list->size =0; 

    return list;
} 

int  addNode(SeqList * list,int pos,int value){

     if(list->size > MaxSize){

          printf("list is full,can't insert any data!\n");
          return -1;
     }else if(pos<0 || pos >list->size){
          printf("Illige pos %d\n", pos);
          return -1;

     }else{

       int i;
       for(i=list->size ;i> pos;i--) list->list[i] =  list->list[i-1];

       list->list[pos] = value;
       list->size++;
       return 0;
    }

}
int delNode(SeqList *list,int pos){

    if(list->size ==0){
          printf("list is empty,can't delete any data\n");
          return -1;

    }else if(pos<0 || pos > list->size-1){
           printf("Illige pos %d\n", pos);
           return -1;
    }else{

          int i;
          for(i= pos+1;i<list->size;i++)
               list->list[i-1] =  list->list[i];
          list->size--;
          return 0;
    }


}

int getNodevalue(SeqList *list,int pos){

    
 if(list->size ==0){
          printf("list is empty,can't delete any data\n");
          return -1;

    }else if(pos<0 || pos > list->size-1){
           printf("Illige pos %d\n", pos);
           return -1;
    }else{

          return list->list[pos];
    }


}

int getLength(SeqList * list){
     return list->size;
}
void printList(SeqList * list){
    int i;
    for(i = 0;i<list->size;i++)
          printf("%d  ",list->list[i]);
    
     printf("\n");
}

void main(){

   SeqList * l=initList();

   addNode(l,0,0);
   addNode(l,1,2);
   addNode(l,2,4);
   addNode(l,3,6);
   addNode(l,4,8);
   addNode(l,5,10);
  
    printf("value=%d\n",getNodevalue(l,0));   
    printf("value=%d\n",getNodevalue(l,1));   
    printf("value=%d\n",getNodevalue(l,2));   
    printf("value=%d\n",getNodevalue(l,3));   
    printf("value=%d\n",getNodevalue(l,4));   
    printf("value=%d\n",getNodevalue(l,5));   


   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);
   printf("--------\n");
   delNode(l,0);
   printList(l);



   
}



