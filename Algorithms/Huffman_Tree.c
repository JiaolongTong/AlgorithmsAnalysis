#include <stdio.h>
#include <stdlib.h>


typedef struct node{
     int value;
     struct node * left;
     struct node * right;
}tree_node;

tree_node  *addHuffmanTreeNode(tree_node *left,tree_node * right){

             tree_node * root = (tree_node *)malloc(sizeof(tree_node));
             tree_node * r_left = (tree_node *)malloc(sizeof(tree_node));
             tree_node * r_right = (tree_node *)malloc(sizeof(tree_node));
             r_left->value = left->value;
             r_right->value = right->value; 
           
             root->value = r_left->value + r_right->value;
             
             root->left  = left;
             root->right = right;
               printf("root %d  %d  %d\n",root->value,root->left->value,root->right->value);
             return root;
}


void Walk(tree_node * root){

      
     if(root->left == NULL||root->right == NULL) return ;
    
     printf("%d  ",root->value);
     Walk(root->left);
     Walk(root->right);  
 

}

void main(){

     tree_node *forest[4];
     tree_node *left,*right,*root;
    
     forest[0] = (tree_node *)malloc(sizeof(tree_node));
     forest[0]->value =7;
     forest[1] = (tree_node *)malloc(sizeof(tree_node));
     forest[1]->value =5;
     forest[2] = (tree_node *)malloc(sizeof(tree_node));
     forest[2]->value =3;
     forest[3] = (tree_node *)malloc(sizeof(tree_node));
     forest[3]->value =1;


     root=addHuffmanTreeNode( forest[3], forest[2]);
     forest[3]=root;
     free(forest[2]);
     forest[2]=NULL;
     

     root=addHuffmanTreeNode( forest[3], forest[1]);
     forest[3]=root;
     free(forest[1]);
     forest[1]=NULL;


     root=addHuffmanTreeNode( forest[3], forest[0]);
     forest[3]=root;
     free(forest[0]);
     forest[0]=NULL;
    
     Walk(root);

}
