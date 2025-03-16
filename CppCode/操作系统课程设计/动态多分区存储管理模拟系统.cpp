#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include<cstring>
#include <queue>
#include <malloc.h>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
int Max_size;  //���洢�ռ�
typedef struct used_node{
    int address;
    int lenth;
    int pid;
    used_node *next;
} used_node,*used_ptr;

typedef struct free_node{
    int address;
    int lenth;
    int flag;
    free_node *next;
} free_node,*free_ptr;

free_ptr free_head;
used_ptr used_head;
int last_address; //��¼��һ�η����ڴ��ĩ��ַ�����ڽ��� CFF �㷨
int select,pid,size;

//��� free_table �� used_table
void show_space()
{
    printf("---------free memory table----------\n");
    printf("address\t\tlength\t\tflag\n");
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        printf("%d\t\t%d\t\t%d\n",free_tmp->address,free_tmp->lenth,free_tmp->flag);
        free_tmp = free_tmp->next;
    }
    printf("---------used memory table----------\n");
    printf("address\t\tlength\t\tpid\n");
    used_ptr used_tmp = (used_ptr)malloc(sizeof(used_node));
    used_tmp = used_head->next;
    while(used_tmp != NULL){
        printf("%d\t\t%d\t\t%d\n",used_tmp->address,used_tmp->lenth,used_tmp->pid);
        used_tmp = used_tmp->next;
    }
    cout<<endl<<endl;
}
//��ʼ��
void init()  
{
    free_head = (free_ptr)malloc(sizeof(free_node));
    free_head->next = NULL;
    used_head = (used_ptr)malloc(sizeof(used_node));
    used_head->next = NULL;
    free_ptr fp = (free_ptr)malloc(sizeof(free_node));
    fp->address = 0;
    fp->flag = 0;
    fp->lenth = Max_size;
    fp->next = NULL;
    free_head->next = fp;

}
//���� used_table
void used_insert(used_ptr &p)
{
    used_ptr used_tmp = (used_ptr)malloc(sizeof(used_node));
    used_tmp = used_head->next;
    if(used_tmp == NULL){
        used_head->next = p;
        return;
    } 
    else if(used_tmp->next == NULL){
        if(used_tmp->address > p->address){
            p->next = used_tmp;
            used_head->next = p;
        }
        else{
            used_tmp->next = p;
        }
        return;
    }
    else{
        while(used_tmp != NULL && used_tmp->next != NULL){
            if(used_tmp->address < p->address && used_tmp->next->address > p->address){
                p->next = used_tmp->next;
                used_tmp->next = p;
                return;
            }
            used_tmp = used_tmp->next;
        }
        used_tmp->next = p;
    }
    return;
}
//�ڴ������޸ģ����� ���뵽 used_table �Լ� free_table ��Ӧ�����ڴ��ķ���
void modify(free_ptr &free_tmp)
{
    used_ptr p = (used_ptr)malloc(sizeof(used_node));
    p->address=free_tmp->address,p->lenth=size,p->pid = pid,p->next=NULL;
    used_insert(p);

    free_tmp->flag = 1;
    int left = free_tmp->lenth - size;
    if(left != 0){
        free_ptr fp = (free_ptr)malloc(sizeof(free_node));
        fp->address=p->address+size,fp->lenth=left,fp->flag=0,fp->next=free_tmp->next;
        free_tmp->lenth = size;
        free_tmp->next = fp;
    }
    last_address = free_tmp->address + free_tmp->lenth - 1;  //��¼�˴η����ڴ��ĩ��ַ
}
//�״���Ӧ�㷨
void FF()
{
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->flag == 0 && free_tmp->lenth >= size){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }
    if(free_tmp == NULL) cout<<"�ڴ治�㣬����ʧ��!"<<endl;
}
//ѭ���״���Ӧ�㷨
void CFF()
{
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->address > last_address && free_tmp->lenth > size && free_tmp->flag == 0){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }
    if(free_tmp == NULL){  //֤���� last_address ֮��û�к��ʵ��ڴ�飬��Ҫ��ͷ��ʼ��
        free_tmp = free_head->next;
            while(free_tmp != NULL){
                if(free_tmp->address > last_address){
                    cout<<"�ڴ治�㣬����ʧ��"<<endl;
                    break;
                }
                if(free_tmp->flag == 0 && free_tmp->lenth >= size){
                    modify(free_tmp);
                    break;
                }
                free_tmp = free_tmp->next;
            }
    }
    if(free_tmp == NULL) cout<<"�ڴ治�㣬����ʧ��!"<<endl;
    return;
}
//�����Ӧ�㷨
void BF()
{
    struct node{
        int address;
        int length;
        bool operator<(const node& a)const{
            return length > a.length;
        }
    };
    priority_queue<node>q;
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->flag == 0){
            node tmp;
            tmp.address = free_tmp->address;
            tmp.length = free_tmp->lenth;
            q.push(tmp);
        }
        free_tmp = free_tmp->next;
    }
    int tmp_address = -1;
    while(!q.empty()){
        node tmp = q.top();
        q.pop();
        if(tmp.length >= size){
            tmp_address = tmp.address;
            break;
        }
    }
    if(tmp_address == -1) cout<<"�ڴ治�㣬����ʧ��!"<<endl;
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->address == tmp_address){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }

}
//���Ӧ�㷨
void WF()
{
    int tmp_address = -1;
    int Max = 0;
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->flag == 0 && free_tmp->lenth >= size){
            if(free_tmp->lenth > Max){
                Max = free_tmp->lenth;
                tmp_address = free_tmp->address;
            }
        }
        free_tmp = free_tmp->next;
    }
    if(tmp_address == -1) cout<<"�ڴ治�㣬����ʧ��"<<endl;
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->address == tmp_address){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }
    if(free_tmp == NULL) cout<<"�ڴ治�㣬����ʧ��!"<<endl;
    return;
}
//�ϲ� free_table �����ڵĿ����ڴ��(�� flag == 0 �������ڴ��)
void merge()
{
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next->next;
    free_ptr pre_free = (free_ptr)malloc(sizeof(free_node)); //��¼ free_tmp ��ǰ�����
    pre_free = free_head->next;
    while(free_tmp != NULL){
        if(pre_free->flag == 0 && free_tmp->flag == 0){
            pre_free->lenth += free_tmp->lenth;
            pre_free->next = free_tmp->next;
            free_tmp = free_tmp->next;
        }
        else{
            pre_free = pre_free->next;
            free_tmp = free_tmp->next;
        }
    }
    return;
}
//�����ڴ��
void reclaim()
{
    int vis[Max_size];  //�������
    mem(vis,0);
    used_ptr used_tmp = (used_ptr)malloc(sizeof(used_node));
    used_tmp = used_head->next;
    used_ptr pre_used = (used_ptr)malloc(sizeof(used_node));  //��¼ used_tmp ��ǰ�����
    pre_used = used_head;
    while(used_tmp != NULL){
        if(used_tmp->pid == pid){
            vis[used_tmp->address] = 1;
            pre_used->next = used_tmp->next; //ɾ�� used_table �ڴ��
        }
        else pre_used = pre_used->next;  //ֻ���ڴ��� pid ����Ҫɾ���� pid ʱ���� pre_used ָ����һ������������֤pre_usedһֱ��used_tmp��ǰ�����
        
        used_tmp = used_tmp->next;
    }
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(vis[free_tmp->address]){
            free_tmp->flag = 0;
        }
        free_tmp = free_tmp->next;
    }
    merge();
    return;

}
int main()
{
    printf("-------Dynamic partition allocation algorithm simulation-------\n");
    printf("Input the Max_size of memory:");
    cin>>Max_size;
    printf("Memory Created Succesfully\n");
    init();
    show_space();
    while(1){
        int op;
        printf("-----Please select memory allocation algorithm-----\n");
        printf("1.FF\t\t2.CFF\t\t3.BF\t\t4.WF\n");
        printf("Algorithm select:");
        cin>>op;
        //���� 
        printf("-----------------------Menu------------------------\n");
        printf("1.allocate\t\t2.reclaim\t\t0.exit\n");
        printf("Select:");
        cin>>select;
        if(select == 0) return 0;
        printf("Pid:");
        cin>>pid;
        if(select == 1){
            printf("Size:");
            cin>>size;
            if(op == 1) FF();
            else if(op == 2) CFF();
            else if(op == 3) BF();
            else if(op == 4) WF();
        }
        else if(select == 2){
            reclaim();
        }
        show_space(); //��� free_table �� used_table
    }
}
