/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/


#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    void push(int node) {
        
        stack1.push(node);
        
    }

    int pop() {

        int tmp=0;
        if(stack2.empty()!=1){
            tmp=stack2.top();
            stack2.pop();
        }else if(stack1.empty()!=1){
            while(!stack1.empty()){
                tmp=stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            tmp=stack2.top();
            stack2.pop();
        }
        return tmp;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main ()  {
      Solution mystack;
      Solution *a ;
      a = malloc();
       
      mystack.push(10);
      mystack.push(9);
      mystack.push(8);
        
      cout <<dec<<mystack.pop() << dec<< mystack.pop() << dec<<mystack.pop() << endl;
      return 0; 
 }
