#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
  基于链表实现堆栈
	(1)初始化init_stack()
	(2)栈空stack_isEmpty()
	(2)出栈stack_pop()
	(3)入栈stack_push()
	(4)输出栈顶stack_top()
*/

/*   表达式括号匹配
（1）从左到右循环遍历一次表达式字符串
（2）遇到左边括号入栈
（3）遇到右边括号输出栈顶元素C，并与当前括号类型E比较
     A：若C=E，则匹配成功
     C：若C!=E，则括号类型不匹配
     B：若栈空，则右边括号多于左边括号
     D：若遍历完毕，栈非空，则左边括号多于右边括号

*/

struct link{
       char value;
       struct link * next;
};
struct stack{

      struct link *head;
};
typedef struct stack Stack;


Stack * init_stack(){
        Stack * top = ( Stack *) malloc( sizeof(Stack));
      //  top->head->next=NULL;
        top->head ==NULL;
        return top;
}
int stack_isEmpty(Stack * s){

    if(s->head ==NULL)return 1;
    else return 0;
}

void stack_pop(Stack * s){
     if(s !=NULL  && (!stack_isEmpty(s))){
        struct link * node = s->head->next;
     	free(s->head);
        s->head = node;
     }
}
char  stack_top(Stack * s){
     if(s!=NULL  && (!stack_isEmpty(s))){
        // printf("%d \n",s->head->current_node->value);
         return s->head->value;   
     }else return -1;
}
void stack_push(Stack **s, char value){
     struct link * node = (struct link *) malloc (sizeof(struct link));
     node ->value = value; 
     if((*s)!=NULL){
	     node->next   = (*s)->head;
	     (*s)->head   = node;
     }
}

void ExpIsCorrect(char exp[],int n){

    Stack  *myStack;
    myStack=init_stack();
    char c;
    int i=0;
    while(exp[i] != '\0'){

           if(exp[i] == '(' ||exp[i] == '[' ||exp[i] == '{'  )
                 stack_push(&myStack,exp[i]); 


           else if(exp[i] == ')'){
               if(!stack_isEmpty(myStack)){

                       c=stack_top(myStack);
                       if(c == '('){
                           stack_pop(myStack); 
                           //printf("match '%c' = '%c' \n",c,exp[i]);
                       }else if(c >0){
                           printf("error : don't Mach  '%c' != '%c' \n",c,exp[i]);
                           return ;
                       }else{
                           printf("error : More right '%c' \n",exp[i]);
                           return;
                       }
                }
           }

           else if(exp[i] == ']'){
               if(!stack_isEmpty(myStack)){

                       c=stack_top(myStack);
                       if(c == '['){
                           stack_pop(myStack); 
                           //printf("match '%c' = '%c' \n",c,exp[i]);
                       }else if(c > 0){
                           printf("error : don't Mach  '%c' != '%c' \n",c,exp[i]);
                           return ;
                       }else {
                           printf("error : More right '%c' \n",exp[i]);
                           return;
                       }
                }
           }

           else if(exp[i] == '}'){
               if(!stack_isEmpty(myStack)){

                       c=stack_top(myStack);
                       if(c == '{'){
                           stack_pop(myStack); 
                           //printf("match '%c' = '%c' \n",c,exp[i]);
                       }else if(c >0){
                           printf("error : don't Mach  '%c' != '%c' \n",c,exp[i]);
                           return ;
                       }else {
		           printf("error : More right '%c' \n",exp[i]);
		           return;
                       }
                }
           }

           i++;

    }

        c=stack_top(myStack); 
        if(c=='(' || c=='[' || c== '{'){
            printf("error : More left '%c'\n",c);
        }else
            printf("Match OK !!\n");
 

}

void main(){

     printf("表达式括号匹配\n");
     char a[] = "([)]abc{[]()}";
     char b[] = "((())abc{[]}";
     char c[] = "(()))abc{[]}";
     char d[] = "(**)abc{{()[]}}";
     ExpIsCorrect(a,strlen(a));
     ExpIsCorrect(b,strlen(b));
     ExpIsCorrect(c,strlen(c));
     ExpIsCorrect(d,strlen(d));
   

}




