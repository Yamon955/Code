#include<stdio.h>
#include<malloc.h>
#define error 0
#define ok    1

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
	
} LNode, *Linklist;
typedef int Status;

Status Initlist(Linklist &L)
{ // 操作结果：构造一个空的线性表L
    // 产生头结点,并使L指向此头结点
    L = (Linklist)malloc(sizeof(LNode)); 
    if(!L) 	            	// 存储分配失败
        return error;
    L->next = NULL; 		// 指针域为空
    return ok;
}

Status Getelem(Linklist L,int i,ElemType &e)//获取第i个元素，其值赋给e，返回 Ok ，否则反回error; 
{
	LNode *p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i) return error;
	e=p->data;
	return e;
 } 
 
 Status ListInsert(Linklist &L,int i,ElemType e)
 {
 	LNode *p=L;
 	int j=0;
 	while(p&&j<i-1){
 		p=p->next;
 		j++;
	 }
	 if(!p||j>i-1) return error;
	 LNode *s=(Linklist)malloc(sizeof(LNode));
	 s->data=e;
	 s->next=p->next;
	 p->next=s;
	return ok; 
 }
 
Status ListDelete(Linklist L,int i,ElemType &e)
{
	LNode *p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||j>i-1) return error;
	LNode *q=p->next;
	p->next=q->next;
	e=q->data;
	return ok;
}

int Displist(Linklist L)
{
	LNode *p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}

void Showaddress(Linklist L)
{
	int i;
	LNode *p=L->next;
	if(p!=NULL){
		printf("\n头节点的地址为：\t%p\n",L);
		for(i=1;p!=NULL;i++){
			printf("第%d个结点的值：\t%d;地址为：%p\n",i,p->data,p);
			p=p->next;
		}
	} 
}

int main()
{
	int a[5],i,j;
	Linklist L;
	Initlist(L);
	 printf("\n\n输入存入链表中的数据：");
    for(i = 1, j = 0; i <= 5; i++, j++){
    	scanf("%d",&a[j]);
    	ListInsert(L, i, a[j]);
	}
	Displist(L);
	Showaddress(L);
	return 0;
}

