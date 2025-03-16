 //--------------------------单链队列_____队列的链式存储结构-------------------------

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define ok 1
#define error 0
typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode,*Queueptr;//在定义结点时Qnode* = Queueptr(queueptr表示定义一个指针类型的结点)   例如:定义一个结点p的两种方式 Qnode *p 或者 Queueptr p; 
typedef struct{
	Queueptr front;//队头指针 
	Queueptr rear;//队尾指针 
}Linkqueue;

int Initqueue(Linkqueue &Q)//构造一个空队列 
{
	Q.front=Q.rear=(Queueptr)malloc(sizeof(Qnode));
	if(!Q.front) return error;//存储分配失败
	Q.front->next=NULL;
	return ok; 
}

int Destroyqueue(Linkqueue &Q)//销毁队列 
{
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return ok;
}


int Enqueue(Linkqueue &Q,int e)//插入元素e为新的队尾元素 
{
	Qnode *p;//另一种定义p的方式：Queueptr p;
	p=(Queueptr)malloc(sizeof(Qnode));
	if(!p) return error;       //存储分配失败 
	Q.rear->next=p;
	p->data=e;
	p->next=NULL;
	Q.rear=p;
	return ok; 
}


int dequeue(Linkqueue &Q)//若队列不空则删除队头元素 
{
	if(Q.front==Q.rear)  return error; 
	Qnode *p;//Queueptr p;
	p=Q.front->next;
	Q.front->next=p->next;	
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return ok;
}


void disp(Linkqueue Q)//打印队列 
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
	cout<<"输入要存放的元素个数:";
	cin>>n;
	int a[n],i;
	cout<<"输入要存放的元素:";
	for(i=0;i<n;i++){
		cin>>a[i];
		Enqueue(Q,a[i]);
	} 
	cout<<"当前队列排列为:";
	disp(Q);
	cout<<"\n输入要插入到队尾的元素:";
	int e;
	cin>>e;
	Enqueue(Q,e);
	cout<<"当前队列排列为:";
	disp(Q);
	cout<<"\n删除队头元素后,";
	dequeue(Q);
	cout<<"当前队列排列为:";
	disp(Q);
	return 0;
	
}

















