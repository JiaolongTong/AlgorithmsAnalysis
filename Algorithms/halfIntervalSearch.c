#include <stdio.h>
#include <stdlib.h>

int half_search_A(int array[],int begin,int end,int find){ //递归方法

    if(begin > end ) return -1;
    
    int middle = (begin+end)/2;
    //printf(" begin %d end %d middle %d\n" ,begin,end,middle); 
    if(array[middle] > find) return half_search_A(array,begin,middle-1,find); 
    if(array[middle] < find) return half_search_A(array,middle+1,end,find); 
    if(array[middle] == find ) return middle;
  
}
int half_search_B(int array[],int len,int find){          //非递归方法
  int begin  =0;
  int end    =len-1;
  int middle=0;
  while ( begin <= end ){
       middle = (begin+end) / 2;
       //printf(" begin %d end %d middle %d\n" ,begin,end,middle); 
       if(array[middle] > find)  end = middle -1;
       if(array[middle] < find)  begin = middle +1;
       if( array[middle] == find )  return middle;
  }
   
  return -1;

}
void main(){


    int array[10] ={1,3,5,7,9};

    int find =9;
    int index=-1 ;
    for (find =0 ;find <=10 ;find ++){
	    index = half_search_B(array,5,find);
	 
	    if(index >=0)
	    	printf("the find index is %d value is %d \n", index, array[index]);
	    else
	    	printf("don't find any value\n");
   }
}
