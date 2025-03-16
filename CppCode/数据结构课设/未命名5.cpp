#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
char s[1000],w[100][100];//����w[]����������е��� 
clockid_t start,stop;//ʱ��
int word_count;
typedef struct{
	char s[100];//��ŵ��� 
	int number;//���ִ��� 
}Word; //���ʽṹ�� 
void sort_Word(Word w[])//�Խṹ������w[]������ַ��������ֵ������� 
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
////////////////////////////////////////////////////////////////////////// 
///////////˳��� 
typedef struct{
	Word *elem;
	int len;
}SqList;//˳��� 
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
void print(SqList L)//˳����ӡ 
{
	for(int i=0;i<L.len;i++){
		cout<<L.elem[i].s<<" "<<L.elem[i].number<<endl;
	}
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
	stop = clock();
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
		printf("ƽ�����ҳ���: \n"); 
	}
	
 } 
////////////////////////////////////////////////////////////////////////////
////////���� 
typedef struct Lnode{
	Word data;
	struct Lnode *next;
}Lnode,*Linklist;
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
 int Displist(Linklist L)//�����ӡ 
{
	Lnode *p=L->next;
	while(p){
		cout<<p->data.s<<" "<<p->data.number<<endl;
		p=p->next;
	}
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
		printf("ƽ�����ҳ���: \n"); 
	}
}
/////////////////////////////////////////////////////////////////////////////////// 
//////����������
typedef struct BiTNode{
	Word data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
int SearchBST_(BiTree &T,Word a,BiTree f,BiTree &p)
{                            //�ڶ����������в��ҹؼ��ֵ���key��Ԫ��
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
BiTree Search_BiTree(BiTree T,char a[])
{
	if(strcmp(T->data.s,a)==0) return T;
	else if(strcmp(T->data.s,a)>0) Search_BiTree(T->lchild,a);
	else if(strcmp(T->data.s,a)<0) Search_BiTree(T->rchild,a);
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
 void mid(BiTree T)//����������������� 
{
	if(T!=NULL){
		mid(T->lchild);
		cout<<T->data.s<<endl;
		mid(T->rchild);	
    }
 } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///��ϣ(ɢ�б�)����----���ڿ��ŵ�ַ���Ĺ�ϣ����----------- 
const int Table_size=100; //��ϣ�������洢�ĵ����������ʱ������Ӧ���� 
typedef struct{
	Word *elem;//����Ԫ�ش洢����̬�������� 
	int  num;//��ǰ����Ԫ�صĸ��� 
}HashTable; 
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
void Search_Hash(HashTable Ta,char *q)
{
	int tmpAdress,flag;
	start = clock();
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
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==1) cout<<"����ʧ��"<<endl;
	else {
		printf("�˵��ʵĴ�ƵΪ: %d\n",Ta.elem[tmpAdress].number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: \n");
	}
}
void print_HashTable(HashTable Ta)
{
	for(int i=0;i<Table_size;i++){
		if(Ta.elem[i].s[0]>='a'&&Ta.elem[i].s[0]<='z'){  //if(Ta.elem[i].s=='\0')???
			cout<<Ta.elem[i].s<<" "<<Ta.elem[i].number<<endl;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///��ϣ(ɢ�б�)����----��������ַ���Ĺ�ϣ����-----------
typedef struct HashNode{
	Word elem;
	struct HashNode *next;
}HashNode,*HashList;
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
void Search_HashList(HashList HL[],char *s)//��ʽ��ϣ���� 
{
	int tmpAdress,flag;
	HashNode *p;
	start = clock();
	for(int i=0;i<=100000;i++){
		tmpAdress=Hash(s);
		flag=0;
		p=HL[tmpAdress]->next;
		while(p){
			if(strcmp(p->elem.s,s)==0){ //���ҵ��˵��� 
				flag=1;
				break;
			}
		}
	}
	stop = clock();
	double duration = ((double)(stop - start));// / CLK_TCK;
	if(flag==0) cout<<"����ʧ��"<<endl;
	else {
		printf("�˵��ʵĴ�ƵΪ: %d\n",p->elem.number);
		printf("���Ҹõ���������ʱ��: %fms\n",duration);
		printf("ƽ�����ҳ���: \n");
	}
	
} 
void print_HashList(HashList HL[])
{
	for(int i=0;i<Table_size;i++){
		HashNode *p=HL[i]->next;
		while(p){
			cout<<p->elem.s<<" "<<p->elem.number<<endl;
			p=p->next;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

int main()
{
	FILE *fp=fopen("InFile.txt","r+");
	if(fp==NULL){
		cout<<"���ܴ�";
		exit(1);	
	}
	int count=0,n=0,num;
	char ch;
	while((ch=fgetc(fp))!=EOF){
		s[count++]=ch;//���ļ��е������ַ���ȡ���ַ�����s�У�ʵ����û��Ҫ 
	}
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
	Word word[5000];//��Ų��ظ��ĵ��� 
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
	sort_Word(word);
	for(int i=0;i<count;i++) cout<<word[i].s<<endl;
	SqList L;
	Init_SqList(L);
	for(int i=0;i<count;i++){
		SqList_Insert(L,word[i]);
	} 
	print(L);
	cout<<endl;
	
	Linklist L2;
	Init_Linklist(L2);
	for(int i=0;i<count;i++){
		Linklist_Insert(L2,word[i]);
	}
	Displist(L2);
	cout<<endl;
	
	BiTree T;
	CreateBST(T,word,count);
	mid(T);
	cout<<endl;
	 
	HashTable HT;
	Create_HashTable(HT);
	for(int i=0;i<count;i++){
		HashTable_Insert(HT,word[i]);
	}
	print_HashTable(HT);
	cout<<endl;
	
	HashList HL[Table_size];
	for(int i=0;i<Table_size;i++){
		Create_HashList(HL[i]);
	} 
	for(int i=0;i<count;i++){
		HashList_Insert(HL,word[i]);
	}
	print_HashList(HL);
	cout<<"Enter a word"<<endl;
	char c[100];
	cin>>c;
	BiTree q=Search_BiTree(T,c);
	printf("�˵��ʵĴ�ƵΪ: %d\n",q->data.number);
	printf("���Ҹõ���������ʱ��: %fms\n");
	printf("ƽ�����ҳ���: \n");
	 fclose(fp);	
	return 0;
}

