#include <stdio.h>
#include <stdlib.h>
/*
   (1) 在数组中秋两个和为target的组合
       针对无序数组需要先进行排序
   (2) 求三个和为target的组合
*/


void two_sum_sorted(int array[],int len,int target){

     
     int left = 0;
     int right= len-1;
     int sum=0;
     while(left < right){
          sum=array[left] + array[right];
          if(  sum> target){

                right --;
          }else if(sum <target){

                left ++;
          }else{
                printf("The %d + %d = %d \n",array[left],array[right],target);
                left++;
                right--;
          }
     }
}



void main(void){

int array[10] = {0,1,2,3,4,7,9,10,11,12};


 
two_sum_sorted(array,10,9);


}
