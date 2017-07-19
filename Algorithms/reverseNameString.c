#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *  ReverseName(char * Name, char * newName){

      char *p;

      p= strchr(Name,' ');
      *p = '\0';

      strcpy(newName,p+1);
      strcat(newName,",");
      strcat(newName,Name);

      *p = ',';


      printf("%s\n",Name);
      return newName;
}


void  ReserseTwo(char *oldName,char * newName){

      char *p;
      char Name[30];
      strcpy(Name,oldName);

      p= strchr(newName,' ');
      *p = '\0';

      strcpy(newName,p+1);
      strcat(newName," ");
      strcat(newName,Name);
      *p = ' ';
}

void RevereStringByChar(char * newName,char ch){

   //  while


}

void main(){

    char name[] = "tong jiao long";char newName[30],Tmp[30],newName2[30];
   
     strcpy(Tmp,name);

     while(strchr(Tmp,' ') > 0) {
         ReverseName(Tmp,newName);
         strcpy(Tmp,newName);
     }
     




 //   ReserseTwo(name,newName);
   
    printf("new Name : %s \n \n \n",Tmp);
//   ReverseName(tmp,newName1);
//   printf("old Name : %s \nnew Name : %s \n \n \n",newName,newName1);
//   ReverseName(newName1,newName2);
//   printf("old Name : %s \nnew Name : %s \n",newName1,newName2);
}
