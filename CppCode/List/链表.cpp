#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};//����һ���ṹ������ʾ������� 
int main()
{
	struct node *head,*p,*t,*q;
	int i,a,n;
	scanf("%d",&n);//ͷָ���ʼΪ�� 
	head=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&a);//ѭ������n���� 
		p=(struct node *)malloc(sizeof(struct node));//��̬����һ���ռ䣬�������һ����㣬������ʱָ��pָ�������� 
		p->data=a;//������a��ŵ���ǰ����data���� 
		p->next=NULL;//���õ�ǰ���ĺ��ָ��ָ��� 
		if(head==NULL)
		  head=p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ�������� 
		else
		  q->next=p;//������ǵ�һ�������Ľ�㣬����һ���ڵ�ĺ��ָ��ָ��ǰ���
		q=p;//ָ��qҲָ��ǰ��� 
	}
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//������һ�����
	}
	return 0;
}
