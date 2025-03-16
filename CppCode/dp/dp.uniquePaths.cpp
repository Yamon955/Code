//----------动态规划------求解在m行n列表格中从(0,0)到(m-1,n-1)有多少种不同的方式（每次只能向右或向下走）-----
//样例   1  3 ===> 1
//时间复杂度O(m*n)  空间复杂度O(m*n) 

#include<iostream>
using namespace std;
int uniquePaths(int m,int n)
{
	int f[m][n];//f[i][j] 表示从(0,0)到(i,j)的不同方式数量 
	int i,j;
	for(j=0;j<n;j++){//行数递增 
		for(i=0;i<m;i++){//列数递增   计算顺序：从左到右，从上到下 
			if(i==0||j==0){
				f[i][j]=1;//初始条件 
			}
			else 
				f[i][j]=f[i-1][j]+f[i][j-1];//最后一步一定是向右或向下 所以总方式数=到达(i-1,j)的方式数+到达(i,j-1)的方式数 
		}
	}
	return f[m-1][n-1];
 }
 
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<uniquePaths(m,n);
	return 0;
}
