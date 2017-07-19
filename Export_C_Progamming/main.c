#include "main.h"


int testConst(const int c){  
   //c++;                    //编译报错，i是const修饰的只读变量(只在函数内部起作用，保证传入的实参不可被修改,但在函数外，对应实参的值是可以被其他函数修改的)
   char a;
   char b;
   char * const p1 = &a;  
   *p1 =b;  
   //p++;                    //编译报错，指针p1本身不能被修改(指向的内存地址是不可改变的)
   const char *p2  = &a;
   p2++;
   //*p2 = b;                //编译报错，指针p2本身不能被修改(指向的内存空间值是只读的)
   char const *p3  = &a;
   p3++;
   //*p3 = b;                //编译报错，与p2相同,指针p3本身不能被修改(指向的内存空间值是只读的)
   char const *const p4  = &a; 
   const char *const p5  = &a;
    
   //p4++;                   //编译报错，地址和内容均不能被修改                 
   //p5++;
   //*p4=b;
   //*p5=b;
}

void getMaxTime(){

  time_t biggest_t =0x7FFFFFFF;

  printf("A the biggest time :%s\n" ,ctime(&biggest_t));

  printf("B the biggest time :%s\n" ,asctime(gmtime(&biggest_t)));

}

void typeAutoConv(){
/*
寻常算数转换原则： 
    A 当执行算数运算时，操作数的类型如果不同，就会发生类型转换。
    B 数据类型一般朝着浮点精度更高的、长度更长的方向转换。
    C 整型如果转换成signed不会丢失信息，则向signed转换，否则向unsigned类型转换

使用无符号的建议：
    A 尽量不要使用无符号类型，以免增加不必要的麻烦，尤其是，不要仅仅因为数据不存在负值就使用无符号数。
    B 尽量使用想int这样的有符号类型，这样涉及到混合类型的复杂细节的时候，不必担心边界情况（如-1被转换成很大的正数）
    C 只有在使用段位和二进制掩码的时候(需要对位进行操作)，才可以使用无符号数。
    D 应该在表达式中强制转换，使操作数均是有符号或者无符号。
*/
    #define TOTAL_ELEMENTS  (sizeof(array)/sizeof(array[0]))   //这种宏定义方式，只需在定义数组时候改变类型即可
    //#define TOTAL_ELEMENTS  (sizeof(array)/sizeof(int))      //而第二种需要在定义完了后，在修改宏定义
    int array[] ={ 23,24 ,12, 17,204,99,16};

    int d=-1,x;
    unsigned int c=0;
    if(d<= TOTAL_ELEMENTS -2){        // 结果不是预期 计算结果是个无符号整型uinsgned int，由于int所表示的范围不足以容纳unsigned int，因此int型变量d被转换成了无符号整型，-1的无符号数为4294967295
       x=array[d+1];
       printf("x:%d \n",x);
    }
    printf("d:%ud len :%d \n",d ,TOTAL_ELEMENTS -2);

    if(d<=(int)(TOTAL_ELEMENTS) -2){  // 结果是预期  对TOTAL_ELEMENTS做强制类型转换
       x=array[d+1];
       printf("x:%d \n",x);
    }
    
    printf("sizeof('A') = %d \n", sizeof('A') );       // 结果是4  ,'A'  ->(signed int) 94   ->sizeof(signed ins) =4


    char a1 , a2 ,a3;  
    a3=a1 + a2;  
    printf ( "sizeof(a1+a2) = %d \n" ,sizeof(a1+a2)); 
}
/*第二章 语言本身产生的bug*/
void testBug(){     // 

    char str[100];
    char i;
    //memset(str,'\0',sizeof(char)*100);
    for(i='a';i<='z';i++){
         str[i-'a'] = i;
         printf("%c ,%d \n",str[i-'a'],i-'a');
    }
    str[i-'a'] = '\0';
    printf("%s\n",str);

}
void bugSwitch(){
/*
A      Switch 语句中每个case，包括default 均遵循fall throught原则。
       即，从匹配到的标签开始，从上往下依次执行，直到遇到break语句或者switch语句自然退出

B      Switch 语句中case 后的标签必须是常量，但不能是const修饰的变量，实际上const修饰的变量是只读变量。

C      break 语句事实上跳出的是最近的那一层循环或者switch语句

D      default一般放在最后的位置,但是它可以随便放，与case是平级的
*/
    int a =6;
    const int label =5;
    switch(a){
      case 1:printf("case 1\n");
      case 2:printf("case 2\n");
      default: printf("default\n");    
      case 3:printf("case 3\n");   break;
      case 4:printf("case 4\n");
      //case label: printf("case 5\n");  //编译报错
    }


}

void bugString(){
/*
    C语言允许相邻两个字符串常量将自动合并成一个字符串常量。
*/
    char *str[6]={ "aaa",
                   "bbb",
                   "ccc"         //缺少一个逗号“，”，编译不报错也不提醒，而是将两个引号之间的字符串合并成一个。自然也影响了数组的结构。
                   "ddd",
                   "eee",
                   "fff"
     };
     
    for(int i=0;i<6;i++)
        printf("str[i] = %s \n",str[i]);
}
/*
static 修饰的全局变量只能在申明它的源文件中引用,即使使用extern也不能将其扩展到其他源文件中

extern 修饰的变量表是该变量在其他源文件中申明为全局变量，在此处需要引用


static 修饰的局部变量只能在其作用域内使用，但是每次引用后其变量空间不会释放（因为它存放在.data区）

static 修饰一个函数，则他只能在本文件中使用。相当于将其私有化了。

*/

extern char * hello;   //file1种定义的全局变量hello，引入到本文件中
extern char * fine;    //file1种定义的全局变量fine ，fine在申明时被static修饰，可以引入进来，但是不能访问它
void fitstDefferent(char * str){
/*
   启发，这个特性可以使得一段程序在第一次的行为和以后的行为不同
*/
       static char separator=' ';     // static 
       printf("%c %s ",separator,str);
       separator=',';
}
void static_extren(){
   output();       
   printf("%s",hello);
   //printf("%s",fine);               //访问fine时会在连接阶段出错
}

void overLoad(){
   int N=5;

   int p;
   int *q=NULL;
   int *r=NULL;
   q  = malloc(sizeof(int)*6);
   p =N*sizeof*q;                     // sizeof*q 标识p指向的变量类型所占空间大小
   //p =N*sizeof(*q);                 // 这两句是等价的
   printf("p=%d\n",p);
   r =malloc(p);

   
/* 未测试通过
   int apple;
   char *s=NULL;
   s=malloc(sizeof(char)*2);
   //int s;
   apple  = sizeof(int) * s;
   printf("apple=%d\n",apple);
*/

}
typedef struct abc{
   int a;
   int b;
   int c;
}abc;
void bugPriority(){
    abc *p1;
    p1=malloc(sizeof(abc));
    (*p1).a;                    // .  的优先级高于 *
                                // [] 的优先级高于 *
    int *p2[5];                 // p2这个数组中存放了5个指向int的指针       
    int (*p3)[5];               // *p3的单元是个数组，它里面存放了5个整型元素
    int size=sizeof(abc);
    printf("sizeif(abc)=%d \n",size);
    for(int i=0;i<5;i++){
       p2[i] = malloc(sizeof(abc));
       printf("p2[%d]=%d \n",i,p2[i]);
    }
    for(int i=0;i<5;i++){       
        (*p3)[i] = i;
        printf("(*p3)[i]=%d \n",(*p3)[i]);
    }
    
}


int main(int argc ,char **argv){

  //getMaxTime()
  //testConst(i);
  //typeAutoConv();
  //testBug();
  //bugSwitch();
  //bugString();
  //fitstDefferent("AAA");
  //fitstDefferent("BBB");
  //fitstDefferent("CCC");
  //fitstDefferent("DDD");
  //printf("\n");
  //static_extren();
  //overLoad();
  //bugPriority();
  int x=21;
   int n=0;
   while((x+1)){
     n++; 
     x=x|(x+1);
    
  }
  printf("n=%d\n",n);
}
