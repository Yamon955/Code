//--------------------------����_____���е�˳��洢�ṹ---------------------------- 

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
#define Maxsize 100//�����г��� 
typedef struct{
	int *base;
	int front;//ָ���ͷԪ�� 
	int rear;//ָ���βԪ�ص���һ��λ�� 
}SqQueue;

int Initqueue(SqQueue &q)//����һ���ն��� 
{
	q.base=(int *)malloc(Maxsize*sizeof(int));
	if(!q.base) return error;
	q.front=q.rear=0;
	return ok;
}


int Queuelength(SqQueue q)//���� �ĳ��� 
{
	return (q.rear-q.front);
}


int Enqueue(SqQueue &q,int e)//����Ԫ��eΪ�µĶ�βԪ�� 
{
	if(q.rear==Maxsize) return error;//�������� 
	q.base[q.rear]=e;
	q.rear=q.rear+1;
	return ok;
}

int Dequeue(SqQueue &q)
{
	if(q.front==q.rear) return error;
	q.front=q.front+1;
	return ok;
 } 


void disp(SqQueue q)
{
	int i,j=1;
	i=q.front;
	cout<<"��ǰ��������Ϊ:";
	while(j<=Queuelength(q)){
		cout<<q.base[i]<<" ";
		i++;
		j++;
	}
}


int main()
{
	SqQueue q;
	Initqueue(q);
	int n;
	cout<<"����Ҫ��ŵ�Ԫ�ظ���:";
	cin>>n;
	int a[n],i;
	cout<<"����Ҫ��ŵ�Ԫ��:";
	for(i=0;i<n;i++){
		cin>>a[i];
		Enqueue(q,a[i]);
	}
	disp(q);
	cout<<"\n����Ҫ���뵽��β��Ԫ��:" ;
	int e;
	cin>>e;
	Enqueue(q,e);
	disp(q);
	cout<<"\nɾ����ͷԪ�غ�";
	Dequeue(q);
	disp(q); 
	return 0;
}











