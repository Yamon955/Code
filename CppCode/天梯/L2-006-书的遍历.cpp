#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+50;

int n;
int a[N],b[N];

typedef struct node{
	int data;
	node *left;
	node *right;
}node,*Tree;
Tree T = NULL;

Tree insert(int pos,int st,int end)
{
	if(st > end){
		return NULL;
	}
	int i;
	for(i=st;i<=end;i++)
		if(b[i] == a[pos]) break;
	Tree tree = (Tree)malloc(sizeof(node));
	tree->data = a[pos];
	tree->left = insert(pos-(end-i)-1,st,i-1);
	tree->right = insert(pos-1,i+1,end);
	return tree;
}
void search()
{
	queue<Tree>q;
	q.push(T);
	cout<<T->data;
	while(!q.empty())
	{
		if(q.front()->left != NULL){
			cout<<" "<<q.front()->left->data;
			q.push(q.front()->left);
		} 
		if(q.front()->right != NULL){
			cout<<" "<<q.front()->right->data;
			q.push(q.front()->right);
		} 
		q.pop();
	}

}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	T = insert(n,1,n);
	search();
	return 0;
	
}