// sList.cpp : Defines the entry point for the console application.
//


#include "malloc.h"
#include<stdio.h> 
// ------ ���Ա�Ķ�̬����˳��洢�ṹ --------
#define LIST_INIT_SIZE 100  // ���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 10    // ���Ա�洢�ռ�ķ�������
typedef int ElemType;	       //Ԫ�ص���������
typedef struct {
  ElemType *elem;            // �洢�ռ��ַ
  int length;                // ��ǰ����
  int listsize;              // ��ǰ����Ĵ洢����
} SqList;

// ------ ���Ա�ľ�̬����˳��洢�ṹ --------
#define MaxSize 100
typedef int ElemType;		//����˳���������Ԫ��Ϊint����
typedef struct
{  
   ElemType data[MaxSize];	//���˳����Ԫ��
   int length;			//˳����ʵ�ʳ���
} SSqList;			//˳�������


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;   // Statusֵ�Ǻ������״̬���룬��OK��

////////////////////////////////////////////////////////////////////////
Status InitList_Sq(SqList  &L) 
{  
    // �㷨2.3  ����һ���յ����Ա�L��
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem)   return  ERROR;        	// �洢����ʧ��
    L.length = 0;                 			 // �ձ���Ϊ0
    L.listsize = LIST_INIT_SIZE;  		 // ��ʼ�洢����
    return OK;
}



Status DestroyList(SqList &L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
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
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
  // �����������e����L�е�i������Ԫ�ص�ֵ
    if(i < 1 || i > L.length)
        return ERROR;
    e = *(L.elem + i - 1);
    return OK;
}


int LocateElem(SqList L, ElemType e)
{
    ElemType *p;
    int i = 1;        // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L.elem;       // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
    while(i <= L.length && (*p++ != e))
        ++i;
    if(i <= L.length)
        return i;
    else
        return 0;
}


Status ListInsert_Sq(SqList &L, int i, ElemType e)
{   // �㷨2.4��  i�ĺϷ�ֵΪ1��i��L.Length+1
    ElemType *p;
    if(i < 1 || i > L.length + 1)
        return ERROR;  		   // iֵ���Ϸ�
    if(L.length >= L.listsize) {    // ��ǰ�洢�ռ���������������
        ElemType *newbase = (ElemType *)realloc(L.elem,
                (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if(!newbase)
            return ERROR;                 // �洢����ʧ��
        L.elem = newbase;                  // �»�ַ
        L.listsize += LIST_INCREMENT;      // ���Ӵ洢����
    } 
    ElemType *q = &(L.elem[i - 1]);       // qΪ����λ��
    for(p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;		         // ����λ�ü�֮���Ԫ������
    *q = e;       			// ����e
    ++L.length;   			// ����1
    return OK;
} 




Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // �㷨2.5�� i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
    ElemType   *p, *q;
    if(i < 1 || i > L.length)
        return ERROR;             // iֵ���Ϸ�
    p = &(L.elem[i - 1]);          // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                       // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1;     // ��βԪ�ص�λ��
    for(++p; p <= q; ++p)
        *(p - 1) = *p;        // ��ɾ��Ԫ��֮���Ԫ������
    --L.length;               // ����1
    return OK;
}

////////////////////////////////////////////////////////////////

void dispList(SqList L)
{
    for(int i = 1; i <= L.length; i++)
        printf("%d ", L.elem[i - 1]);
}

void swap(ElemType &x, ElemType &y)	//����x��y
{  ElemType tmp=x;
   x=y;  y=tmp;
}
void SwapMaxMin(SqList &L)	//����L�����ֵԪ������СֵԪ��
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
{  //�����Ա���ɾ���Ե�i��Ԫ�ؿ�ʼ��k��Ԫ��
   int j;
   if (i<1 || k<1 || i+k-1>L.length)
      return 0;			//�ж�i��k�Ƿ�Ϸ�
   for (j=i+k-1;j<L.length;j++)   	//��Ԫ��ǰ��k��λ��
      L.elem[j-k]=L.elem[j];
   L.length-=k;			//L�ĳ��ȼ�k
   return 1;
}


void Move(SqList &L)
{  //�����������Ƶ����е�ż��ǰ��
   int i=0,j=L.length-1;
   while (i<j)
   {  while (L.elem[i]%2==1) i++;	//��ǰ�����ż��
      while (L.elem[j]%2==0) j--;	//�Ӻ���ǰ������
      if (i<j)
         swap(L.elem[i],L.elem[j]);	//��������Ԫ��
   }
}


void DeleteMinus(SqList &L)
{  //ɾ����������ֵΪ��������Ԫ��
   int i, k=0;
   for (i=0;i<L.length;i++)
     if (L.elem[i]>=0)	//����Ϊ������Ԫ�ز��뵽L��
     {  L.elem[k]=L.elem[i];
        k++;
     }
   L.length=k;			//����L�ĳ���
}


/*�轫n��n��1����������ŵ�һά����R�С������һ��ʱ��Ϳռ������澡���ܸ�Ч���㷨����R����������ѭ������p��0��p��n����λ�ã�
����R�е���������(X0,X1,��,Xn-1)�任Ϊ(Xp,Xp+1,��,Xn-1,X0,X1,��,Xp-1)��Ҫ��
��1�������㷨�Ļ������˼�롣
��2���������˼�룬����C��C++��Java���������㷨���ؼ�֮������ע�͡�
��3��˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
*/
void reverse(int R[],int m,int n)	  //��R[m..n]����
{
	int i;
	int tmp;
	for (i=0;i<(n-m+1)/2;i++)
	{
		tmp=R[m+i];		  //��R[m+i]��R[n-i]���н���
		R[m+i]=R[n-i];
		R[n-i]=tmp;
	}
}

int ListReverse(int R[],int n,int p)	    //ѭ������
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
    printf("\n\n���������д洢���ݵĸ�����");
    scanf("%d",&n);
    int	 A[n];
	SqList List;
    InitList_Sq(List);

    printf("\n\n������������е����ݣ�");
    for(i = 1, j = 0; i <= n; i++, j++){
    	scanf("%d",&A[j]);
    	ListInsert_Sq(List, i, A[j]);
	}
    printf("\n\n����֮ǰ��Ԫ������Ϊ��");
    dispList(List);
    printf("\n\n����Ҫ��������ݣ�");
    scanf("%d",&e);
    printf("\n\n����Ҫ�����λ�ã�");//����λ�� 
    scanf("%d",&i);//����λ��
    ListInsert_Sq(List, i, e);
    printf("\n\n������Ԫ������Ϊ��");
    dispList(List);

    printf("\n\n����Ҫɾ�����ݵ�λ��:");   //ɾ��λ��
    scanf("%d",&i);
    printf("\n\nɾ�����Ԫ������Ϊ:");
    ListDelete_Sq(List, i, e);
    dispList(List);

	printf("\n\n");
}
//////////////////////////////////////////////////////////////
