/**
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}
和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
#include <stdio.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
void reConstructBinaryTree(int *pre,int *vin,int index) {
        
           int Pre_Left[index],Pre_Right[index];
           int Vin_Left[index],Vin_Right[index];

           //if (pre.size() <= 0) return NULL; 
           int root,find=0;
           int i;
           root = pre[0];
           while( root != vin[find] )find++;


           printf("index=%d\n",find);
/* 
           struct TreeNode * node;
           node =(struct TreeNode *)malloc(sizeof(struct TreeNode));
           node->val =root;

           for(i=0;i<index;i++){
               Pre_Left.push_back(pre[i]);
               Vin_Left.push_back(vin[i]);
           }

           for(i=index+1;i<vin.size();i++){
               Pre_Right.push_back(pre[i]);
               Vin_Right.push_back(vin[i]);
           }

          node->left=reConstructBinaryTree(Pre_Left,Vin_Left);
           
          node->right=reConstructBinaryTree(Pre_Right,Vin_Right);
*/      
         // return node;
   }


void main(void){

	int pre[8]={1,2,4,7,3,5,6,8};
	int vin[8]={4,7,2,1,5,3,8,6};

	struct TreeNode *root;
	reConstructBinaryTree(pre,vin,8);
}

