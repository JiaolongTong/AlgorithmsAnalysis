#include <stdio.h>
#include <stdlib.h>

/*

       字符串匹配函数， 返回匹配成功元字符串首地址
       O(m-n)

*/
const char * strStr(const char *source, const char * target){

     int i=0,j=0;
     int match =0;
     if(*target == '\0') return source;
     while(source[i] != '\0'){
            if(source[i++] == target[j++]){  
                 match=1;             
                 while(target[j] != '\0'){
                       if(source[i++] != target[j++]){
                                 j=0;
                                 match=0;
                                 break;
                       }

                 }
                 if(match == 1) return (const char *)(source+i-j);
                 
            }else{
                 j=0;
            }

     }
     return NULL;



}

void main(void){


printf("%s\n ",strStr("abcdde","cd"));


}
