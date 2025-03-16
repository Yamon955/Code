#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1005;
typedef struct node{
	int data;
	node* lchild;
	node* rchild;
}BTnode,*BTree;
int n;
int a[N];
int cnt,flag;
void BT_insert(BTree& T,int data)
{
	if(T == NULL){
		T = new BTnode;
		T->data = data;
		T->lchild = T->rchild = NULL;
		return;
	}
	else if(data < T->data){
		BT_insert(T->lchild,data);
	}
	else BT_insert(T->rchild,data);
}
void RBT_insert(BTree& T,int data)
{
	if(T == NULL){
		T = new BTnode;
		T->data = data;
		T->lchild = T->rchild = NULL;
		return;
	}
	else if(data >= T->data) RBT_insert(T->lchild,data);
	else RBT_insert(T->rchild,data);
}
void Judge(BTree T)
{
	if(T != NULL){
		if(a[++cnt] != T->data){
			flag = 1;
			return;
		}
		Judge(T->lchild);
		Judge(T->rchild);
	}
}
void print(BTree T,int step)
{
	if(T == NULL) return;
	print(T->lchild,step+1);
	print(T->rchild,step+1);
	if(step != 0)
		cout<<T->data<<" ";
	else cout<<T->data;
}
int main()
{
	cin>>n;
	BTree T=NULL,RT=NULL;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		BT_insert(T,a[i]);
		RBT_insert(RT,a[i]);
	}
	flag = 0;
	cnt = 0;
	Judge(T);
	if(flag == 0){
		cout<<"YES"<<endl;
		print(T,0);
	}
	else{
		flag = 0;
		cnt = 0;
		Judge(RT);
		if(flag == 0){
			cout<<"YES"<<endl;
			print(RT,0);
		}
		else cout<<"NO"<<endl;
	}

}
/*
输入样例 1：
7
8 6 5 7 10 8 11
结尾无空行
输出样例 1：
YES
5 7 6 8 11 10 8
结尾无空行
输入样例 2：
7
8 10 11 8 6 7 5
结尾无空行
输出样例 2：
YES
11 8 10 7 5 6 8
结尾无空行
输入样例 3：
7
8 6 8 5 10 9 11
结尾无空行
输出样例 3：
NO
*/