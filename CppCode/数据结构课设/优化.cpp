#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
char s[1000000],w[5000][100];//����w[]����������е��� 
clockid_t start,stop;//ʱ��
int key;//������ƿ��� 
int word_count;//ͳ�Ƶ��ʵ����� 
typedef struct{
	char s[100];//��ŵ��� 
	int number;//���ִ��� 
}Word; //���ʽṹ�� 
Word word[5000];//��Ų��ظ��ĵ��� 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort_Word(Word w[])//�Խṹ������w[]������ַ��������ֵ�������,�Ա��ڰ����ֵ������ 
{
	Word w1[word_count];
	int num=1,j;//���� 
	w1[0]=w[0];
	for(int i=1;i<word_count;i++){
		for(j=0;j<num;j++){
			if(strcmp(w[i].s,w1[j].s)<0){
				for(int m=num;m>j;m--){
					w1[m]=w1[m-1];
				}
				w1[j]=w[i];
				num++;
				break;
			}
		}
		if(j==num){
			w1[j]=w[i];
			num++;
		}
	}
	for(int i=0;i<word_count;i++) w[i]=w1[i];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////˳��� 
typedef struct{
	Word *elem;
	int len;
}SqList;//˳��� 
SqList L;
void Init_SqList(SqList &L)//����һ��˳��������ٿռ� 
{
	L.elem=(Word *)malloc(5000*sizeof(Word));
	L.len=0;
}
void SqList_Insert(SqList &L,Word a)//���뵽˳����� 
{
	if(L.len==0){
		strcpy(L.elem[L.len].s,a.s);
		L.elem[L.len].number=a.number;
		L.len++;
	}
	else {
		int i;
		for(i=0;i<L.len;i++){
			if(strcmp(L.elem[i].s,a.s)>0){//���������ֵ���С����ǰ�������۰���� 
				for(int j=L.len;j>i;j--){
					strcpy(L.elem[j].s,L.elem[j-1].s);
					L.elem[j].number=L.elem[j-1].number;
				}
				strcpy(L.elem[i].s,a.s);
				L.elem[i].number=a.number;
				L.len++;
				break;
			}
		}
		if(i==L.len) {
			strcpy(L.elem[i].s,a.s);
			L.elem[i].number=a.number;
			L.len++;
		}
	}
}
void print_SqList1(SqList L)//˳���˳����Ҵ�Ƶͳ�� 
{
	
	/*for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}*/
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile1.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<L.len;i++)
		fprintf(fp,"%s     %d\n",L.elem[i].s,L.elem[i].number);

	fclose(fp);
}
void print_SqList2(SqList L)//˳����۰���Ҵ�Ƶͳ��
{
	
	/*for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}*/
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile3.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<L.len;i++)
		fprintf(fp,"%s     %d\n",L.elem[i].s,L.elem[i].number);

	fclose(fp);
}
void SqSearch_SqList(SqList L,char a[])//����˳����˳����� 
{
	int i;
	start = clock();        /*  ��ʼ��ʱ  */
	for(int j=0;j<=100000;j++) //���Ҷ�� 
	for(i=0;i<L.len;i++){
		if(strcmp(L.elem[i].s,a)==0){//�ҵ����ҵĵ��� 
			break;
		}
	}
	stop = clock();     /*  ֹͣ��ʱ  */
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(i==L.len){
		cout<<"����ʧ��."<<endl;
	}
	else{
		printf("�˵��ʵĴ�ƵΪ: %d\n",L.elem[i].number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: %.1f\n",(L.len+1.0)/2);
	}
} 
float get_aveSearchlegth_HalfSearh(SqList L,Word w[])//���ƽ�����ҳ��� 
{
	int sum=0;//�ܵĲ��Ҵ��� 
	for(int i=0;i<word_count;i++){ //��������ÿ�����ʵĲ��Ҵ��� 
		int l=0,r=L.len-1,n=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(strcmp(L.elem[mid].s,w[i].s)==0){//�ҵ����ҵĵ��� 
			 	sum+=n; //�ҵ��˵��ʺ󽫴˵��ʵĲ��Ҵ����ӵ�sum�� 
				break;
			}	
			else if(strcmp(L.elem[mid].s,w[i].s)>0) {
				n++;//���Ҵ�����һ 
				r=mid-1;
			}
			else if(strcmp(L.elem[mid].s,w[i].s)<0){
				n++;//���Ҵ�����һ 
			 	l=mid+1;
		 	} 
		}
	}
	return (sum*1.0)/word_count;
}
void HalfSearch_SqList(SqList L,char a[])//����˳�����۰���� 
{
	int mid,l,r;
	start = clock();
	for(int j=0;j<=100000;j++){
		l=0,r=L.len-1;
		while(l<=r){
			mid=(l+r)/2;
			if(strcmp(L.elem[mid].s,a)==0)//�ҵ����ҵĵ��� 
				break;	
			else if(strcmp(L.elem[mid].s,a)>0) r=mid-1;
			else if(strcmp(L.elem[mid].s,a)<0) l=mid+1;
		}
	}
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(l>r) cout<<"����ʧ��."<<endl;
	else{
		printf("�˵��ʵĴ�ƵΪ: %d\n",L.elem[mid].number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: %.1f\n",get_aveSearchlegth_HalfSearh(L,word)); 
	}
	
 } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////���� 
typedef struct Lnode{
	Word data;
	struct Lnode *next;
}Lnode,*Linklist;
Linklist L2;
void Init_Linklist(Linklist &L)//��ʼ������ 
{ 
    L = (Linklist)malloc(sizeof(Lnode)); 
    L->next = NULL; 		// ָ����Ϊ��
}
void Linklist_Insert(Linklist &L,Word a)//������� 
 {
 	Lnode *p=L;
 	while(p->next){
 		p=p->next;
	 }
	 Lnode *s=(Linklist)malloc(sizeof(Lnode));
	 s->data=a;
	 s->next=p->next;
	 p->next=s;
 }
 int print_Linklist(Linklist L)//�����˳����ҵĴ�Ƶͳ�� 
{
	Word w1[word_count]; 
	int n=0;
	Lnode *p=L->next;
	while(p){
		w1[n++]=p->data;
		p=p->next;
	}
	sort_Word(w1);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile2.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w1[i].s,w1[i].number);

	fclose(fp);
}
float get_aveSearchlength_Linklist(Linklist L,Word w[])
{
	int sum=0;//�ܵĲ��Ҵ��� 
	for(int i=0;i<word_count;i++){//��������ÿ�����ʵĲ��Ҵ��� 
		Lnode *p=L->next;
		int n=1; 
		while(p){
			if(strcmp(p->data.s,w[i].s)==0){
				sum+=n;//�ҵ��˵��ʺ󽫴˵��ʵĲ��Ҵ����ӵ�sum�� 
				break;
			}
			else {
				n++;//���Ҵ�����һ 
				p=p->next;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void SqSearch_Linklist(Linklist L,char a[])//����������˳����� 
{
	Lnode* p;
	start = clock();
	for(int j=0;j<=100000;j++){
		p=L->next;
		while(p){
			if(strcmp(p->data.s,a)==0) break;
			else p=p->next;
		}
	}

	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(!p) cout<<"����ʧ��."<<endl;
	else{
		printf("�˵��ʵĴ�ƵΪ: %d\n",p->data.number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: %.1f\n", get_aveSearchlength_Linklist(L2,word)); 
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////����������
typedef struct BiTNode{
	Word data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
BiTree T;
int SearchBST_(BiTree &T,Word a,BiTree f,BiTree &p)
{                            //�ڶ����������в��ҹؼ��ֵ���a��Ԫ��
	if(!T){					//�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㲢����1,����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����0,ָ��fָ��T��˫��,���ʼ����ֵΪNULL 
        p=f;                             
		return 0;
	}
	else
		if(strcmp(T->data.s,a.s)==0){//�ж��Ƿ����ظ����ʣ�û��Ҫ����Ϊ�����Ѿ�ɸѡ����������ظ����� 
			p=T;
			return 1;
		}
		else
			if(strcmp(T->data.s,a.s)>0) return SearchBST_(T->lchild,a,T,p);
			else       return SearchBST_(T->rchild,a,T,p);
}
BiTree Search_BiTree(BiTree T,char a[])//�ڶ����������в���
								       //�����ҳɹ����򷵻ظ�����Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
{
	if(T == NULL) return T; 
	if(strcmp(T->data.s,a)==0) return T;
	else if(strcmp(T->data.s,a)>0) Search_BiTree(T->lchild,a);
	else if(strcmp(T->data.s,a)<0) Search_BiTree(T->rchild,a);
}
void InsertBST(BiTree &T,Word e)//���뵽������������ 
{
	BiTree p,s;
	if(!SearchBST_(T,e,NULL,p)){
		s=(BiTree)malloc(sizeof(BiTNode));
		strcpy(s->data.s,e.s);
		s->data.number=e.number;
		s->lchild=s->rchild=NULL;
		if(!T) T=s;
		else
			if(strcmp(p->data.s,e.s)>0) p->lchild=s;
			else if(strcmp(p->data.s,e.s)<0) p->rchild=s;
	} 
}
void CreateBST(BiTree &T,Word a[],int n)//�������������� ,n��ʾ���������� 
{
	T=NULL;//��ʼΪ���� 
	int i=0;
	while(i<n){
		InsertBST(T,a[i]);
		i++;
	}
}
int n=0;
void mid(BiTree T,Word w[])//����������������� 
{
	if(T!=NULL){
		mid(T->lchild,w);
		w[n++]=T->data;//��������õ��ĵ��ʽṹ������w[]��Ϊ���ֵ����źõ� 
		mid(T->rchild,w);	
    }
} 
void print_BiTree(BiTree T,Word w[])//���ڶ������������ҵĴ�Ƶͳ�� 
{
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile4.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
float get_aveSearchlength_BiTree(BiTree T,Word w[])
{
	int sum=0;//�ܵĲ��Ҵ��� 
	for(int i=0;i<word_count;i++){//��������ÿ�����ʵĲ��Ҵ��� 
		BiTree t=T;
		int n=1;
		while(t){
			if(strcmp(t->data.s,w[i].s)==0){
				sum+=n;//�ҵ��˵��ʺ󽫴˵��ʵĲ��Ҵ����ӵ�sum��
				break;
			} 
			else if(strcmp(t->data.s,w[i].s)>0){
				n++;//���Ҵ�����һ 
				t=t->lchild;
			}
			else if(strcmp(t->data.s,w[i].s)<0){
				n++;//���Ҵ�����һ 
				t=t->rchild;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
 
void Search_BiTree2(char *s)//Ϊ�����ʱ������д�Ĳ��Һ��� 
{
			int flag;
			BiTree q;
			start = clock();    /*  ��ʼ��ʱ  */
			for(int i=0;i<=100000;i++){
				flag=0;
				q=Search_BiTree(T,s);
				if(q==NULL){ //����ʧ�� 
					flag=1;
				}
			}
			stop = clock();     /*  ֹͣ��ʱ  */
			double duration = ((double)(stop - start));// / CLK_TCK;
			if(flag==1) cout<<"����ʧ��"<<endl;
			else {
				printf("�˵��ʵĴ�ƵΪ: %d\n",q->data.number);
				printf("���Ҹõ���������ʱ��: %fms\n",duration);
				printf("ƽ�����ҳ���: %.1f\n",get_aveSearchlength_BiTree(T,word));
			}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///��ϣ(ɢ�б�)����----���ڿ��ŵ�ַ���Ĺ�ϣ����----------- 
const int Table_size=6000; //��ϣ�������洢�ĵ����������ʱ������Ӧ���� 
typedef struct{
	Word *elem;//����Ԫ�ش洢����̬�������� 
	int  num;//��ǰ����Ԫ�صĸ��� 
}HashTable; 
HashTable HT;
void Create_HashTable(HashTable &Ta)//������ϣ�� 
{
	Ta.elem=(Word *)malloc(Table_size*sizeof(Word));
	Ta.num=0;
}
int Hash(char *p)//���ϣ��ַ(����������)  ���ַ���������ĸ��ASCLLֵ��ӶԱ�ȡ�� 
{
	int tmp=0;
	for(int i=0;p[i]!='\0';i++){
		tmp+=int(p[i]);
	}
	return tmp%Table_size;//�����ַ����ڹ�ϣ���е�λ���±� 
}
void HashTable_Insert(HashTable &Ta,Word key)
{
	int tmpAdress=Hash(key.s);//�õ���ϣ��ַ 
	while(Ta.elem[tmpAdress].s[0]!='\0'){  //��ͻ   while(Ta.elem[tmpAdress].s!='\0') ????
		tmpAdress=(++tmpAdress)%Table_size;//����̽����ɢ�� �����ͻ 
	}
	strcpy(Ta.elem[tmpAdress].s,key.s);
	Ta.elem[tmpAdress].number=key.number; 
	Ta.num++;
 } 
float get_aveSearchlength_Hash(HashTable Ta,Word w[])
{
	int sum=0;//�ܵĲ��Ҵ��� 
	for(int i=0;i<word_count;i++){//��������ÿ�����ʵĲ��Ҵ��� 
		int tmpAdress=Hash(w[i].s);
		int n=1;
		while(1){
			if(strcmp(Ta.elem[tmpAdress].s,w[i].s)==0){
				sum+=n;//�ҵ��˵��ʺ󽫴˵��ʵĲ��Ҵ����ӵ�sum��
				break;
			} 
			else {
				n++;//���Ҵ�����һ 
				tmpAdress=(++tmpAdress)%Table_size;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void Search_Hash(HashTable Ta,char *q)//��ϣ���� 
{
	int tmpAdress,flag;
	start = clock();       /*  ��ʼ��ʱ  */
	for(int j=0;j<=100000;j++){
		flag=0;
		tmpAdress=Hash(q);
		while(strcmp(Ta.elem[tmpAdress].s,q)!=0){//��ǰλ�ò���q 
			if(Ta.elem[tmpAdress].s[0]=='\0'){
				flag=1;
				break;
			}
			tmpAdress=(++tmpAdress)%Table_size;//�������²��� 
		}
	}
	stop = clock();           /*  ֹͣ��ʱ  */
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==1) cout<<"����ʧ��"<<endl;
	else {
		printf("�˵��ʵĴ�ƵΪ: %d\n",Ta.elem[tmpAdress].number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: %.1f\n",get_aveSearchlength_Hash(HT,word));
	}
}
void print_HashTable(HashTable Ta)//���ŵ�ַ����ϣ���Ҵ�Ƶͳ�� 
{
	Word w[5000];
	int n=0;
	for(int i=0;i<Table_size;i++){
		if(Ta.elem[i].s[0]>='a'&&Ta.elem[i].s[0]<='z'){  //if(Ta.elem[i].s=='\0')???
			w[n++]=Ta.elem[i];
		}
	}
	sort_Word(w);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile5.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///��ϣ(ɢ�б�)����----��������ַ���Ĺ�ϣ����-----------
typedef struct HashNode{
	Word elem;
	struct HashNode *next;
}HashNode,*HashList;
HashList HL[Table_size];
void Create_HashList(HashList &HL)//������ϣ���� 
{
	HL=(HashList)malloc(sizeof(HashNode));
	HL->next=NULL;
} 
void HashList_Insert(HashList HL[],Word a)//���뵽��ϣ���� 
{
	int tmpAdress=Hash(a.s);//��ȡ��ϣ��ַ 
	HashNode *p=HL[tmpAdress];
	while(p->next){
		p=p->next; 
	}
	HashNode *q=(HashList)malloc(sizeof(HashNode));
	q->elem=a;
	q->next=p->next;
	p->next=q;
}
float get_aveSearchlength_HashList(HashList HL[],Word w[])
{
	int sum=0;//�ܵĲ��Ҵ��� 
	for(int i=0;i<word_count;i++){//��������ÿ�����ʵĲ��Ҵ��� 
		int tmpAdress=Hash(w[i].s);
		int n=1;
		HashNode *p=HL[tmpAdress]->next;
		while(p){
			if(strcmp(p->elem.s,w[i].s)==0){
				sum+=n;//�ҵ��˵��ʺ󽫴˵��ʵĲ��Ҵ����ӵ�sum��
				break;
			} 
			else {
				n++;//���Ҵ�����һ 
				p=p->next;
			}
		}
	}
	return (sum*1.0)/word_count; 
 } 
void Search_HashList(HashList HL[],char *s)//��ʽ��ϣ���� 
{
	int tmpAdress,flag;
	HashNode *p;
	start = clock();   /*  ��ʼ��ʱ  */
	for(int i=0;i<=100000;i++){
		tmpAdress=Hash(s);
		flag=0;
		p=HL[tmpAdress]->next;
		while(p){
			if(strcmp(p->elem.s,s)==0){ //���ҵ��˵��� 
				flag=1;
				break;
			}
			else p=p->next;
		}
	}
	stop = clock();     /*  ֹͣ��ʱ  */
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==0) cout<<"����ʧ��"<<endl;
	else {
		printf("�˵��ʵĴ�ƵΪ: %d\n",p->elem.number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: %.1f\n",get_aveSearchlength_HashList(HL,word));
	}
	
} 
void print_HashList(HashList HL[])//����ַ����ϣ���Ҵ�Ƶͳ�� 
{
	Word w[5000];
	int n=0; 
	for(int i=0;i<Table_size;i++){
		HashNode *p=HL[i]->next;
		while(p){
			w[n++]=p->elem;
			p=p->next;
		}
	}
	sort_Word(w);
	FILE *fp;
	if ( (fp = fopen("d:\\Outfile6.txt", "wt")) == NULL )
	{
        puts("Fail to create out file!");
        exit(0);
    }


	fprintf(fp,"��������%d\n",word_count);

	for(int i=0;i<word_count;i++)
		fprintf(fp,"%s     %d\n",w[i].s,w[i].number);

	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/////////////////////////���ý��� 
void Interface1()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"1.�������Ա�Ĳ���"<<endl;
	cout<<"2.���ڶ����������Ĳ���"<<endl;
	cout<<"3.���ڹ�ϣ��Ĳ���"<<endl;
	cout<<"4.�˳�"<<endl;
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;//�������� 
	cout<<endl;
}
void Interface2()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"���������������Ա�Ĳ��ҡ�������"<<endl; 
	cout<<"1.˳�����"<<endl;
	cout<<"2.�۰����"<<endl;
	cout<<"3.������һ��"<<endl;
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
}
void Interface3()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"��������˳����ҡ�������"<<endl;
	cout<<"1.����˳����˳�����"<<endl;
	cout<<"2.���������˳�����"<<endl;
	cout<<"3.������һ��"<<endl;
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
 }
void Interface4() 
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"������������˳����˳����ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key; 
	cout<<endl;
 } 
 void Interface5() 
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"�����������������˳����ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl; 
	cin>>key;
	cout<<endl;
 } 
 void Interface6() 
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"������������˳�����۰���ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl; 
	cin>>key;
	cout<<endl;
 } 
void Interface7()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"�����������ڶ����������Ĳ��ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
}
void Interface8()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"�����������ڹ�ϣ��Ĳ��ҡ�������"<<endl;
	cout<<"1.���ڿ��ŵ�ַ���Ĺ�ϣ����"<<endl;
	cout<<"2.��������ַ���Ĺ�ϣ����"<<endl;
	cout<<"3.������һ��"<<endl;
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
 } 
 void Interface9()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"�����������ڿ��ŵ�ַ���Ĺ�ϣ���ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
}
 void Interface10()
{
	cout<<"/***���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ***/"<<endl;
	cout<<"����������������ַ���Ĺ�ϣ���ҡ�������"<<endl;
	cout<<"1.��Ƶͳ��"<<endl;
	cout<<"2.���ʲ���"<<endl; 
	cout<<"3.������һ��"<<endl; 
	cout<<"�밴��Ӧ���ּ�����ѡ��"<<endl;
	cin>>key;
	cout<<endl;
}
void choose1();
void choose2();
void choose3();
void choose4();
void choose5();
void choose6();
void choose7();
void choose8();
void choose9();
void choose10();

void choose1()
{
	Interface1();
	switch(key){
		case 1:
			choose2();
			break;
		case 2:
			choose3();
			break;
		case 3:
			choose4();
			break;
		case 4:
			exit(0);//ִ���˳����� 
			break;
		default:
			cout<<"�����������"<<endl;
			break;
	}
}
void choose2()
{
	Interface2(); 
	switch(key){
		case 1:
			choose5();
			break;
		case 2:
			choose6(); 
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"�����������"<<endl;
			break;		
	}
}
void choose5()
{
	Interface3();
	switch(key){
		case 1:
			choose7();
			break;
		case 2:
			choose8();
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"�����������"<<endl;
			break;		
	}
}
void choose7()
{
	Interface4();
	switch(key){
		case 1:
			print_SqList1(L);
			break;
		case 2:
			cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			SqSearch_SqList(L,s);
			break;
		case 3:
			choose5();
			break;
		default:
			cout<<"�����������"<<endl;
			break;		
	}
}
void choose8()
{
	Interface5();
	switch(key){
		case 1:
			
			print_Linklist(L2);
			break;
		case 2:
			cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			SqSearch_Linklist(L2,s);
			break;
		case 3:
			choose5();
			break;
		default:
			cout<<"�����������"<<endl;
			break;		
	}
}
void choose6()
{
	Interface6();
	switch(key){
		case 1:
			print_SqList2(L);
			break;
		case 2:
			cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			HalfSearch_SqList(L,s);
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"�����������"<<endl;
			break;
		}
}
void choose3()
{
	Interface7();
	switch(key){
		case 1:
			Word w2[5000];
			mid(T,w2);
			print_BiTree(T,w2);
			break;
		case 2:
		cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			Search_BiTree2(s);
			break;
		case 3:
			choose2();
			break;
		default:
			cout<<"�����������"<<endl;
			break;
		}
}
void choose4()
{
	Interface8();
	switch(key){
		case 1:
			choose9();
			break;
		case 2:
			choose10();
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"�����������"<<endl;
			break;
		}
}
void choose9()
{
	Interface9();
	switch(key){
		case 1:
			print_HashTable(HT);
			break;
		case 2:
			cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			Search_Hash(HT,s);
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"�����������"<<endl;
			break;
		}
}
void choose10()
{
	Interface10();
	switch(key){
		case 1:
			print_HashList(HL);
			break;
		case 2:
			cout<<"����������ҵ���:";
			char s[100];
			cin>>s;
			Search_HashList(HL,s);
			break;
		case 3:
			choose1();
			break;
		default:
			cout<<"�����������"<<endl;
			break;
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	FILE *fp=fopen("D://InFile.txt","r+");
	if(fp==NULL){
		cout<<"���ܴ�";
		exit(1);	
	}
	int count,n=0,num;
	char ch;
	while((ch=fgetc(fp))!=EOF){
		s[count++]=ch;//���ļ��е������ַ���ȡ���ַ�����s�У�ʵ����û��Ҫ 
	}
	fclose(fp);//�ر��ļ� 
	for(int i=0;i<count;i++){
		if(s[i]>='a'&&s[i]<='z') {
			w[num][n]=s[i];n++;
		}
		else if(s[i]>='A'&&s[i]<='Z'){
			char ch=s[i]-'A'+'a';
			w[num][n]=ch;
			n++;
		}
		else{
			num++;
			n=0;
		}
	}
	count=0;//��¼���ʵ������� 
	for(int i=0;i<num;i++){
		int x=0,flag=0;
		if(w[i][0]>='a'&&w[i][0]<='z'){
			for(x=0;x<count;x++){
				if(strcmp(word[x].s,w[i])==0){
					flag=1;
					break;
				} 
			}
			if(flag==1){//�����������һ�� 
				word[x].number++; 
			}
			else{ 
				for(int j=0;w[i][j]!='\0';j++) word[count].s[j]=w[i][j];
				word[count].number++;
				count++;
			}	
		} 
	}
	word_count=count;
	Init_SqList(L);
	for(int i=0;i<count;i++){
		SqList_Insert(L,word[i]);
	} 	
	Init_Linklist(L2);
	for(int i=0;i<count;i++){
		Linklist_Insert(L2,word[i]);
	}
	CreateBST(T,word,count);
	Create_HashTable(HT);
	for(int i=0;i<count;i++){
		HashTable_Insert(HT,word[i]);
	}
	for(int i=0;i<Table_size;i++){
		Create_HashList(HL[i]);
	} 
	for(int i=0;i<count;i++){
		HashList_Insert(HL,word[i]);
	}
	choose1();//����ѡ����� 
	return 0;
}


