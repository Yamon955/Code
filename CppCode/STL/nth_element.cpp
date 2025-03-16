#include<iostream>
#include<algorithm>
using namespace std; 
int main()
{
	int a[]={1,3,4,5,2,6,8,7,9};
	int i;
	cout<<"数列如下："<<endl;
	for(i=0;i<9;i++)
	   cout<<a[i]<<" ";
	nth_element(a,a+5,a+9);
    cout<<endl<<"输出第五小的数： "<<a[5]<<endl; //注意下标是从0开始计数的 ，第0小，第1小‘’‘’‘’‘’‘’第n-1小
	return 0;
}
/*
nth_element()函数
函数语句：nth_element(数组名,数组名+第k小元素,数组名+元素个数)

?

头文件：#include<algorithm>

作用：nth_element作用为求第n大的元素，并把它放在第n位置上，下标是从0开始计数的，也就是说求第0小的元素就是最小的数。

如：a[start,end]元素区间。排序后a[n]就是数列中第n+1大的数（下标从0开始计数）。要注意的是a[start,n),

??? a[n,end]内的大小顺序还不一定。只能确定a[n]是数列中第n+1大的数。当然a[start,n)中的数肯定不大于

??? a[n,end]中的数。

注意：nth_element()函数仅仅是将第n大的数排好了位置，并不返回值。

*/