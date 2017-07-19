#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int Fib(int n){
if(n==1)
    return 1;
else if(n==2)
    return 2;
else
    return Fib(n-1)+Fib(n-2);
}

int Parity_Check(){
    int len,i,j;
    char * s1;
    s1 = malloc(sizeof(char)*100);
    scanf("%s",s1);
    
    len=strlen(s1);
    
    for(i=0;i<len;i++){
        for(j=0;j<8;j++){
            if( (s1[i]<<(7-j) ) & 0x80 )printf("1");
            else printf("0");
        }
        printf("\n");
    }
    
    return 0;
}

     int  NumberOf1(int n) {
         int count =0;
         int tmp;
         while(n != 0){
             tmp = n & (int)0x80000000;
             if(tmp==0x80000000) count ++;            
             n=n<<1; 
         }
         
         return count;
            
         
     }




    double Power(double base, int exponent) {
/*
            if(exponent == 0) return 1.0; 
            if(exponent > 0)  return base*Power(base,exponent-1);
            if(exponent < 0)  return 1.0/(base*Power(base,exponent+1));
*/
            double value =1;
            while(exponent != 0){
               if(exponent > 0){
                  value = value* base;
                  exponent--;
               }
		if(exponent < 0){
                  value = value/base;
                  exponent++;
		}
           }
           return  value;

    }
// begin ~ end-1  
void swap(int *p, int begin, int end)  
{  
    int i,j;  
    for(i=begin,j=end-1; i<j; i++,j--)  
    {  
        int t;  
        t=p[i];  
        p[i]=p[j];  
        p[j]=t;  
    }  
}  
void swap2(int *p, int begin, int mid, int end)  
{  
    swap(p, begin, mid);  
    swap(p, mid, end);  
    swap(p, begin, end);  
} 

    void reOrderArray(int array[],int len) {
        

/*//无顺序要求  

    if(len <= 0)  return ;
        
    int beg = 0, end = len -1;
    while(beg < end)
    {
        while(beg < end &&  array[beg] %2 == 1)
            ++beg;
        while(beg < end &&  array[end] %2 == 0)
            --end;
        if(beg < end)
        {
            int tmp = array[beg];
            array[beg] = array[end];
            array[end] = tmp;
        }
    }
*/
    // 有顺序要求
    int ep; //偶数块的下标  
    int op; //奇数块的下标  
    int end; //结束  
      
    int i=0;  
      
    while(i<len)  
    {  
        for(;i<len && array[i] %2 == 1; i++);  // 找到ep  
        if(i>=len)  
            break;  
        ep=i;  
          
        for(;i<len && array[i] %2 == 0; i++);  // 找到op  
        if(i>=len)  
            break;  
        op=i;  
          
        for(;i<len && array[i] %2 == 1; i++);  // 找到end  
        end=i;  
          
        swap2(array, ep, op, end);
        i = ep+end-op;  
          
    }  
        
    }


int main(){


   printf("number of 1 is :%d\n", NumberOf1(1));
   printf("value of base^exponent is %f \n",Power(2,-3) );
  //3 4 4 6 8 2 1 1 1
  // int a[9] ={3,4,4,6,8,2,1,1,1};
   int a[7] ={1,2,3,4,5,6,7};
   reOrderArray(a,7);

   int i;
   for(i=0;i<7;i++){
       
       printf("%d  ",a[i]);
   }
}
