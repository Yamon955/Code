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
bool EQ(int a,int b)//�ж�ab�Ƿ���� 
{
	if(a==b) return true;
	else     return false;
}
bool LT(int a,int b)//�ж�a�Ƿ����b 
{
	if(a<b) return true;
	else    return false;
}
BiTree SearchBST(BiTree T,int key)//�ڶ����������в��ҹؼ��ֵ���key��Ԫ�� 
{								  //�����ҳɹ����򷵻ظ�����Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ�� 
	if(!T||EQ(key,T->data.key)) return T;
	else {
		if(LT(key,T->data.key)) return SearchBST(T->lchild,key);
		else   return SearchBST(T->rchild,key);
	} 
}
int SearchBST_(BiTree &T,int key,BiTree f,BiTree &p)
{                            //�ڶ����������в��ҹؼ��ֵ���key��Ԫ��
	if(!T){					//�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㲢����1,����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����0,ָ��fָ��T��˫��,���ʼ����ֵΪNULL 
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
int InsertBST(BiTree &T,RecType e)//������������T�в����ڹؼ��ֵ���e.key��Ԫ��ʱ������e������1,���򷵻�0 
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
	else return 0;//�������йؼ�����ͬ�Ľ�㣬���ٲ��� 
}
void mid(BiTree T)//����������������� 
{
	if(T!=NULL){
		mid(T->lchild);
		cout<<T->data.key<<" ";
		mid(T->rchild);	
    }
 } 
void CreateBST(BiTree &T,RecType a[],int n)//�������������� 
{
	T=NULL;//��ʼΪ���� 
	int i=0;
	while(i<n){
		InsertBST(T,a[i]);
		i++;
	}
 } 
void Delete1(BiTree &p)//�Ӷ�����������ɾ�����p(��һ:��p�������������ұߵĽ��s���p) 
{
	BiTree q,s;
	if(!p->rchild){   // p������������ֻ���ؽ�����������(��ɾ�����Ҷ��Ҳ�ߴ˷�֧)
		q=p;
		p=p->lchild;
		free(q);
	}
	else
		if(!p->lchild){ // p���������գ�ֻ���ؽ����������� 
			q=p;
			p=p->rchild;
			free(q);
		}
		else{   //p���������������� 
			q=p;
			s=p->lchild;
			while(s->rchild){  //�ҵ�p�������������ұߵĽ��
				q=s;
				s=s->rchild;
			} 
			p->data=s->data;
			if(q!=p) q->rchild=s->lchild;
			else     q->lchild=s->lchild;
			free(s);
		}
}
void Delete2(BiTree &p)//�Ӷ�����������ɾ�����p(��һ:��p��������������ߵĽ��s���p) 
{
	BiTree q,s;
	if(!p->rchild){   // p������������ֻ���ؽ�����������(��ɾ�����Ҷ��Ҳ�ߴ˷�֧)
		q=p;
		p=p->lchild;
		free(q);
	}
	else
		if(!p->lchild){ // p���������գ�ֻ���ؽ����������� 
			q=p;
			p=p->rchild;
			free(q);
		}
		else{   //p���������������� 
			q=p;
			s=p->rchild;
			while(s->lchild){  //�ҵ�p��������������ߵĽ�� 
				q=s;
				s=s->lchild;
			} 
			p->data=s->data;
			if(q!=p) q->lchild=s->rchild;
			else     q->rchild=s->rchild;
			free(s);
		}
}
int DeleteBST(BiTree &T,int key)// ������������T�д��ڹؼ��ֵ���key������Ԫ����ɾ��������Ԫ�ؽ��,������1���򷵻�0 
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
	cout<<"���뱻���ұ�������Ԫ�صĸ���:";
	cin>>n;
	cout<<"���뱻���ұ��е�n��Ԫ�ص�keyֵ:";
	for(int i=0;i<n;i++) {
		cin>>a[i].key;
	}
	CreateBST(T,a,n);
	cout<<"������������������õ�����������Ϊ:"; 
	mid(T);
	int key;
	cout<<endl<<"����Ҫ���ҵĹؼ���key��ֵ:";
	cin>>key;
	cout<<"����key="<<key<<"�Ľ��:"; 
	if(SearchBST(T,key)) cout<<"���ҳɹ�."<<endl;
	else {
		cout<<"����ʧ��."<<endl;
		RecType c;
		c.key=key;
		InsertBST(T,c);
		cout<<"���˲���ʧ�ܵ�keyֵ���뵽������������,��ʱ������������������Ϊ:";
		mid(T);
	}
	int d;
	cout<<endl<<"����Ҫɾ����Ԫ�ص�keyֵ:";
	cin>>d;
	DeleteBST(T,d);
	cout<<"ɾ����˶��������������������Ϊ:";
	mid(T); 
	return 0; 
}



