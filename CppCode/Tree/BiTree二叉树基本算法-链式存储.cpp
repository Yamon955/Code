#include<iostream>                    //输入样例ABC##DE#G##F###(先序次序) 
#include<malloc.h> 
#include<cstdio> 
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode, *BiTree;
void CreateBiTree_1(BiTree &T)//按先序次序输入二叉树中结点的值 
{						    //对于不是满二叉树的用特殊字符‘#’来补全 ，
                            //将一般二叉树变为满二叉树来存储，但是存储时补全用的特殊字符不进行存储 
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;//空树
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T) exit(-1);//检测结点是否申请成功 
		T->data=ch;     //生成根节点 
		CreateBiTree_1(T->lchild);//构造左子树 
		CreateBiTree_1(T->rchild);//构造右子树 
	} 
 } 
/*void CreateBiTree_2(BiTree &T)//按中序次序输入二叉树中结点的值
{
	char ch;
	cin>>ch;
	T=(BiTree)malloc(sizeof(BiTNode));
	if(!T) exit(-1);//检测结点是否申请成功  		CreateBiTree_2(T->lchild);//构造左子树
	T->data=ch;     //生成根节点 
	CreateBiTree_2(T->rchild);//构造右子树  
 } 
 void CreateBiTree_3(BiTree &T)//按后序序次序输入二叉树中结点的值
{
	char ch;
	cin>>ch;

	T=(BiTree)malloc(sizeof(BiTNode));
	if(!T) exit(-1);//检测结点是否申请成功  
	CreateBiTree_3(T->lchild);//构造左子树
	CreateBiTree_3(T->rchild);//构造右子树 
	T->data=ch;     //生成根节点 
 } 
 */
void PreOrderTraverse(BiTree T)//先序遍历二叉树 
{
	if(T!=NULL){
		cout<<T->data<<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)////中序遍历二叉树 
{
	if(T!=NULL){
		InOrderTraverse(T->lchild);
		cout<<T->data<<" ";
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)//后序遍历二叉树 
{
	if(T!=NULL){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<" ";
	}
}
void swap(BiTNode *&T)//交换左右孩子 
{
	if(T!=NULL){
		if(T->lchild!=NULL&&T->rchild!=NULL){
			BiTNode *p=T->lchild;
			T->lchild=T->rchild;
			T->rchild=p;
		}
		swap(T->lchild);
		swap(T->rchild);
	}
 } 
void DestroyBiTree(BiTree &b)//销毁二叉树递归算法 
{							 //f(b)=不做任何事情，当b=NULL时 
	if(b!=NULL){             //f(b)=f(b->lchild);f(b->rchild);free(b) 当b!=NULL时 
		DestroyBiTree(b->lchild);
		DestroyBiTree(b->rchild);
		free(b);
	}
	else return;
 } 
int bt_height(BiTNode *T)//求二叉树高度(深度)递归算法1 
{						 //当T=NULL时，f(T)=0;其他情况，f(b)=max(f(b->lchild),f(b->rchild))+1 
	if(T==NULL) return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL) return 1;
		else return 1+max(bt_height(T->lchild),bt_height(T->rchild));
	}
 } 
int BTheight(BiTNode *b)//求二叉树高度递归算法2 
{
	int lh,rh;
	if(b==NULL) return 0;//空树高度为0 
	else{
		lh=BTheight(b->lchild);//求左子树的高度 
		rh=BTheight(b->rchild);//求右子树的高度 
	}
	return lh>rh?(lh+1):(rh+1); 
}
int width_max(BiTree T)//求最大宽度 
{
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front队头指针，rear队尾指针，last为同层最右边的结点在队列中的位置 
		int temp=0,maxw=0;//temp临时记录每层的宽度，maxw记录最大宽度 
		Q[rear]=T;//根节点入队 
		while(front<=last){
			p=Q[front++];
			temp++;//同层结点数加1 
			if(p->lchild!=NULL) Q[++rear]=p->lchild;//左子女入队 
			if(p->rchild!=NULL) Q[++rear]=p->rchild;//右子女入队 
			if(front>last){//一层结束 
				last=rear;//last指向下层最右元素 
				if(temp>maxw) maxw=temp;
				temp=0;
			}
		}
	   return  maxw;	
	}
 } 
int NodeCount(BiTNode *b)//求二叉树结点个数算法
{						 //当b=NULL时，f(b)=0;其他情况，f(b)=f(b->lchild)+f(b->rchild)+1 
	int lnum,rnum;
	if(b==NULL) return 0;//空树返回0
	else{
		lnum=NodeCount(b->lchild);//求左子树结点个数 
		rnum=NodeCount(b->rchild);//求右子树结点个数 
	} 
	return (lnum+rnum+1); 
 } 
 int leafCount(BiTree T)//求叶子结点个数 
 {
 	if(T==NULL) return 0;
 	else if(T->lchild==NULL&&T->rchild==NULL) return 1;
 	else return (leafCount(T->lchild)+leafCount(T->rchild));
 }
int DegreeTwo_count2(BiTree T)//递归求度为2的结点个数 
 {
 	int lnum,rnum,n;
 	if(T==NULL) return 0;
 	else {
 		if(T->lchild!=NULL&&T->rchild!=NULL) n=1;
 		else n=0;
 		lnum=DegreeTwo_count2(T->lchild);
 		rnum=DegreeTwo_count2(T->rchild);
	 }
	return (lnum+rnum+n);
}
   int DegreeTwo_count(BiTree T)//层次遍历求度为2的结点个数 
{
	int num=0;//统计度为1的结点个数 
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front队头指针，rear队尾指针，last为同层最右边的结点在队列中的位置 
		Q[rear]=T;//根节点入队 
		while(front<=last){
			p=Q[front++];
			if(p->lchild==NULL&&p->rchild!=NULL){
				Q[++rear]=p->rchild;
				//num++;//只有右孩子，度为1，右孩子入队，num++ 
			}
			else if(p->lchild!=NULL&&p->rchild==NULL){
				Q[++rear]=p->lchild;
				//num++;//只有左孩子，度为1，左孩子入队，num++ 
			}
			else if(p->lchild!=NULL&&p->rchild!=NULL){
				Q[++rear]=p->lchild;//左右孩子都有，度为2，左右孩子入队 
				Q[++rear]=p->rchild;
				num++;
			}
			if(front>last){//一层结束 
				last=rear;//last指向下层最右元素 
			}
		}
	   return  num;	
	}
 } 
 int DegreeOne_count(BiTree T)//层次遍历求度为1的结点个数 
{
	int num=0;//统计度为1的结点个数 
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front队头指针，rear队尾指针，last为同层最右边的结点在队列中的位置 
		Q[rear]=T;//根节点入队 
		while(front<=last){
			p=Q[front++];
			if(p->lchild==NULL&&p->rchild!=NULL){
				Q[++rear]=p->rchild;
				num++;//只有右孩子，度为1，右孩子入队，num++ 
			}
			else if(p->lchild!=NULL&&p->rchild==NULL){
				Q[++rear]=p->lchild;
				num++;//只有左孩子，度为1，左孩子入队，num++ 
			}
			else if(p->lchild!=NULL&&p->rchild!=NULL){
				Q[++rear]=p->lchild;//左右孩子都有，度为2，左右孩子入队 
				Q[++rear]=p->rchild;
			}
			if(front>last){//一层结束 
				last=rear;//last指向下层最右元素 
			}
		}
	   return  num;	
	}
 } 
int sum(BiTNode *b)//求所有结点值的和递归算法 
{				   //当b=NULL时，f(b)=0;其他情况时，f(b)=b->data+sum(b->lchild)+sum(b->rchild) 
	if(b==NULL) return 0;
	else return(b->data+sum(b->lchild)+sum(b->rchild));
}
void Route(BiTree T,char *path,int pathlen)//输出叶子节点到根节点的路径 
{
	if(T==NULL) return ;
	if(T->lchild==NULL&&T->rchild==NULL){
		cout<<endl<<T->data<<" ";
		for(int i=pathlen-1;i>=0;i--) cout<<path[i]<<" ";
	}
	else{
		path[pathlen++]=T->data;
		Route(T->lchild,path,pathlen);
		Route(T->rchild,path,pathlen);
	}
 } 
int main()
{
	BiTree T;
	cout<<"建立二叉树，输入结点值:";
	CreateBiTree_1(T);
	cout<<"先序遍历序列:";
	PreOrderTraverse(T);
	cout<<endl<<"中序遍历序列:";
	InOrderTraverse(T);
	cout<<endl<<"后序遍历序列:";
	PostOrderTraverse(T);
	cout<<endl<<"此二叉树高度:"<<BTheight(T);
	cout<<endl<<"此二叉树结点总数:"<<NodeCount(T);
	cout<<endl<<"此二叉树叶子节点个数:"<<leafCount(T);
	cout<<endl<<"最大宽度:"<<width_max(T); 
	cout<<endl<<"度为1的结点个数:"<<DegreeOne_count(T);
	char path[100]; 
	Route(T,path,0); 
	return 0;
	
}

