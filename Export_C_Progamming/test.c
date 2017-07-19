
#include <stdio.h> 
int find(char * str, int length){
        char *p=str;
        char   tmp[2*length];
        int i=0,j=0,len=0;
        while(*p !='\0'){ 
            if( *p == ' '){
                 tmp[j++]='%';
                 tmp[j++]='2';
                 tmp[j++]='0';
                 j=0;
                 
            }else{
                 tmp[j++]=*p;
            }
            p++;
        }
        p=str;
        j=len;
        for(j=0;j<len;j++){
            *str++ = tmp[j];
        }       
        *p='\0';
}


void main(){
/*
 char aa[10] = "hello word\n";
 find();
 printf("7 is %d \n",find(7));
*/
 int c;
 int a,b;
c= ({a=10;b=5;});
printf("c=%d\n",c);

}
