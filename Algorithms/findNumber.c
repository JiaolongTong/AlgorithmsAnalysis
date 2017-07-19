#include <stdio.h>
#include <stdlib.h>
/*
有10000个正整数,
每个数的取值范围均在1到1000之间,
编程找出从小到达排列在第3400(从0算起)的那个书,
将此数的值返回
要求不使用排序

*/
void generRand(int array[],int num){
	int i;
	for (i=0;i<num;i++)
	     array[i]= rand()%1000+1;

}

void output(int array[],int num){
	int i;
	for (i=0;i<num;i++)
	     printf("%d ",array[i]);
        printf("\n");
}

int Partion(int array[],int begin,int end){

  int i= begin;
  int j= end;
  int tmp,look;
  look = array[begin];
  
  while(i!=j ){
        while( array[j]>= look && i<j) j--;
        while( array[i]<= look && i<j) i++;
        if(i<j){
		tmp= array[j];
		array[j] =array[i];
		array[i] =tmp;
        }
  }
  
  array[begin]=array[i];
  array[i] = look;

  return i; 
}
int findNumber(int array[],int len,int k){

     int index=0;
     int begin = 0;
     int end = len-1;
     index=Partion(array,begin,end);
     while(index != k-1){
          index=Partion(array,begin,end);
          if(index>k-1)end   = index-1;
          if(index<k-1)begin = index+1; 
     }
     
     return index;
}

void main(){
int len =10,k=1;
	
int array[len],index;
generRand(array,len);
//output(array,len);

index=findNumber(array,len,k);

output(array,len);
printf("this is index=%d value=%d \n",index,array[index]);

}
