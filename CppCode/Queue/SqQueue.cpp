//----------------------循环队列_____队列的顺序存储结构------------ 

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
#define Maxsize 10//最大队列长度 
typedef  struct{
	int *base;//初始化的动态分配存储空间
	int front;//头指针，若队列不空，指向队列头元素 
	int rear;//尾指针，若队列不空，指向队尾元素的下一个位置 
}SqQueue; 

int Initqueue(SqQueue &Q)//构造一个空队列
{
	Q.base=(int *)malloc(Maxsize*sizeof(int));
	if(!Q.base) return error;//存储分配失败
	Q.front=Q.rear=0;
	return ok; 
 } 
 
 
int Queuelength(SqQueue Q)//返回Q的元素个数，即队列的长度 
{
	return (Q.rear-Q.front+Maxsize)%Maxsize;
}
 
 
int Enqueue(SqQueue &Q,int e)//插入元素e为新的队尾元素 
{
	if((Q.rear+1)%Maxsize==Q.front) return error;//队列满
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;
	return ok; 
}


int Dequeue(SqQueue &Q)//若队列不空，则删除队头元素 
{
	if(Q.front==Q.rear)  return error;//判断是否是空队列 
	Q.front=(Q.front+1)%Maxsize;
	return ok;
 } 
 
 
void disp(SqQueue Q)
{
	int i,j=1;
	i=Q.front;
	cout<<"当前队列元素为:";
	while(j<=Queuelength(Q)){//如果循环结束条件为Q.base[i]!=0或Q.base[i]!=NULL
	                         //那么当存储的元素中有0时，打印到0就会结束，0和0之后的元素无法打印 
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
	cout<<"输入要存放的元素个数:";
	cin>>n;
	int a[n],i;
	cout<<"输入要存放的元素:";
	for(i=0;i<n;i++){
		cin>>a[i];
		Enqueue(q,a[i]);
	}
	disp(q);
	int e;
	cout<<"\n输入要插入的元素:";
	cin>>e;
	Enqueue(q,e);
	disp(q);
	cout<<"\n删除队头元素后,";
	Dequeue(q);
	disp(q);
	return 0;
}










 
 
 
 
 
 
 
 
 
 

