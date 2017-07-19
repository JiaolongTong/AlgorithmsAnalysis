#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
  基于链表实现堆栈
	(1)初始化init_stack()
	(2)栈空stack_isEmpty()
	(2)出栈stack_pop()
	(3)入栈stack_push()
	(4)输出栈顶stack_top()
*/
struct node {

     int value;
     struct node * left;
     struct node * right;
};
typedef struct node Node;


struct link{
       Node * current_node;
       struct link * next;
};
struct stack{

      struct link *head;
};
typedef struct stack Stack;


Stack * init_stack(){
        Stack * head = ( Stack *) malloc( sizeof(Stack));

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
Node * stack_top(Stack * s){
     if(s!=NULL  && (!stack_isEmpty(s))){
        // printf("%d \n",s->head->current_node->value);
         return s->head->current_node;   
     }else return NULL;
}
void stack_push(Stack **s, Node * n){
     struct link * node = (struct link *) malloc (sizeof(struct link));
     node ->current_node = n; 
     if((*s)!=NULL){
	     node->next   = (*s)->head;
	     (*s)->head      = node;
     }
}
/*
  基于数组实现队列
	(1)初始化init_queue()
	(2)队列空queue_isEmpty()
	(2)出队列queue_in()
	(3)入队列queue_out()
	(4)输出队列头queue_top()
*/
struct queue{

      int  head;
      int  tail;
      int  count;
      Node *tree_node[20];
};
typedef struct queue Queue;
Queue *init_queue(){

       Queue * q = (Queue *) malloc (sizeof(Queue));
       q->head =0;
       q->tail =0;
       q->count=0;
       return q;
}
int queue_isEmpty(Queue * q){

      if(q->head == q->tail && q->count == 0) return 1;
      else return 0;
}
int queue_isFull(Queue *q){
       
      if(q->head == q->tail && q->count == 20) return 1;
      else return 0;
}
void queue_in(Queue * q, Node *n){
       
       if(!queue_isFull(q)){  
		 q->tree_node[q->head] = n;
		 q->head = q->head % 20+1;
		 q->count++;
       }

}

void queue_out(Queue * q){
       
       if(!queue_isEmpty(q)){
		 q->tail = q->tail %20+1;
		 q->count--;
       }

}
Node*  queue_top(Queue * q){
      
       if(!queue_isEmpty(q)){

            printf("%d ",q->tree_node[q->tail]->value);
            return  q->tree_node[q->tail];
       }else return NULL;

}

/*
  二叉树(struct node)
（1）加入节点：add_node()
 (2) 求树的深度:depth()
 (3) 打印某一层节点:printLevel()
（2）基于递归的深度优先遍历:trivel_BFS_recursion()
（3）基于递归的广度优先遍历:trival_DFS_recursion()
（4）基于栈的深度优先遍历: trival_DFS_stack()
（5）基于队列的广度优先遍历:trival_DFS_queue()

*/




void add_node(Node **root,int value){

     *root = (Node *) malloc (sizeof(Node));

     (*root)->value = value;
}



void trivel_BFS_recursion(Node * root){   //中序遍历

    if(root == NULL)  return ;
    else{
            printf("%d ",root->value);
	    trivel_BFS_recursion(root->left);
	    trivel_BFS_recursion(root->right);
    }
}
int depth(Node * root){

     if(root ==NULL) return -1;
     int h_left;
     int h_right;
     int max;
     h_left = depth(root->left);
     h_right = depth(root->right);
     max = (h_left > h_right ? h_left: h_right) +1;
     return max;
}
void printLevel(Node * root,int level){

     if(root ==NULL) return;
    
     if(level == 0){
          printf("%d ",root->value);
          return;
     }else{
          
         printLevel(root->left,level-1);
         printLevel(root->right,level-1);
     }
     
}
void trival_DFS_recursion(Node * root){
    int dep = depth(root);
    int i;
    for(i=0;i<=dep;i++){
             printLevel(root,i);  
   }
}


void trival_BFS_stack(Node * root,Stack * s){  //中序遍历

     Node * current_node = root;
     
     while(current_node !=NULL){
          printf("%d ",current_node->value);
          if(current_node->right   !=NULL )stack_push(&s,current_node->right);
          if(current_node->left  !=NULL){
                 current_node = current_node ->left;
          }else{
                if(stack_isEmpty(s)){
                    current_node =NULL;
                }else{
                    current_node=stack_top(s);
                    stack_pop(s); 
                }
          }
             

     }


}

void trival_DFS_queue(Node * root,Queue *s){
     Node * current_node = root;
     queue_in(s,root);
     while(!queue_isEmpty(s)){
         current_node = queue_top(s);
         queue_out(s);

         if(current_node->left )  queue_in(s,current_node->left);
         if(current_node->right)  queue_in(s,current_node->right);
        // sleep(1);
     }

}

void main(){
     Node * tree;
     add_node(&tree,1);
     add_node(&(tree->left),2);
     add_node(&(tree->right),3);
     add_node(&(tree->left->left),4);
     add_node(&(tree->left->right),5);
          
     printf("二叉树深度优先遍历（    递归）:");
     trivel_BFS_recursion(tree);
     printf("\n");
     printf("二叉树广度优先遍历（    递归）:");
     trival_DFS_recursion(tree);
     printf("\n");
     printf("二叉树深度优先遍历（  基于栈）:");
     Stack * head=init_stack();
     
   
     trival_BFS_stack(tree,head);
     printf("\n");
     printf("二叉树深度优先遍历（基于队列）:");
     Queue *q;
     q=init_queue();
     trival_DFS_queue(tree,q);
     printf("\n");
}

