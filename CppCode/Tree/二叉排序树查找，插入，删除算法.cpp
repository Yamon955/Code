#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct{
	int key;
}RecType;
typedef struct BiTNode{
	RecType data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
bool EQ(int a,int b)//判断ab是否相等 
{
	if(a==b) return true;
	else     return false;
}
bool LT(int a,int b)//判断a是否大于b 
{
	if(a<b) return true;
	else    return false;
}
BiTree SearchBST(BiTree T,int key)//在二叉排序树中查找关键字等于key的元素 
{								  //若查找成功，则返回该数据元素结点的指针，否则返回空指针 
	if(!T||EQ(key,T->data.key)) return T;
	else {
		if(LT(key,T->data.key)) return SearchBST(T->lchild,key);
		else   return SearchBST(T->rchild,key);
	} 
}
int SearchBST_(BiTree &T,int key,BiTree f,BiTree &p)
{                            //在二叉排序树中查找关键字等于key的元素
	if(!T){					//若查找成功，则指针p指向该数据元素结点并返回1,否则指针p指向查找路径上访问的最后一个结点并返回0,指针f指向T的双亲,其初始调用值为NULL 
        p=f;                             
		return 0;
	}
	else
		if(EQ(key,T->data.key)){
			p=T;
			return 1;
		}
		else
			if(LT(key,T->data.key)) return SearchBST_(T->lchild,key,T,p);
			else       return SearchBST_(T->rchild,key,T,p);
}
int InsertBST(BiTree &T,RecType e)//当二叉排序树T中不存在关键字等于e.key的元素时，插入e并返回1,否则返回0 
{
	BiTree p,s;
	if(!SearchBST_(T,e.key,NULL,p)){
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!T) T=s;
		else
			if(LT(e.key,p->data.key)) p->lchild=s;
			else p->rchild=s;
		return 1;
	} 
	else return 0;//树中已有关键字相同的结点，不再插入 
}
void mid(BiTree T)//中序遍历二叉排序树 
{
	if(T!=NULL){
		mid(T->lchild);
		cout<<T->data.key<<" ";
		mid(T->rchild);	
    }
 } 
void CreateBST(BiTree &T,RecType a[],int n)//创建二叉排序树 
{
	T=NULL;//初始为空树 
	int i=0;
	while(i<n){
		InsertBST(T,a[i]);
		i++;
	}
 } 
void Delete1(BiTree &p)//从二叉排序树中删除结点p(法一:用p的左子树中最右边的结点s替代p) 
{
	BiTree q,s;
	if(!p->rchild){   // p的右子树空则只需重接它的左子树(待删结点是叶子也走此分支)
		q=p;
		p=p->lchild;
		free(q);
	}
	else
		if(!p->lchild){ // p的左子树空，只需重接它的右子树 
			q=p;
			p=p->rchild;
			free(q);
		}
		else{   //p的左右子树均不空 
			q=p;
			s=p->lchild;
			while(s->rchild){  //找到p的左子树中最右边的结点
				q=s;
				s=s->rchild;
			} 
			p->data=s->data;
			if(q!=p) q->rchild=s->lchild;
			else     q->lchild=s->lchild;
			free(s);
		}
}
void Delete2(BiTree &p)//从二叉排序树中删除结点p(法一:用p的右子树中最左边的结点s替代p) 
{
	BiTree q,s;
	if(!p->rchild){   // p的右子树空则只需重接它的左子树(待删结点是叶子也走此分支)
		q=p;
		p=p->lchild;
		free(q);
	}
	else
		if(!p->lchild){ // p的左子树空，只需重接它的右子树 
			q=p;
			p=p->rchild;
			free(q);
		}
		else{   //p的左右子树均不空 
			q=p;
			s=p->rchild;
			while(s->lchild){  //找到p的右子树中最左边的结点 
				q=s;
				s=s->lchild;
			} 
			p->data=s->data;
			if(q!=p) q->lchild=s->rchild;
			else     q->rchild=s->rchild;
			free(s);
		}
}
int DeleteBST(BiTree &T,int key)// 若二叉排序树T中存在关键字等于key的数据元素则删除该数据元素结点,并返回1否则返回0 
{
	if(!T) return 0;
	else{
		if(EQ(key,T->data.key)) Delete2(T);
		else
			if(LT(key,T->data.key)) DeleteBST(T->lchild,key);
			else    DeleteBST(T->rchild,key);
		return 1;
	}
 } 
int main()
{
	BiTree T;
	RecType a[100];
	int n;
	cout<<"输入被查找表中所有元素的个数:";
	cin>>n;
	cout<<"输入被查找表中的n个元素的key值:";
	for(int i=0;i<n;i++) {
		cin>>a[i].key;
	}
	CreateBST(T,a,n);
	cout<<"中序遍历二叉排序树得到的有序序列为:"; 
	mid(T);
	int key;
	cout<<endl<<"输入要查找的关键字key的值:";
	cin>>key;
	cout<<"查找key="<<key<<"的结果:"; 
	if(SearchBST(T,key)) cout<<"查找成功."<<endl;
	else {
		cout<<"查找失败."<<endl;
		RecType c;
		c.key=key;
		InsertBST(T,c);
		cout<<"将此查找失败的key值插入到二叉排序树中,此时二叉排序树中序序列为:";
		mid(T);
	}
	int d;
	cout<<endl<<"输入要删除的元素的key值:";
	cin>>d;
	DeleteBST(T,d);
	cout<<"删除后此二叉排序树中序遍历序列为:";
	mid(T); 
	return 0; 
}



