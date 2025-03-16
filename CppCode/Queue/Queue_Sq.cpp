//--------------------------队列_____队列的顺序存储结构---------------------------- 

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
#define Maxsize 100//最大队列长度 
typedef struct{
	int *base;
	int front;//指向队头元素 
	int rear;//指向队尾元素的下一个位置 
}SqQueue;

int Initqueue(SqQueue &q)//构造一个空队列 
{
	q.base=(int *)malloc(Maxsize*sizeof(int));
	if(!q.base) return error;
	q.front=q.rear=0;
	return ok;
}


int Queuelength(SqQueue q)//队列 的长度 
{
	return (q.rear-q.front);
}


int Enqueue(SqQueue &q,int e)//插入元素e为新的队尾元素 
{
	if(q.rear==Maxsize) return error;//队列已满 
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
	cout<<"当前队列排列为:";
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
	cout<<"输入要存放的元素个数:";
	cin>>n;
	int a[n],i;
	cout<<"输入要存放的元素:";
	for(i=0;i<n;i++){
		cin>>a[i];
		Enqueue(q,a[i]);
	}
	disp(q);
	cout<<"\n输入要插入到队尾的元素:" ;
	int e;
	cin>>e;
	Enqueue(q,e);
	disp(q);
	cout<<"\n删除队头元素后，";
	Dequeue(q);
	disp(q); 
	return 0;
}











