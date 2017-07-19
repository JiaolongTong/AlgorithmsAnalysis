#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_LEN    2807303

typedef struct node{

      char *key;
      int   count;

      struct node * next;
}HashNode_t;

HashNode_t  *hash_head[HASH_LEN]; 

int hash_code(char const * key){

     int value =0;
     while(*key!='\0'){
         value = value *31 +*key++;
         if(value > HASH_LEN)
            value = value % HASH_LEN;
      }
}


void hashInsert(char const *str){
      int hash_index = hash_code(str);

      HashNode_t *p = hash_head[hash_index];
      while(p!=NULL){
           if(strcmp(str,p->key) == 0 ){
               p-> count++;
               return ;
           }
           p=p->next;
      }

      HashNode_t *node = (HashNode_t *)malloc(sizeof(HashNode_t));
      node->key =  (char*)malloc(strlen(str)+1);  
      strcpy(node->key,str);
      node->count = 1;
      node->next = hash_head[hash_index];
      hash_head[hash_index] = node;
}

int hashDelete(char const * str){

     int hash_index = hash_code(str);

     HashNode_t *p = hash_head[hash_index];
     HashNode_t *per;
     while(p!=NULL){

         if(strcmp(str,p->key) == 0 ){
            printf("delete key : %s \n", p->key);
            if(p->count ==1){
               if(p->next != NULL)
                   per->next = p->next;
               free(p->key);
               p->key=NULL;
               free(p);
               p=NULL;
               return 1;
            }else{
               p->count--;
               return 1;
            }
         }
         per = p;
         p=p->next;


     }
     return 0;

}

int hash_search(char * str){

      int hash_index = hash_code(str);
      HashNode_t *p =  hash_head[hash_index];
      while(p!=NULL){
        
            if(strcmp(p->key,str) == 0){

                       printf("find key : %s \n", p->key);
                       return 1;
            }
            p= p->next;
      }
      return 0;
}



void print_hash(){
      

     int i;
      HashNode_t *p;
     for(i=0;i<HASH_LEN;i++){
           p = hash_head[i];
           while( p!=NULL ){
                 printf("key :%s , count :%d\n",p->key, p->count );
                 p= p->next;
           }
     }
}

/*
     利用滚动hash实现字符串匹配(O(n) ~O(m*n))
     m= len_t
     
     hash_value = a0*PRIME_BASE^(m-2) +  a1*PRIME_BASE^(m-3) + a2*PRIME_BASE^(m-4) ....
*/
#define PRIME_BASE  31
int roll_hash(char * src, char * str){

    int   len_s = strlen(src);
    int   len_t = strlen(str);
    int i=0;
    int hash_value_s=0;
    int hash_value_t=0;
    int power =1;
    for(i=0;i<len_t;i++){
        hash_value_s = hash_value_s *PRIME_BASE +src[i];
        hash_value_t = hash_value_t *PRIME_BASE +str[i];      
        power = power* PRIME_BASE;    
  
    }
    if(hash_value_s == hash_value_t){
          printf("find out :%s index: %d \n",str,i);
          return 0;
    }
    else{

       for(i=len_t;i<len_s;i++){

              hash_value_s = hash_value_s*PRIME_BASE + + src[i];
              hash_value_s = hash_value_s - src[i-len_t]*power ;

              if(hash_value_s == hash_value_t ){
                     printf("find out :%s index: %d \n",str,i-len_t+1);
                     return i-len_t+1;
              }
       }

    }

     if(hash_value_s != hash_value_t ){
             printf("Don't find any suitable string\n");
             return -1;
     }  

}

void main(){

      printf("哈希字符串查找\n");
      hashInsert("tong");
      hashInsert("jiao");
      hashInsert("long");
      hashInsert("ni");
      hashInsert("hao");
      hashInsert("haha");
      hashInsert("haha");
      hashInsert("!!");      
      //print_hash();
      printf("find:%d\n",hash_search("haha"));

      hashDelete("haha");
      hashDelete("haha");

      printf("find:%d\n",hash_search("haha"));

     roll_hash("abcdeeda","ff");
}


