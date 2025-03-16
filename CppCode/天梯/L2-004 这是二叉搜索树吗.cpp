#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e4+50;

int n;
int a[N],b[N];
int cnt;
typedef struct node{
	int data;
	node* L;
	node* R;
}Node,*Tree;
Tree T = NULL;

Tree build()
{
	Tree tmp = (Tree)malloc(sizeof(Node));
	tmp->data = a[1];
	tmp->L = tmp->R = NULL;
	return tmp;
}
void insert(Tree &T,int pos)  //这里插入的函数 T 一定要用引用 &T,否则插入不成功，
                             //但是镜像翻转就不用引用也行，建议对于改变树的结构的操作都用引用
{
	if(T == NULL) {
		Tree tmp = (Tree)malloc(sizeof(Node));
		tmp->data = a[pos];
		tmp->L = tmp->R = NULL;
		T = tmp;
		return;
	}
	if(a[pos] < T->data) insert(T->L,pos);
	else insert(T->R,pos);
}
void search(Tree T)  //层次遍历
{ 
	queue<Tree>q;
	q.push(T);;
	while(!q.empty()){
		Tree tmp;
		tmp = q.front();
		q.pop();
		b[++cnt] = tmp->data;
		if(tmp->L) q.push(tmp->L);
		if(tmp->R) q.push(tmp->R);
	}
}
void fir(Tree T) //先根遍历
{
	if(T == NULL) return;
	b[++cnt] = T->data;
	fir(T->L);
	fir(T->R); 
}
void last(Tree T) //后序遍历
{
	if(T == NULL) return;
	last(T->L);
	last(T->R); 
	b[++cnt] = T->data;
}
void swap(Tree T)  //树的镜像反转
{
	if(T == NULL) return;
	Tree tmp = (Tree)malloc(sizeof(Node));
	tmp = T;
	Tree tmp2 = (Tree)malloc(sizeof(Node));
	tmp2 = tmp->L;
	tmp->L = tmp->R;
	tmp->R = tmp2;
	swap(tmp->L);
	swap(tmp->R);

}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	T = build();
	for(int i=2;i<=n;i++) insert(T,i);
	//cout<<T->L->data<<endl; 
	fir(T);
	int flag = 0;
	for(int i=1;i<=n;i++){
		if(a[i] != b[i]){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		cout<<"YES"<<endl;
		cnt = 0;
		last(T);
		for(int i=1;i<=n;i++){
			if(i == n) cout<<b[i];
			else cout<<b[i]<<" ";
		}
	}
	else{
		flag = 0;
		swap(T);
		cnt = 0;
		fir(T);
		for(int i=1;i<=n;i++){
			if(a[i] != b[i]){
				flag = 1;
				break;
			}
		}
		if(flag) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cnt = 0;
			last(T);
			for(int i=1;i<=n;i++){
				if(i == n) cout<<b[i];
				else cout<<b[i]<<" ";
			}
		}
	}
	
	return 0;
	
}
/*
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
const int N = 1e4+50;

int n;
int a[N];
int b[N],len;
typedef struct node{
	int key;
	node* L;
	node* R;
}Node,*Tree;
Tree T = NULL;

void insert(Tree &T,int w)
{
	if(T == NULL){
		Tree tmp = (Tree)malloc(sizeof(Node));
		tmp->key = w;
		tmp->L = tmp->R = NULL;
		T = tmp;
		return;
	}
	if(w < T->key) insert(T->L,w);
	else insert(T->R,w);
}
void fir(Tree T)
{
	if(T == NULL) return;
	b[++len] = T->key;
	fir(T->L);
	fir(T->R);
}
void swap(Tree &T)
{
	if(T == NULL) return;
	Tree tmp;
	tmp = T->L;
	T->L = T->R;
	T->R = tmp;
	swap(T->L);
	swap(T->R);
}
void last(Tree T)
{
	if(T == NULL) return;
	last(T->L);
	last(T->R);
	len ++;
	if(len == n) cout<<T->key;
	else cout<<T->key<<" ";
 } 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(T,a[i]);
	} 
	len = 0;
	fir(T);
	int i;
	for(i=1;i<=n;i++){
		if(a[i] != b[i]) break;
	}
	if(i > n) {
		cout<<"YES"<<endl;
		len = 0;
		last(T);
		return 0;
	}
	else{
		swap(T);
		len = 0;
		fir(T);
		for(i=1;i<=n;i++)
			if(a[i] != b[i]) break;
		if(i > n){
			cout<<"YES"<<endl;
			len = 0;
			last(T);
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
	
	
	
	
}

*/