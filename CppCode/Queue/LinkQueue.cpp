 //--------------------------��������_____���е���ʽ�洢�ṹ-------------------------

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode,*Queueptr;//�ڶ�����ʱQnode* = Queueptr(queueptr��ʾ����һ��ָ�����͵Ľ��)   ����:����һ�����p�����ַ�ʽ Qnode *p ���� Queueptr p; 
typedef struct{
	Queueptr front;//��ͷָ�� 
	Queueptr rear;//��βָ�� 
}Linkqueue;

int Initqueue(Linkqueue &Q)//����һ���ն��� 
{
	Q.front=Q.rear=(Queueptr)malloc(sizeof(Qnode));
	if(!Q.front) return error;//�洢����ʧ��
	Q.front->next=NULL;
	return ok; 
}

int Destroyqueue(Linkqueue &Q)//���ٶ��� 
{
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return ok;
}


int Enqueue(Linkqueue &Q,int e)//����Ԫ��eΪ�µĶ�βԪ�� 
{
	Qnode *p;//��һ�ֶ���p�ķ�ʽ��Queueptr p;
	p=(Queueptr)malloc(sizeof(Qnode));
	if(!p) return error;       //�洢����ʧ�� 
	Q.rear->next=p;
	p->data=e;
	p->next=NULL;
	Q.rear=p;
	return ok; 
}


int dequeue(Linkqueue &Q)//�����в�����ɾ����ͷԪ�� 
{
	if(Q.front==Q.rear)  return error; 
	Qnode *p;//Queueptr p;
	p=Q.front->next;
	Q.front->next=p->next;	
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return ok;
}


void disp(Linkqueue Q)//��ӡ���� 
{
	Qnode *p;//Queueptr p;
	p=Q.front->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main()
{
	Linkqueue Q;
	Initqueue(Q);
	int n;
	cout<<"����Ҫ��ŵ�Ԫ�ظ���:";
	cin>>n;
	int a[n],i;
	cout<<"����Ҫ��ŵ�Ԫ��:";
	for(i=0;i<n;i++){
		cin>>a[i];
		Enqueue(Q,a[i]);
	} 
	cout<<"��ǰ��������Ϊ:";
	disp(Q);
	cout<<"\n����Ҫ���뵽��β��Ԫ��:";
	int e;
	cin>>e;
	Enqueue(Q,e);
	cout<<"��ǰ��������Ϊ:";
	disp(Q);
	cout<<"\nɾ����ͷԪ�غ�,";
	dequeue(Q);
	cout<<"��ǰ��������Ϊ:";
	disp(Q);
	return 0;
	
}

















