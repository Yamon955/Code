/*
??????????n??????num????????��??m?��???��????????????????��?

???????��?????????��?��???????? "?��?" ??��,????????��?
*/
/*?????��??
?????????��??????��?minn(???????????)~maxn(????????????) 
???????????????mid?????????????????��??��????????
*/ 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,m;
int num[100010];
int judge(int a[],int mid)//????mid??????????????? 
{
	int sum=0,count=0;//coun???????mid??????????? 
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>=mid){
			sum=a[i];
			count++;
		}
	}
	if(count<m) return 1;//?????????mid????????????????m,??????mid???????????mid????? 
	else return 0;
 } 
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int maxn=0;
		int minn=0;
		for(int i=0;i<n;i++) {
			cin>>num[i];
			maxn+=num[i];  //maxn?????????????? 
			if(minn<num[i]) minn=num[i];//minn?????????????? 
		}                        //?????????��??????��?minn(???????????)~maxn(????????????) 
		while(minn<maxn){
			int mid=(minn+maxn)/2;
			if(judge(num,mid)) { // 
				maxn=mid;
			}
			else minn=mid+1;
		}
		cout<<minn-1<<endl;
	}
	return 0;
}
/*
5 3
4 2 4 5 1
-->6
*/ 

/* 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,m;
int num[100010];
int judge(int a[],int mid)//????mid??????????????? 
{
	int sum=0,count=0;//coun???????mid??????????? 
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>=mid){
			sum=a[i];
			count++;
		}
	}
	if(count<m) return 1;//?????????mid????????????????m,??????mid???????????mid????? 
	else return 0;
 } 
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int maxn=0;
		int minn=0;
		for(int i=0;i<n;i++) {
			cin>>num[i];
			maxn+=num[i];  //maxn?????????????? 
			if(minn<num[i]) minn=num[i];//minn?????????????? 
		}                        //?????????��??????��?minn(???????????)~maxn(????????????) 
		while(minn<maxn){
			int mid=(minn+maxn)/2;
			if(judge(num,mid)) { // 
				maxn=mid;
			}
			else minn=mid+1;
		}
		cout<<minn-1<<endl;?????????????l-1??????�b???????????????mid?????l = mid + 1 ?????????????????????l = r??????????????l - 1??????????mid 
	}
	return 0;
}
*/
