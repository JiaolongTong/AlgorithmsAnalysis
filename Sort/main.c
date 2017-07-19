#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NUM  15
// http://blog.csdn.net/u014682691/article/details/50787366
void show_sorted(int array[],int n){

     printf("Sorted:");
     for(int i=0;i<n;i++){
                  printf("%d,",array[i]);
     }
     printf("\n");

}

void sample_Bucket_Sort(){
     int perSort[15]={8,1,4,5,0,9,6,7,6,1,1,3,1,5,8};
     int score[10]={0,0,0,0,0,0,0,0,0,0};
     int i,j;
     for(i=0;i<15;i++){
             score[perSort[i]]++;
     }
     for(i=9;i>=0;i--){
           for(j=1;j<=score[i];j++){
                  printf("%d,",i);
           }
     }
     printf(" \n");

}

int perSort[NUM]={8,1,4,5,0,9,6,7,6,1,1,3,1,5,8};
 
//int perSort[NUM]  ={1,3,5,7,9,2,4,6,8,10};
void Insert_Sort(){
  
     int Tmp,i,j;
     for(i=1;i<NUM;i++){                            // 0-i-1 (已排序) i--->NUM-1 (未排序)
        Tmp=perSort[i];                             // 取第一个未排序的数   Tmp                                  
        for(j=i-1;j>=0;j--){ 
           perSort[j+1] =perSort[j];                // 不断为Tmp插入留出空位
           if(Tmp > perSort[j])break;               // 找到第一个比Tmp小的数的位置j（升序）便退出循环
        }
        perSort[j+1]=Tmp;                           // 将Tmp插入j+1位置
     }
     show_sorted(perSort,NUM);
}

void BinInsert_Sort(){

     int Tmp,i,j;
     int left,right,middle;
     for(i=1;i<NUM;i++){
          Tmp = perSort[i];
          left = 0;
          right= i-1;
          while(left<=right){                        // 采用二分法查找最接近的数的位置
               middle = (left+right)/2;
               if( Tmp > perSort[middle] )
                    right = middle-1;
               else
                    left  = middle+1;
                          
          }
          for(j=i-1;j>=left;j--)
              perSort[j+1]=perSort[j];
          perSort[left]=Tmp;
     
     }
     
     show_sorted(perSort,NUM);
}

int perSortShell[10]={49,38,65,97,76,13,27,49,55,4};
//计算Hibbard增量
/*
int dkHibbard(int t,int k)
{
    return (int)(pow(2,t-k+1)-1);
}*/
void shellInsert(int Array[],int Num,int dk){

       int i,j,k;
       int Tmp;
       for(k=0;k<dk;k++){
           for(i=1;i<Num/dk;i++){
               Tmp=Array[k+i*dk];
               for(j=i-1;j>=0;j--){
                    Array[k+(j+1)*dk]=Array[k+j*dk];
                    if(Tmp > Array[k+j*dk])break;
               }
               Array[k+(j+1)*dk]=Tmp;
           }
       }


}

void selectSort(int Array[],int num){


 int i,j,min;
 int tmp;


 for(i=0;i<num;i++){
    min=i;
    for(j=i+1;j<num;j++)
        if(Array[j]<Array[min])min=j;
    if(min!=i){
	    tmp=Array[i];
	    Array[i]=Array[min];
	    Array[min]=tmp;
    }
 }
}

void Bubble_Sort(){
 
    int perSort[NUM]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i,j,tmp;
    for(i=0;i<NUM-1;i++)
        for(j=0;j<NUM-i-1;j++){
             if(perSort[j] < perSort[j+1]){
                       tmp=perSort[j+1];
                       perSort[j+1]=perSort[j];
                       perSort[j]=tmp;
             }
        }
     show_sorted(perSort,NUM);

}

/*
      分治算法Pritition

A    look选取参考数
B    以参考数为基准，使其左边的数都大于它，右边的数都小于它

*/
int Partition(int Array[],int begin,int end){

     int i,j;
     int tmp,look;

     i=begin;
     j=end;
     
     look=Array[begin];
     while(i!=j){
            
            while(Array[j] <= look && i<j)j--;
            while(Array[i] >= look && i<j)i++;

            if(i<j){
                tmp=Array[i];
                Array[i]=Array[j];
                Array[j]=tmp;

            }

    }
    Array[begin]=Array[i];
    Array[i]=look;
    return i;
}
/*
        寻找前k大数(第k大数)   
A   运用分治算法，将使右边数都比比较大的数
B   检查分界点index，若index>k-1，则将搜索范围向小的方向缩小end=index-1
                    若index<k-1，则将搜索范围向大的方向扩大begin=index+1
C   若index=k-1,则找到第k大的数，退出搜索，输出前k个数       

*/
int findBigist_K_Number(int Array[],int k,int num){

    int index;
    int begin;
    int end;
    begin=0;
    end  =num;
 
    while(index !=k-1 ){
       index=Partition(Array,begin,end);  
       if(index < k-1)   begin =index+1;
       else if(index>k)  end   =index-1;

    } 

    return index;

}
/*
        快速排序
A   运用分治算法,将序列分为两部分
B   在将两部分序列，各自递归的运用分治算法

*/
void Quick_Sort(int a[],int left ,int right){     
     int i,j,index,look,tmp; 
     if(left>=right)return;  

/*
     look=a[left];
     i=left;
     j=right;

     while(i!=j){

        while(a[j] >= look && i<j) j--;     

        while(a[i] <= look && i<j) i++;

 
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
        
     }
    
     a[left] = a[i];
     a[i]=look;
     index=i;
*/
     index=Partition(a,left,right);
     Quick_Sort(a,left,index-1);
     Quick_Sort(a,index+1,right);
   
}




 /*对以某一节点为根的子树做堆调整(保证最大堆性质)
void AdjustHeap(int Array[], int heap_size,int i )  
{  
    int lelt  = 2*i+1;  
    int right = 2*i+2;  
    int largest;  
    int temp;  
    if(lelt < heap_size && Array[lelt] > Array[i])  
    {  
        largest = lelt;  
    }  
    else  
    {  
        largest = i;  
    }  
    if(right < heap_size && Array[right] > Array[largest])  
    {  
        largest = right;  
    }  
    if(largest != i)  
    {  
        temp = Array[i];  
        Array[i] = Array[largest];  
        Array[largest] = temp;  
        AdjustHeap(Array, heap_size, largest);  
    }  
}  
 */ 

 /*对以某一节点为根的子树做堆调整(保证最大堆性质)*/
void AdjustHeap(int Array[] ,int num,int h){
     int i,j,flag;
     int tmp;
     i=h;
     j=2*i+1;
     flag=0;     
     while(j<num && flag !=1){
          tmp=Array[i];
          if(j<num-1 && (Array[j] < Array[j+1]) ) j++;
          if(tmp < Array[j]){
             Array[i]=Array[j];
             Array[j] = tmp;
             i=j;
             j=2*i+1;                 
          }else{
             flag=1;
          }
     }
}
void InitGreatHeap(int Array[],int num){
     for(int i=0;i<num-1;i++) 
            AdjustHeap(Array,num,i);
}
void HeapSort(int Array[],int num){
    int i;
    int tmp;
    InitGreatHeap(Array,num);
    for(i=num;i>0;i++){
         tmp=Array[0];
         Array[0]=Array[i];
         Array[i]=tmp;
         AdjustHeap(Array,i,0);
    }    
}
/*
      (1) 递归的拆分两个相邻的序列
      (2) 指导相邻序列均只有一个元素（两个序列一定有序）
      (3) 将两个相邻有序的子序列合并成一个有序序列(两路归并)

*/
void merge(int Array[],int first,int last,int tmp[]){
      int middle =(first+last)/2;
      int fi = first;
      int li = middle+1;
      int k=0;
      while(fi<=middle && li<=last){
           if(Array[fi] <= Array[li] ) tmp[k++] = Array[fi++];
           else  tmp[k++] = Array[li++];
      }
      while(fi<=middle)tmp[k++] = Array[fi++];
      while(li<=last)tmp[k++]   = Array[li++];
  
      for(int i=0;i<k;i++)
           Array[first+i] =tmp[i];
}

void mergeSort(int Array[],int first,int last,int tmp[]){

     if(first<last){
           int mid= (first+last)/2;            // 以mid为分界
           mergeSort(Array,first,mid,tmp);     // 先使左边有序
           mergeSort(Array,mid+1,last,tmp);    // 再使右边有序
           merge(Array,first,last,tmp);        // 合并左右两边序列为有序
     }
}
/*
   A 随机征求图书编号
   B 按照编号由小到大输出图书
   C 并且每本图书只能购买一本
*/
int book[10] ={20,40,32,67,40,20,89,300,400,15};

void buyBook_afterSort(int StudNum, int book[] ){

     int Bit[1001]; 
     int i,j,sum=0;
     for(i=0;i<1001;i++) Bit[i]=0;

     
     for(i=0;i<StudNum;i++)
               Bit[book[i]] = 1;         
     for(i=0;i<1001;i++)
         if(Bit[i] == 1) sum++;
     printf("%d\n",sum);
     for(i=0;i<1001;i++)
         if(Bit[i] == 1) printf("%d ",i);      
      printf(" \n");
}

void buyBook_beforSort(int StudNum, int book[]){
     int i,sum=0;
     Quick_Sort(book,0,9);
     for(i=0;i<10;i++)
        if(book[i]!=book[i+1])sum++;
                
     printf("%d\n",sum);           
     for(i=0;i<10;i++){
         if(book[i]!=book[i+1]){
            printf("%d ",book[i]);
            
         }
     }  
     printf("\n");  
}
/*
   A 老师随机输入学生成绩（名字+成绩）
   B 中间可以随时修改任意一人的成绩
   C 输出结果是学生成绩由高到低的排列
*/
typedef struct Score{

    char  name[20];
    int   score;
}Score;

void Quick_sortScore(Score a[],int left ,int right){     
     int i,j;
     Score look,tmp; 
     if(left>=right)return;  


     look=a[left];
     i=left;
     j=right;

     while(i!=j){

        while(a[j].score <= look.score && i<j) j--;         

        while(a[i].score >= look.score && i<j) i++;

 
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
        
     }
    
     a[left] = a[i];
     a[i]=look;

     Quick_sortScore(a,left,i-1);
     Quick_sortScore(a,i+1,right);
}


int sortScoe(Score stud[]){
     int i=0,n=0;
     Score new; 
     while(1){
        Quick_sortScore(stud,0,n-1);
        printf("请输入学生成绩（姓名 成绩）:");
        scanf("%s %d",stud[n].name,&stud[n].score);
        if(strcmp(stud[n].name,"quit")==0)break;
        new = stud[n];
        for(i=0;i<n;i++){
            if(strcmp(stud[i].name,new.name)==0) {
               stud[i] = new;
               n--;
            }
        }
        n++;        
     }
     return n;
}



void main(int argc ,char ** argv)
{     int sum;
      //sample_Bucket_Sort();

      printf("冒泡排序算法");
      Bubble_Sort();
      

      //buyBook_afterSort(10,book);
      //buyBook_beforSort(10,book);
      //Score stud[100];
      //sum=sortScoe(stud);
      //for(int i=0;i<sum;i++){
      //    printf("姓名:%s  成绩:%d \n",stud[i].name,stud[i].score);  
      //}
       
       printf("插入排序算法");
       Insert_Sort();
       
       
       k
       printf("二分插入排序算法");
       BinInsert_Sort(); 
       
      
        printf("希尔插入排序算法");
        int shellADD[]={5,3,1};
	for(int i=0 ;i<3 ;i++){
	   shellInsert(perSortShell,10,shellADD[i]);
	   show_sorted(perSortShell,10);
	}
        
       printf("选择排序算法");
       selectSort(perSort,NUM);
       show_sorted(perSort,15);
       
       printf("快速排序算法");
       Quick_Sort(perSort,0,NUM-1);
       show_sorted(perSort,NUM);
 
       int k=4;
       printf("寻找第k=%d大的数:",k); 
       int index=findBigist_K_Number(perSortShell,4,10);
       for(int i=0;i<k;i++){
            printf("%d,",perSortShell[i]);
       }
       printf("\n第k=%d大的数:%d",k,perSortShell[index]);
       printf("\n"); 

       printf("堆排序算法");
       InitGreatHeap(perSortShell,10);
       show_sorted(perSortShell,10);

       printf("归并排序算法");
       int tmp[15];
       show_sorted(perSort,NUM);
       mergeSort(perSort,0,NUM-1,tmp);
       show_sorted(perSort,NUM);
}
