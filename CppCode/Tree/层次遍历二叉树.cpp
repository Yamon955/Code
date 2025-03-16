#include<iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
int count=0;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode, *BiTree;
void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T=(BiTNode *)malloc(sizeof(BiTree));
		if(!T) exit(-1);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}	
}
void LevelorderTraverse(BiTree T)//层次遍历
{
	//if(T==NULL) return;
	if(T!=NULL){
		BiTree Q[100],p;//Q是队列，元素为二叉树结点指针 
		int front=1,rear=1,last=1;//front队头指针，rear队尾指针，last为同层最右边的结点在队列中的位置 
		Q[rear]=T;//根节点入队 
		while(front<=last){
			p=Q[front++];
		    if(p->lchild!=NULL) Q[++rear]=p->lchild;//左子女入队 
			if(p->rchild!=NULL) Q[++rear]=p->rchild;//右子女入队 
			if(front>last){//一层结束 
				last=rear;//last指向下层最右元素 
			}
		}
		for(int i=1;i<=rear;i++) cout<<Q[i]->data<<endl;
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
 int width_max(BiTree T)//层次遍历求最大宽度 
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
 int main()
 {
 	BiTree T;
 	CreateBiTree(T);
 	LevelorderTraverse(T);
 	return 0;
 }
