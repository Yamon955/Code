#include<stdio.h>
#include<malloc.h>
#define error 0
#define ok    1

typedef int ElemType;
typedef struct LNode{
	
	ElemType data;
	LNode *next;
	
} LNode, *Linklist;
typedef int Status;

Status Initlist(Linklist &L)//��ʼ������ 
{ // �������������һ���յ����Ա�L
    // ����ͷ���,��ʹLָ���ͷ���
    L = (Linklist)malloc(sizeof(LNode)); 
    if(!L) 	            	// �洢����ʧ��
        return error;
    L->next = NULL; 		// ָ����Ϊ��
    return ok;
}

void Createlist(Linklist &L,int n)
{
	L=(Linklist)malloc(sizeof(LNode));
	L->next=NULL;
	printf("\n���������е����ݵ�����");
	for(int i=n;i>0;--i){
		LNode *p=(Linklist)malloc(sizeof(LNode));
		scanf("%d",&p->data);
	    p->next=L->next;
	    L->next=p;
	}
}

Status Getelem(Linklist L,int i,ElemType &e)//��ȡ��i��Ԫ�أ���ֵ����e������ Ok �����򷴻�error; 
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
		printf("\nͷ�ڵ�ĵ�ַΪ��\t%p\n",L);
		for(i=1;p!=NULL;i++){
			printf("��%d������ֵ��\t%d;��ַΪ��%p\n",i,p->data,p);
			p=p->next;
		}
	} 
}

 
 int main()
 {
 	int i, n, e;
    printf("\n���������д洢���ݵĸ�����");
    scanf("%d",&n);
	Linklist L;
    Createlist(L,n);
    printf("������Ԫ�����У�");
	Displist(L); 
    printf("\n����Ҫ����Ԫ��λ��:");
    scanf("%d",&i);
    printf("\n����Ҫ����Ԫ��:");
    scanf("%d",&e);
    ListInsert(L,i,e);
    printf("\n�������������:");
	Displist(L);
	printf("\n����Ҫɾ����λ��:");
	scanf("%d",&i);
	ListDelete(L,i,e);
	printf("\nɾ������������:");
	Displist(L);
	Showaddress(L);
	return 0;
 }
