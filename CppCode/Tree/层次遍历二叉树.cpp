#include<iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
int count=0;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
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
void LevelorderTraverse(BiTree T)//��α���
{
	//if(T==NULL) return;
	if(T!=NULL){
		BiTree Q[100],p;//Q�Ƕ��У�Ԫ��Ϊ���������ָ�� 
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
		    if(p->lchild!=NULL) Q[++rear]=p->lchild;//����Ů��� 
			if(p->rchild!=NULL) Q[++rear]=p->rchild;//����Ů��� 
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
			}
		}
		for(int i=1;i<=rear;i++) cout<<Q[i]->data<<endl;
	}

 } 
 int DegreeOne_count(BiTree T)//��α������Ϊ1�Ľ����� 
{
	int num=0;//ͳ�ƶ�Ϊ1�Ľ����� 
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
			if(p->lchild==NULL&&p->rchild!=NULL){
				Q[++rear]=p->rchild;
				num++;//ֻ���Һ��ӣ���Ϊ1���Һ�����ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild==NULL){
				Q[++rear]=p->lchild;
				num++;//ֻ�����ӣ���Ϊ1��������ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild!=NULL){
				Q[++rear]=p->lchild;//���Һ��Ӷ��У���Ϊ2�����Һ������ 
				Q[++rear]=p->rchild;
			}
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
			}
		}
	   return  num;	
	}
 } 
 int width_max(BiTree T)//��α���������� 
{
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		int temp=0,maxw=0;//temp��ʱ��¼ÿ��Ŀ�ȣ�maxw��¼����� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
			temp++;//ͬ��������1 
			if(p->lchild!=NULL) Q[++rear]=p->lchild;//����Ů��� 
			if(p->rchild!=NULL) Q[++rear]=p->rchild;//����Ů��� 
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
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
