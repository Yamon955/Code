#include<iostream>
#include<malloc.h>
using namespace std;
#define Max_size 100
#define Incrent_size 10
typedef struct{
	int *r;
	int length;
	int listsize;
}SqList;
void CreateList(SqList &L)
{
	L.r=(int *)malloc(Max_size*sizeof(int));
	L.length=0;
	L.listsize=Max_size;	
} 
void List_Insert(SqList &L,int a)
{
	if(L.length==L.listsize){
		int* newbase=(int *)realloc(L.r,(Max_size+Incrent_size)*sizeof(int));
		L.listsize = Max_size+Incrent_size;
		L.r=newbase;
	}
	L.r[++L.length]=a;
}
void show_List(SqList L)
{
	for(int i=1;i<=L.length;i++){
		cout<<L.r[i]<<" ";
	}
	cout<<endl;
}
bool LT(int a,int b)
{
	if(a<b) return true;
	else    return false;
}
void Insert_sort(SqList &L)
{
	int i,j;
	for(i=2;i<=L.length;i++){
		L.r[0]=L.r[i];
		for( j=i-1;LT(L.r[0],L.r[j]);j--)
			L.r[j+1]=L.r[j];
		L.r[j+1]=L.r[0];
	}
}
int main()
{
	SqList L;
	CreateList(L);
	int a[100],n;
	cout<<"Enter the number of elems:";
	cin>>n;
	cout<<"Enter the elems:";
	for(int i=0;i<n;i++){
		cin>>a[i];
		List_Insert(L,a[i]);
	}
	Insert_sort(L);
	show_List(L);
	return 0;
	
}
