#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* QQ号解码(Queue)  */
void deCode_QQ(int queue[],int len){
        int tail;
        int head;
        tail =len;
        head =1;
	while(tail != head){
	      printf("%d ",queue[head]);
	      head++;
	      queue[tail]=queue[head++];
	      tail++;
	}
        printf("\n");
}
/* 队列接口 */
typedef struct Queue{
    int data[100];
    int tail;
    int head;
} Queue;
void in_queue(Queue *q,int dat){
 
     q->data[q->tail] = dat;
     q->tail++;     
}

void out_queue(Queue *q){
     q->head++;
}

void deCode_QQ_B(int queue[] ){
   int i;
   Queue *q;
   q=(Queue *)malloc(sizeof(Queue));
   q->tail=1;
   q->head=1;
    
   for(i=1;i<10;i++){
       in_queue(q,queue[i]);
       printf("%d ",q->data[q->tail-1]);
   }
 printf("\n");
   while(q->head != q->tail){
        
        printf("%d ",q->data[q->head]);
        out_queue(q);
        in_queue(q,q->data[q->head]);
        out_queue(q);        
    
   }
 printf("\n");
}
/*回文识别 (Stack)*/
int isBackText(char * text){
    int i,len,mid,top,next;
    char *stack=NULL; 
    len=strlen(text);
    mid = len/2-1;

    stack = (char *)malloc(sizeof(char)*len);
    top=0;
    for(i=0;i<=mid;i++){
    	top++;
    	*(stack+top) = *(text+i);
        printf("%c ",*(stack+top));
    }
    printf("\n");
    if(len % 2 == 0)
       next =mid +1;
    else
       next =mid +2;

    for(i=next;i<len;i++){
      
      printf("%c ",*(stack+top));
      
      if(*(stack+top) != *(text + i))break;

      top--;
    }
    if(top==0) return 1;
  
    printf("\n");
    return 1;
}



void main(void){

  int q[102]={0,6,3,1,7,5,8,9,2,4};

  // deCode_QQ(q,10);
  // deCode_QQ_B(q);
   
   if(isBackText("axbxa"))printf("Is Back Text\n");
   else printf("Not is Back Text \n");
}
