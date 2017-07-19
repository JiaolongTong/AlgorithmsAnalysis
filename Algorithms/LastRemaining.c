/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再
回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一
个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)


*/




#include <stdio.h>
#include <stdlib.h> 
struct node{
    int num;
    struct node * next;
};

struct node *creat_cycle(int n){
   struct node * tail;
   struct node * p;
   int i;
   if(n==0)
        return NULL;
   else{
        tail=(struct node *)malloc(sizeof(struct node));
        tail->num=0;
        tail->next=tail;
        for(i=1;i<n;i++){
                p=(struct node *)malloc(sizeof(struct node));
                p->num = i;
                p->next = tail->next;
                tail->next = p;
                tail=p;
            }
        }
        return tail->next;
}
int LastRemaining_Solution(int n, int m)
{
        struct node *bakup,*p =creat_cycle(n) ;
        int i;
        if(p==NULL)return -1;


        while(p->next != p){
            
            for(i=0;i<m-1;i++){
                 bakup = p;
                 p=p->next;
            }

            bakup->next = p->next;
            free(p); 
            p=bakup->next;
        }
       
        return p->num;
}


void main(){



printf(" LastRemaining Student: %d \n",LastRemaining_Solution(5,2));


}

