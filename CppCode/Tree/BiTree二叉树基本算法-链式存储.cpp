#include<iostream>                    //��������ABC##DE#G##F###(�������) 
#include<malloc.h> 
#include<cstdio> 
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode, *BiTree;
void CreateBiTree_1(BiTree &T)//�������������������н���ֵ 
{						    //���ڲ��������������������ַ���#������ȫ ��
                            //��һ���������Ϊ�����������洢�����Ǵ洢ʱ��ȫ�õ������ַ������д洢 
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;//����
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T) exit(-1);//������Ƿ�����ɹ� 
		T->data=ch;     //���ɸ��ڵ� 
		CreateBiTree_1(T->lchild);//���������� 
		CreateBiTree_1(T->rchild);//���������� 
	} 
 } 
/*void CreateBiTree_2(BiTree &T)//�������������������н���ֵ
{
	char ch;
	cin>>ch;
	T=(BiTree)malloc(sizeof(BiTNode));
	if(!T) exit(-1);//������Ƿ�����ɹ�  		CreateBiTree_2(T->lchild);//����������
	T->data=ch;     //���ɸ��ڵ� 
	CreateBiTree_2(T->rchild);//����������  
 } 
 void CreateBiTree_3(BiTree &T)//���������������������н���ֵ
{
	char ch;
	cin>>ch;

	T=(BiTree)malloc(sizeof(BiTNode));
	if(!T) exit(-1);//������Ƿ�����ɹ�  
	CreateBiTree_3(T->lchild);//����������
	CreateBiTree_3(T->rchild);//���������� 
	T->data=ch;     //���ɸ��ڵ� 
 } 
 */
void PreOrderTraverse(BiTree T)//������������� 
{
	if(T!=NULL){
		cout<<T->data<<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)////������������� 
{
	if(T!=NULL){
		InOrderTraverse(T->lchild);
		cout<<T->data<<" ";
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)//������������� 
{
	if(T!=NULL){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<" ";
	}
}
void swap(BiTNode *&T)//�������Һ��� 
{
	if(T!=NULL){
		if(T->lchild!=NULL&&T->rchild!=NULL){
			BiTNode *p=T->lchild;
			T->lchild=T->rchild;
			T->rchild=p;
		}
		swap(T->lchild);
		swap(T->rchild);
	}
 } 
void DestroyBiTree(BiTree &b)//���ٶ������ݹ��㷨 
{							 //f(b)=�����κ����飬��b=NULLʱ 
	if(b!=NULL){             //f(b)=f(b->lchild);f(b->rchild);free(b) ��b!=NULLʱ 
		DestroyBiTree(b->lchild);
		DestroyBiTree(b->rchild);
		free(b);
	}
	else return;
 } 
int bt_height(BiTNode *T)//��������߶�(���)�ݹ��㷨1 
{						 //��T=NULLʱ��f(T)=0;���������f(b)=max(f(b->lchild),f(b->rchild))+1 
	if(T==NULL) return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL) return 1;
		else return 1+max(bt_height(T->lchild),bt_height(T->rchild));
	}
 } 
int BTheight(BiTNode *b)//��������߶ȵݹ��㷨2 
{
	int lh,rh;
	if(b==NULL) return 0;//�����߶�Ϊ0 
	else{
		lh=BTheight(b->lchild);//���������ĸ߶� 
		rh=BTheight(b->rchild);//���������ĸ߶� 
	}
	return lh>rh?(lh+1):(rh+1); 
}
int width_max(BiTree T)//������� 
{
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		int temp=0,maxw=0;//temp��ʱ��¼ÿ��Ŀ�ȣ�maxw��¼����� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
			temp++;//ͬ��������1 
			if(p->lchild!=NULL) Q[++rear]=p->lchild;//����Ů��� 
			if(p->rchild!=NULL) Q[++rear]=p->rchild;//����Ů��� 
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
				if(temp>maxw) maxw=temp;
				temp=0;
			}
		}
	   return  maxw;	
	}
 } 
int NodeCount(BiTNode *b)//��������������㷨
{						 //��b=NULLʱ��f(b)=0;���������f(b)=f(b->lchild)+f(b->rchild)+1 
	int lnum,rnum;
	if(b==NULL) return 0;//��������0
	else{
		lnum=NodeCount(b->lchild);//�������������� 
		rnum=NodeCount(b->rchild);//�������������� 
	} 
	return (lnum+rnum+1); 
 } 
 int leafCount(BiTree T)//��Ҷ�ӽ����� 
 {
 	if(T==NULL) return 0;
 	else if(T->lchild==NULL&&T->rchild==NULL) return 1;
 	else return (leafCount(T->lchild)+leafCount(T->rchild));
 }
int DegreeTwo_count2(BiTree T)//�ݹ����Ϊ2�Ľ����� 
 {
 	int lnum,rnum,n;
 	if(T==NULL) return 0;
 	else {
 		if(T->lchild!=NULL&&T->rchild!=NULL) n=1;
 		else n=0;
 		lnum=DegreeTwo_count2(T->lchild);
 		rnum=DegreeTwo_count2(T->rchild);
	 }
	return (lnum+rnum+n);
}
   int DegreeTwo_count(BiTree T)//��α������Ϊ2�Ľ����� 
{
	int num=0;//ͳ�ƶ�Ϊ1�Ľ����� 
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
			if(p->lchild==NULL&&p->rchild!=NULL){
				Q[++rear]=p->rchild;
				//num++;//ֻ���Һ��ӣ���Ϊ1���Һ�����ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild==NULL){
				Q[++rear]=p->lchild;
				//num++;//ֻ�����ӣ���Ϊ1��������ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild!=NULL){
				Q[++rear]=p->lchild;//���Һ��Ӷ��У���Ϊ2�����Һ������ 
				Q[++rear]=p->rchild;
				num++;
			}
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
			}
		}
	   return  num;	
	}
 } 
 int DegreeOne_count(BiTree T)//��α������Ϊ1�Ľ����� 
{
	int num=0;//ͳ�ƶ�Ϊ1�Ľ����� 
	if(T==NULL) return 0;
	else{
		BiTree Q[100],p;
		int front=1,rear=1,last=1;//front��ͷָ�룬rear��βָ�룬lastΪͬ�����ұߵĽ���ڶ����е�λ�� 
		Q[rear]=T;//���ڵ���� 
		while(front<=last){
			p=Q[front++];
			if(p->lchild==NULL&&p->rchild!=NULL){
				Q[++rear]=p->rchild;
				num++;//ֻ���Һ��ӣ���Ϊ1���Һ�����ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild==NULL){
				Q[++rear]=p->lchild;
				num++;//ֻ�����ӣ���Ϊ1��������ӣ�num++ 
			}
			else if(p->lchild!=NULL&&p->rchild!=NULL){
				Q[++rear]=p->lchild;//���Һ��Ӷ��У���Ϊ2�����Һ������ 
				Q[++rear]=p->rchild;
			}
			if(front>last){//һ����� 
				last=rear;//lastָ���²�����Ԫ�� 
			}
		}
	   return  num;	
	}
 } 
int sum(BiTNode *b)//�����н��ֵ�ĺ͵ݹ��㷨 
{				   //��b=NULLʱ��f(b)=0;�������ʱ��f(b)=b->data+sum(b->lchild)+sum(b->rchild) 
	if(b==NULL) return 0;
	else return(b->data+sum(b->lchild)+sum(b->rchild));
}
void Route(BiTree T,char *path,int pathlen)//���Ҷ�ӽڵ㵽���ڵ��·�� 
{
	if(T==NULL) return ;
	if(T->lchild==NULL&&T->rchild==NULL){
		cout<<endl<<T->data<<" ";
		for(int i=pathlen-1;i>=0;i--) cout<<path[i]<<" ";
	}
	else{
		path[pathlen++]=T->data;
		Route(T->lchild,path,pathlen);
		Route(T->rchild,path,pathlen);
	}
 } 
int main()
{
	BiTree T;
	cout<<"������������������ֵ:";
	CreateBiTree_1(T);
	cout<<"�����������:";
	PreOrderTraverse(T);
	cout<<endl<<"�����������:";
	InOrderTraverse(T);
	cout<<endl<<"�����������:";
	PostOrderTraverse(T);
	cout<<endl<<"�˶������߶�:"<<BTheight(T);
	cout<<endl<<"�˶������������:"<<NodeCount(T);
	cout<<endl<<"�˶�����Ҷ�ӽڵ����:"<<leafCount(T);
	cout<<endl<<"�����:"<<width_max(T); 
	cout<<endl<<"��Ϊ1�Ľ�����:"<<DegreeOne_count(T);
	char path[100]; 
	Route(T,path,0); 
	return 0;
	
}

