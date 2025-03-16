#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e5+50;

int n;
typedef struct po{ //个人结构体 
	int cnt;
	int area;
}Peo;
Peo po[N];

typedef struct node{  //家庭结构体 
	int id;   //家庭成员的最小编号 
	int sum;  //家庭人口数 
	int sum_cnt; //房产套数
	int sum_area; //房产面积
}Node;
Node no[N]; 

int p[N];
int vis[N],mp[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x]; 
}
void uion(int x,int y)
{
	if(find(x) != find(y)){
		//通过比较当前根节点的值来保证  家庭成员的最小编号  做根节点 
		if(find(x) > find(y)) p[find(x)] = find(y);
		else p[find(y)] = find(x);
	}
}
bool cmp(Node a,Node b)
{
	if(1.0*a.sum_area/a.sum != 1.0*b.sum_area/b.sum)
		return 1.0*a.sum_area/a.sum > 1.0*b.sum_area/b.sum;
	else return a.id < b.id;
}
int main()
{
	cin>>n;
	for(int i=0;i<N;i++) p[i] = i;
	for(int i=1;i<=n;i++){
		int id,f,m,k;
		cin>>id>>f>>m>>k;
		vis[id] = 1;
		if(f != -1){
			uion(id,f);
			vis[f] = 1;
		} 
		if(m != -1){
			uion(id,m);
			vis[m] = 1;
		}
		while(k --){
			int son;
			cin>>son;
			uion(id,son);
			vis[son] = 1;
		}
		cin>>po[id].cnt>>po[id].area;
	}
	
	int cnt  =0;
	for(int i=0;i<N;i++) if(p[i] == i && vis[i]) {
		mp[i] = cnt;  //相当于map ，将家庭成员的最小编号赋值，便于后续输出 
		cnt++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<N;i++){
		if(vis[i]){
			int idx = mp[find(i)];
			no[idx].id = find(i);
			no[idx].sum += 1;
			no[idx].sum_cnt += po[i].cnt;
			no[idx].sum_area += po[i].area;
		}
	}

	sort(no,no+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",no[i].id,no[i].sum,double(1.0*no[i].sum_cnt/no[i].sum),double(1.0*no[i].sum_area/no[i].sum));
	}
}



