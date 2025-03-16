#include<iostream>                    //��������ABC##DE#G##F###(�������) 
#include<malloc.h> 
#include<stack> 
#include<cstdio> 
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode, *BiTree;
void PreOrder(BiTNode *b)//��������ǵݹ�ʵ�� 
{
	BiTNode *p;
	stack<BiTNode>st;
	if(b!=NULL){
		st.push(b);//���ڵ��ջ 
		while(!st.empty()){//ջ��Ϊ��ʱ�˳�ѭ�� 
			p=st.pop();
			cout<<p->data<<" ";
			if(p->lchild!=NULL) st.push(p->lchild);
			if(p->rchild!=NULL) st.push(p->rchild);
		}
	} 
}
