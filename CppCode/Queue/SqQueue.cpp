//----------------------ѭ������_____���е�˳��洢�ṹ------------ 

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
#define Maxsize 10//�����г��� 
typedef  struct{
	int *base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ�� 
	int rear;//βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ�� 
}SqQueue; 

int Initqueue(SqQueue &Q)//����һ���ն���
{
	Q.base=(int *)malloc(Maxsize*sizeof(int));
	if(!Q.base) return error;//�洢����ʧ��
	Q.front=Q.rear=0;
	return ok; 
 } 
 
 
int Queuelength(SqQueue Q)//����Q��Ԫ�ظ����������еĳ��� 
{
	return (Q.rear-Q.front+Maxsize)%Maxsize;
}
 
 
int Enqueue(SqQueue &Q,int e)//����Ԫ��eΪ�µĶ�βԪ�� 
{
	if((Q.rear+1)%Maxsize==Q.front) return error;//������
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;
	return ok; 
}


int Dequeue(SqQueue &Q)//�����в��գ���ɾ����ͷԪ�� 
{
	if(Q.front==Q.rear)  return error;//�ж��Ƿ��ǿն��� 
	Q.front=(Q.front+1)%Maxsize;
	return ok;
 } 
 
 
void disp(SqQueue Q)
{
	int i,j=1;
	i=Q.front;
	cout<<"��ǰ����Ԫ��Ϊ:";
	while(j<=Queuelength(Q)){//���ѭ����������ΪQ.base[i]!=0��Q.base[i]!=NULL
	                         //��ô���洢��Ԫ������0ʱ����ӡ��0�ͻ������0��0֮���Ԫ���޷���ӡ 
		cout<<Q.base[i]<<" ";
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
	int e;
	cout<<"\n����Ҫ�����Ԫ��:";
	cin>>e;
	Enqueue(q,e);
	disp(q);
	cout<<"\nɾ����ͷԪ�غ�,";
	Dequeue(q);
	disp(q);
	return 0;
}










 
 
 
 
 
 
 
 
 
 

