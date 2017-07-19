#include <stdio.h>
#include <stdlib.h>


/*

二叉查找树（Binary Search Tree）:
     它或者是一棵空树，或者是具有下列性质的二叉树
    (1) 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
    (2) 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
        它的左、右子树也分别为二叉排序树。

*/


struct tree{
     int value;
     int pos;
     struct tree * left;
     struct tree * right;
};



void  add(struct tree **root,int value,int pos){

       struct tree * node = NULL;

       if( (*root)== NULL){
	      node = (struct tree *) malloc(sizeof(struct tree));
	      node->value = value;
              node->pos = pos;
              *root = node;
           
              node->left =NULL;
              node->right=NULL;

       }else if ( (*root)->value > value ) {

              add( &(*root)->left,value,pos);
       }else if ( (*root)->value < value ) {
  
              add( &(*root)->right,value,pos);
       }

}

/*
    树的遍历: 深度优先[DFS] 前序 中序 后序)

*/
void print_tree_DFS(struct tree * root){


     if(root ==NULL)return ;
     else{
           
           print_tree_DFS(root->left  );
           printf("%d ",root->value);
           print_tree_DFS(root->right );
      }
}

/*
    求二叉树树的深度
    
*/

int depth(struct tree * root){
     if(root ==NULL)return 0;
     int h_left;
     int h_right;
     h_left =  depth(root->left );
     h_right=  depth(root->right);
     int max = h_left>h_right? h_left : h_right;
     return max + 1;
     
}


/*
    树的遍历： 广度优先遍历  逐层遍历
*/
void printLevel(struct tree * root, int level){    //  O(n^2)

     if(root ==NULL)return ;
     if(level == 0){
           printf("%d ", root -> value);
           return ;
     }else{
           printLevel(root->left,level-1);
           printLevel(root->right,level-1);
    }
}
void print_tree_BFS(struct tree * root){
  
     int dep = depth(root);
     int i;
     for(i = 0 ; i<= dep ;i++){
         //printf("\n--------------------\n");
         printLevel(root,i);
         
     }
}


/*  
    树的删除
*/
void delete_tree(struct tree * root){

    if(root == NULL) return ;
    else{
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
        root =NULL;
    }

}

int search(struct tree * root , int value){
    if(root ==NULL ) return -1;

    if(root->value == value ) return root->pos;

    else if(root->value > value){

          search(root->left,value );

    }else if(root->value < value){

          search(root->right,value ); 
    }
}


void main(void){


    int array[10] = {3,4,2,1,7,5,8,9,0,6};

    int i=0;
    struct tree *root =NULL;
    printf("原始数据:            ");
    for(i=0;i<10;i++){
         printf("%d ",array[i]);
         add( &root,array[i],i);
    }
    printf("\n");
    printf("二叉搜索树(中序遍历):");
    print_tree_DFS(root);
    printf("\n");
    printf("二叉搜索树(逐层遍历):");
    print_tree_BFS(root);
    printf("\n");
    printf("二叉搜索树高:%d\n",depth(root));
    int value =9;
    printf("搜索:%d 位置:%d\n",value,search(root,value));

    delete_tree(root);


}
