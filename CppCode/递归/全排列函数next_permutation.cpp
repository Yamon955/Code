#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
����STL�ĵ���������next_permutation����������ĸ��˳�����ɸ������е���һ���ϴ�����У�ֱ����������Ϊ����Ϊֹ��prev_permutation������֮�෴�������ɸ������е���һ����С�����С�

����һ����һ���������һ�����еĺ��������Ա���ȫ����,Ҫ����ͷ�ļ�<algorithm>

ʹ�÷�����next_permutation(����ͷ��ַ������β��ַ);����һ�����д��ڣ��򷵻��棬����������򷵻ؼ�

������һ�����У�����prev_permutation
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

