#include<stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TURE 1
#define FALSE 0
#define OK 1
#define error 0
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

Status Initlist_Sq(Sqlist &L)//制一个空线性表表 
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*(sizeof(ElemType)));
	if(!L.elem) return error;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}
 
Status Destroylist(Sqlist &L)
{
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
}

int Getlength(Sqlist L)
{
	return L.length;
}

Status GetElem(Sqlist L,int i,ElemType &e)
{
	if(i<0||i>L.length)
	  return error;
	e=*(L.elem+i-1);
	return OK;
}

int LocatElem(Sqlist L,ElemType e)
{
	int i;
	for( i=0;i<L.length;i++){
		if(L.elem[i]==e)
		  break;
	}
	if(i<L.length) return i;
	else           return 0;
}

Status ListInsert_Sq(Sqlist &L,int i,ElemType e)
{
	if( i<1||i>L.length+1) return error;
	if(L.length>=L.listsize){
		ElemType *newbase=(ElemType *)realloc(L.elem,( 		if(!newbase) return error;
		L.elem=newbase;//为什么头地址=newbase 
		L.listsize+=LISTINCREMENT;
	}
	ElemType *p, *q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	
	*q=e;
	++L.length;
	return OK;
}

/*Status ListInsert_Sq(Sqlist &L, int i, ElemType e)
{   // 算法2.4；  i的合法值为1≤i≤L.Length+1
    ElemType *p;
    if(i < 1 || i > L.length + 1)
        return error;  		   // i值不合法
    if(L.length >= L.listsize) {    // 当前存储空间已满，增加容量
        ElemType *newbase = (ElemType *)realloc(L.elem,
                (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)
            return error;                 // 存储分配失败
        L.elem = newbase;                  // 新基址
        L.listsize += LISTINCREMENT;      // 增加存储容量
    } 
    ElemType *q = &(L.elem[i - 1]);       // q为插入位置
    for(p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;		         // 插入位置及之后的元素右移
    *q = e;       			// 插入e
    ++L.length;   			// 表长增1
    return OK;
}*/

Status ListDelete_Sq(Sqlist &L,int i)
{
	ElemType *p;
	p=&(L.elem[i-1]);
	for(int j=i-1;j<L.length-1;j++){
	  *p=*(p+1);
	  p++;
    }
    L.length-=1;
}

Status Deletek(Sqlist &L,int i,int k)//从线性表中删除第i个元素后的k个元素 
{
	if(i<1||k<1||k>L.length) return error;
	ElemType *p=&(L.elem[i-1]);
	for(int j=i+k-1;j<L.length;j++){
	  *p=*(p+k);
	  p++;
	}
	L.length-=k;
}

void Displist(Sqlist L)
{
	int i;
	for(i=1;i<=L.length;i++)
	  printf("%d ",L.elem[i-1]);
}
int main()
{
	int i,j,n;
	Sqlist list;
	Initlist_Sq(list);
	printf("\n输入数据个数:");
	scanf("%d",&n); 
	int a[n];
	printf("\n输入要输入的%d个数据元素:",n);
	for(i=1,j=0;i<=n;i++,j++){
	  scanf("%d",&a[j]);
	  ListInsert_Sq(list,i,a[j]);
    }
    printf("\n输入要插入的位置：");
	scanf("%d",&i);
	int e;
	printf("\n输入要插入的数据: ");
	scanf("%d",&e);
	ListInsert_Sq(list,i,e); 
	printf("\n在第%d个位置插入数据%d后元素序列为:",i,e);
	Displist(list);
	printf("\n输入要删除的位置：");
	scanf("%d",&i);
	printf("\n删除第%d个位置后元素序列为:",i);
	ListDelete_Sq(list,i);
	Displist(list);
    
	 return 0; 
}
