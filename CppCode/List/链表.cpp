#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};//创建一个结构体来表示结点类型 
int main()
{
	struct node *head,*p,*t,*q;
	int i,a,n;
	scanf("%d",&n);//头指针初始为空 
	head=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&a);//循环读入n个数 
		p=(struct node *)malloc(sizeof(struct node));//动态申请一个空间，用来存放一个结点，并用临时指针p指向这个结点 
		p->data=a;//将数据a存放到当前结点的data域中 
		p->next=NULL;//设置当前结点的后继指针指向空 
		if(head==NULL)
		  head=p;//如果这是第一个创建的结点，则将头指针指向这个结点 
		else
		  q->next=p;//如果不是第一个创建的结点，则将上一个节点的后继指针指向当前结点
		q=p;//指针q也指向当前结点 
	}
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//继续下一个结点
	}
	return 0;
}
