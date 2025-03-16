/* POJ2456 */
/*有n个牛栏，选m个放进牛，相当于一条线段上有 n 个点，选取 m 个点，使得相邻点之间的最小距离值最大。
首先给出n个牛棚的位置，那么每个牛棚之间的最小距离是和相邻两个牛棚之
间的距离。因此，先给牛棚的位置排个序。将第一头牛放在0号位置，
二分法不断缩进距离d，如果前一头牛放到了xi处，就要将下一头放到
满足xi+d<=xj的最小的xj处。这样保证最近的两头牛之间的距离都不会比当前的最小值小，如果每个都能满足这样放就可以作为最小值。
*/ 
 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
int n,m;
int a[100005],v[100005];
int judge(int d)
{
	int count=1;//注意第一只牛已经放进牛棚a[0]位置了 ，故初值为1 
	int last=0; 
	for(int i=1;i<n;i++){
		if(a[i]-a[last]>=d){ //a[i]这个牛栏和上一个牛栏a[last]间距大于等于d，表示可以再放进牛
			last=i;
			count++;//又放进一头牛 
		}
	} 
	if(count>=m) return 1;//所有牛都放完了 
	else return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//对牛栏进行排序 
	int minn=1;//最小距离为1 
	int maxn=a[n-1]-a[0];//最大距离为牛栏号最大的减去牛栏号最小的 
	while(minn<maxn){
		int mid=(minn+maxn+1)>>1;
		if(judge(mid)) minn=mid;
		else maxn=mid-1;
	}
	cout<<minn<<endl;//至于为什么最后答案是l-1呢？假设到了最后一个成立的答案mid，此时l = mid + 1 ，那么下一个必定不成立并l = r退出，此时答案其实为l - 1，即上述的mid 
	return 0;
}
/*
5 3
1
2
8
4
9
-->3
*/

