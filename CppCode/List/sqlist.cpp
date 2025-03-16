// sList.cpp : Defines the entry point for the console application.
//


#include "malloc.h"
#include<stdio.h> 
// ------ 线性表的动态分配顺序存储结构 --------
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LIST_INCREMENT 10    // 线性表存储空间的分配增量
typedef int ElemType;	       //元素的数据类型
typedef struct {
  ElemType *elem;            // 存储空间基址
  int length;                // 当前长度
  int listsize;              // 当前分配的存储容量
} SqList;

// ------ 线性表的静态分配顺序存储结构 --------
#define MaxSize 100
typedef int ElemType;		//假设顺序表中所有元素为int类型
typedef struct
{  
   ElemType data[MaxSize];	//存放顺序表的元素
   int length;			//顺序表的实际长度
} SSqList;			//顺序表类型


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;   // Status值是函数结果状态代码，如OK等

////////////////////////////////////////////////////////////////////////
Status InitList_Sq(SqList  &L) 
{  
    // 算法2.3  构造一个空的线性表L。
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem)   return  ERROR;        	// 存储分配失败
    L.length = 0;                 			 // 空表长度为0
    L.listsize = LIST_INIT_SIZE;  		 // 初始存储容量
    return OK;
}



Status DestroyList(SqList &L)
{ // 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}


int GetLength(SqList L)
{
	return L.length;
}


Status GetElem(SqList L, int i, ElemType &e)
{ // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
  // 操作结果：用e返回L中第i个数据元素的值
    if(i < 1 || i > L.length)
        return ERROR;
    e = *(L.elem + i - 1);
    return OK;
}


int LocateElem(SqList L, ElemType e)
{
    ElemType *p;
    int i = 1;        // i的初值为第1个元素的位序
    p = L.elem;       // p的初值为第1个元素的存储位置
    while(i <= L.length && (*p++ != e))
        ++i;
    if(i <= L.length)
        return i;
    else
        return 0;
}


Status ListInsert_Sq(SqList &L, int i, ElemType e)
{   // 算法2.4；  i的合法值为1≤i≤L.Length+1
    ElemType *p;
    if(i < 1 || i > L.length + 1)
        return ERROR;  		   // i值不合法
    if(L.length >= L.listsize) {    // 当前存储空间已满，增加容量
        ElemType *newbase = (ElemType *)realloc(L.elem,
                (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if(!newbase)
            return ERROR;                 // 存储分配失败
        L.elem = newbase;                  // 新基址
        L.listsize += LIST_INCREMENT;      // 增加存储容量
    } 
    ElemType *q = &(L.elem[i - 1]);       // q为插入位置
    for(p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;		         // 插入位置及之后的元素右移
    *q = e;       			// 插入e
    ++L.length;   			// 表长增1
    return OK;
} 




Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // 算法2.5； i的合法值为1≤i≤ListLength_Sq(L)。
    ElemType   *p, *q;
    if(i < 1 || i > L.length)
        return ERROR;             // i值不合法
    p = &(L.elem[i - 1]);          // p为被删除元素的位置
    e = *p;                       // 被删除元素的值赋给e
    q = L.elem + L.length - 1;     // 表尾元素的位置
    for(++p; p <= q; ++p)
        *(p - 1) = *p;        // 被删除元素之后的元素左移
    --L.length;               // 表长减1
    return OK;
}

////////////////////////////////////////////////////////////////

void dispList(SqList L)
{
    for(int i = 1; i <= L.length; i++)
        printf("%d ", L.elem[i - 1]);
}

void swap(ElemType &x, ElemType &y)	//交换x和y
{  ElemType tmp=x;
   x=y;  y=tmp;
}
void SwapMaxMin(SqList &L)	//交换L中最大值元素与最小值元素
{  int i,maxi,mini;
   maxi=mini=0;
   for (i=1;i<L.length;i++)
     if (L.elem[i]>L.elem[maxi])
         maxi=i;
     else if (L.elem[i]<L.elem[mini])
         mini=i;
   swap(L.elem[maxi],L.elem[mini]);
}


int Deletek(SqList &L,int i,int k)
{  //从线性表中删除自第i个元素开始的k个元素
   int j;
   if (i<1 || k<1 || i+k-1>L.length)
      return 0;			//判断i和k是否合法
   for (j=i+k-1;j<L.length;j++)   	//将元素前移k个位置
      L.elem[j-k]=L.elem[j];
   L.length-=k;			//L的长度减k
   return 1;
}


void Move(SqList &L)
{  //将所有奇数移到所有的偶数前边
   int i=0,j=L.length-1;
   while (i<j)
   {  while (L.elem[i]%2==1) i++;	//从前向后找偶数
      while (L.elem[j]%2==0) j--;	//从后向前找奇数
      if (i<j)
         swap(L.elem[i],L.elem[j]);	//交换这两元素
   }
}


void DeleteMinus(SqList &L)
{  //删除其中所有值为负整数的元素
   int i, k=0;
   for (i=0;i<L.length;i++)
     if (L.elem[i]>=0)	//将不为负数的元素插入到L中
     {  L.elem[k]=L.elem[i];
        k++;
     }
   L.length=k;			//重置L的长度
}


/*设将n（n＞1）个整数存放到一维数组R中。试设计一个时间和空间两方面尽可能高效的算法，将R中整数序列循环左移p（0＜p＜n）个位置，
即将R中的数据序列(X0,X1,…,Xn-1)变换为(Xp,Xp+1,…,Xn-1,X0,X1,…,Xp-1)，要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
*/
void reverse(int R[],int m,int n)	  //将R[m..n]逆置
{
	int i;
	int tmp;
	for (i=0;i<(n-m+1)/2;i++)
	{
		tmp=R[m+i];		  //将R[m+i]与R[n-i]进行交换
		R[m+i]=R[n-i];
		R[n-i]=tmp;
	}
}

int ListReverse(int R[],int n,int p)	    //循环左移
{
	if (p<=0 || p>=n)
		return 0;
	else
	{
		reverse(R,0,p-1);
		reverse(R,p,n-1);
		reverse(R,0,n-1);
		return 1;
	}
}

/////////////////////////////////////////////////////////
int  main()
{
    
    int i, j,n, e;
    printf("\n\n输入链表中存储数据的个数：");
    scanf("%d",&n);
    int	 A[n];
	SqList List;
    InitList_Sq(List);

    printf("\n\n输入存入链表中的数据：");
    for(i = 1, j = 0; i <= n; i++, j++){
    	scanf("%d",&A[j]);
    	ListInsert_Sq(List, i, A[j]);
	}
    printf("\n\n插入之前的元素序列为：");
    dispList(List);
    printf("\n\n输入要插入的数据：");
    scanf("%d",&e);
    printf("\n\n输入要插入的位置：");//插入位置 
    scanf("%d",&i);//插入位置
    ListInsert_Sq(List, i, e);
    printf("\n\n插入后的元素序列为：");
    dispList(List);

    printf("\n\n输入要删除数据的位置:");   //删除位置
    scanf("%d",&i);
    printf("\n\n删除后的元素序列为:");
    ListDelete_Sq(List, i, e);
    dispList(List);

	printf("\n\n");
}
//////////////////////////////////////////////////////////////
