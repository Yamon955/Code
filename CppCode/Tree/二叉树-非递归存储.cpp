#include<iostream>                    //输入样例ABC##DE#G##F###(先序次序) 
#include<malloc.h> 
#include<stack> 
#include<cstdio> 
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode, *BiTree;
void PreOrder(BiTNode *b)//先序遍历非递归实现 
{
	BiTNode *p;
	stack<BiTNode>st;
	if(b!=NULL){
		st.push(b);//根节点进栈 
		while(!st.empty()){//栈不为空时退出循环 
			p=st.pop();
			cout<<p->data<<" ";
			if(p->lchild!=NULL) st.push(p->lchild);
			if(p->rchild!=NULL) st.push(p->rchild);
		}
	} 
}
