#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
按照STL文档的描述，next_permutation函数将按字母表顺序生成给定序列的下一个较大的排列，直到整个序列为降序为止。prev_permutation函数与之相反，是生成给定序列的上一个较小的排列。

这是一个求一个排序的下一个排列的函数，可以遍历全排列,要包含头文件<algorithm>

使用方法：next_permutation(数组头地址，数组尾地址);若下一个排列存在，则返回真，如果不存在则返回假

若求上一个排列，则用prev_permutation
*/
int main()
{
	int a[4]={1,2,3,4};
	while(next_permutation(a,a+4)){
		for(int i=0;i<4;i++) cout<<a[i]<<" ";
		cout<<endl; 
	}
	return 0;
}

