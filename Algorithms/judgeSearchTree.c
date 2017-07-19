#include <stdio.h>
#include <stdlib.h>



int judgeSearchTree(int BackWalk[], int begin, int end){

    if(end == begin) return 1; 
    if(end<0 ) return 0;
    int halfNode;
    int pos;
    int root = BackWalk[end];
    
    for(pos=0;pos<=end-1;pos++){

           if(BackWalk[pos] > root){
              halfNode = BackWalk[pos];
              printf("root :%d index:%d \n",halfNode,pos);
              break;
           }

    }    
    int j;
    int left_begin = begin;
    int left_end   = pos-1;
    int right_begin= pos;
    int right_end  = end-1;

    for(j=left_begin ;j<=left_end ;j++)
        if(root < BackWalk[j]){
                printf("This is not a Search Tree --->left wrong\n");
                return 0;
        }
   
    for(j=right_begin ;j<=right_end ;j++)
        if(root > BackWalk[j]){
                printf("This is not a Search Tree --->right wrong\n");
                return 0;
        }    

    judgeSearchTree(BackWalk,left_begin,left_end);
    judgeSearchTree(BackWalk,right_begin,right_end);
   // printf("This is a Search Tree\n");
    return 1;
}



void main(){

     int backWalk_A[7] = {5,7,6,9,11,10,8};
     int backWalk_B[5] = {5,4,3,2,1};
     
     printf("judge %d \n",judgeSearchTree(backWalk_B,0,4));


}
