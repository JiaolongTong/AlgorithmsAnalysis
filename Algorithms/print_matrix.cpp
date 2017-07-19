/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

*/

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    vector <int > res;
public:
     
     void cycle(int i,int j,int M,int N,vector<vector<int> > matrix){
        
        int ii,jj;
        int t;
        ii=i;
        jj=j;
       
       if(M>i && N>j){
		for(jj=j;jj<=N;jj++){
		    res.push_back(matrix[ii][jj]);
		}
		jj--;
		for(ii=i+1;ii<=M;ii++){
		    res.push_back(matrix[ii][jj]);
		}
		ii--;

		for(jj=jj-1;jj>=j;jj--){
		    res.push_back(matrix[ii][jj]);
		}
		jj++;
		for(ii=ii-1;ii>=i+1;ii--){
		    res.push_back(matrix[ii][jj]);
		}
		//cout<<endl;
       }else{
		if(N == j ){
			for(ii=i;ii<=M;ii++){
			    res.push_back(matrix[ii][jj]);
			}
		}else if(M == i) {
			for(jj=j;jj<=N;jj++){
			    res.push_back(matrix[ii][jj]);
			}   
		}
                return ;

        }
        if(M<=0 || N<=0) return ;
        cycle(i+1,j+1,M-1,N-1,matrix);
        //return 1;

    
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
              int N = (matrix[0].size())-1;
              int M = matrix.size()-1;
              int flag=1,i=0,j=0;
 
              //
              cycle(0,0,M,N,matrix);
              /*while(flag){
                  flag= cycle(i,j,M,N,matrix);
                  i++;
                  j++;
                  M--;
                  N--;
              }*/
              //cout<< endl;
              return res;
    }
};


int main ()  {
      Solution mywork;
        int i,j,m=100,n=100;
	vector<vector<int> > array(m); //这个m一定不能少
        vector <int > result;

	//初始化一个m*n的二维数组
	for(int i=0;i<m;i++) {
	    array[i].resize(n);
	}
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                 array[i][j]=i+j;//push_data(i+j);

      for(i=0;i<m;i++){
        cout<<endl;
        for(j=0;j<n;j++)
                 printf("%d ",array[i][j]);
      }
      cout<<endl;

      cout<<endl;
      result = mywork.printMatrix(array);
      cout <<"---------------------"<< endl;  
      for(i=0;i<result.size();i++)
          cout <<dec<<result[i]<<" ";
      cout<<endl;
      
      return 0; 
 }
