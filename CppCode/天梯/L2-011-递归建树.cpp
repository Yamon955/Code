#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<string>
#include<malloc.h>
using namespace std;
bool fist;
const int maxn=40;
struct tree_node
{
  int value;
  tree_node* leftchild;
  tree_node* rightchild;
  tree_node()
  {
    leftchild=NULL;
    rightchild=NULL;
  }
};
tree_node* build_tree(int pre[],int in[],int length)
{
  if(length==0)return NULL;//终止条件   
  tree_node* temp = (tree_node*)malloc(sizeof(tree_node));
  int pos;  
  for(pos=0;pos<length;pos++)//找到根节点->然后根据中序遍历把左子树和右子树分开 
  {
    if(in[pos]==pre[0])break;
  }  
  temp->value=pre[0];
  temp->leftchild=build_tree(pre+1,in,pos);
  temp->rightchild=build_tree(pre+pos+1,in+pos+1,length-pos-1);
  return temp;
}
void dfs(tree_node* tree)
{
  queue<tree_node*>Q;
  while(!Q.empty())Q.pop();
  Q.push(tree);
  tree_node* root;
  while(!Q.empty())
  {
    root=Q.front();
    Q.pop();
    if(!fist)
    {
      cout<<root->value;
      fist=true;
    }
    else cout<<" "<<root->value;  
    if(root->rightchild!=NULL)
    {
      tree_node* rchild=root->rightchild;
      Q.push(rchild);
    }  
    if(root->leftchild!=NULL)
    {
      tree_node* lchild=root->leftchild;
      Q.push(lchild);
    }    
  }
  cout<<endl;
}
int main()
{
  int n;
  int pre[maxn],in[maxn];
  while(scanf("%d",&n)==1)
  {
    fist=false;
    //input
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    for(int i=0;i<n;i++)scanf("%d",&pre[i]);
    //solve
    tree_node* tree=build_tree(pre,in,n);
    dfs(tree);
  }
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
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e4+50;

int n;
int a[N],b[N];
typedef struct node{
	int data;
	node* L;
	node* R;
}Node,*Tree;
Tree T = NULL;

Tree build(int l,int r,int s)
{
	if(l > r){
		return NULL;
	}
	int i;
	for(i=l;i<=r;i++){
		if(a[i] == b[s]) break;
	}
	Tree t = (Tree)malloc(sizeof(Node));
	t->data = b[s];
	//cout<<s+1<<"    "<<s+1+(i-l)<<endl;
	t->L = build(l,i-1,s+1);
	t->R = build(i+1,r,s+1+(i-l));
	return t;
	
}
void swap(Tree T)
{
	if(T->L == NULL && T->R == NULL){
		return;
	}
	//Tree tmp = (Tree)malloc(sizeof(Node));
	Tree tmp;
	tmp = T->L;
	T->L = T->R;
	T->R = tmp;
	if(T->L != NULL) swap(T->L);
	if(T->R != NULL) swap(T->R);
	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	T = build(1,n,1);
	swap(T);
	queue<Tree>q;
	cout<<T->data;
	
	q.push(T);
	while(!q.empty()){
		//Tree tmp = (Tree)malloc(sizeof(Node));
		Tree tmp;
		tmp = q.front();
		q.pop();
		if(tmp->L != NULL) {
			q.push(tmp->L);
			cout<<" "<<tmp->L->data;	
		}
		if(tmp->R != NULL) {
			q.push(tmp->R);	
			cout<<" "<<tmp->R->data;
		}
		
	}
	return 0;
	
	
 } 
*/
