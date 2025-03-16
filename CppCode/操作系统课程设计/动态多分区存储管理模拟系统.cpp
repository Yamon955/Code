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
int Max_size;  //最大存储空间
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
int last_address; //记录上一次分配内存的末地址，便于进行 CFF 算法
int select,pid,size;

//输出 free_table 和 used_table
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
//初始化
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
//插入 used_table
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
//内存分配的修改，包括 插入到 used_table 以及 free_table 相应空闲内存块的分裂
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
    last_address = free_tmp->address + free_tmp->lenth - 1;  //记录此次分配内存的末地址
}
//首次适应算法
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
    if(free_tmp == NULL) cout<<"内存不足，分配失败!"<<endl;
}
//循环首次适应算法
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
    if(free_tmp == NULL){  //证明在 last_address 之后没有合适的内存块，需要从头开始找
        free_tmp = free_head->next;
            while(free_tmp != NULL){
                if(free_tmp->address > last_address){
                    cout<<"内存不足，分配失败"<<endl;
                    break;
                }
                if(free_tmp->flag == 0 && free_tmp->lenth >= size){
                    modify(free_tmp);
                    break;
                }
                free_tmp = free_tmp->next;
            }
    }
    if(free_tmp == NULL) cout<<"内存不足，分配失败!"<<endl;
    return;
}
//最佳适应算法
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
    if(tmp_address == -1) cout<<"内存不足，分配失败!"<<endl;
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->address == tmp_address){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }

}
//最坏适应算法
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
    if(tmp_address == -1) cout<<"内存不足，分配失败"<<endl;
    free_tmp = free_head->next;
    while(free_tmp != NULL){
        if(free_tmp->address == tmp_address){
            modify(free_tmp);
            break;
        }
        free_tmp = free_tmp->next;
    }
    if(free_tmp == NULL) cout<<"内存不足，分配失败!"<<endl;
    return;
}
//合并 free_table 中相邻的空闲内存块(即 flag == 0 的相邻内存块)
void merge()
{
    free_ptr free_tmp = (free_ptr)malloc(sizeof(free_node));
    free_tmp = free_head->next->next;
    free_ptr pre_free = (free_ptr)malloc(sizeof(free_node)); //记录 free_tmp 的前驱结点
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
//回收内存块
void reclaim()
{
    int vis[Max_size];  //标记数组
    mem(vis,0);
    used_ptr used_tmp = (used_ptr)malloc(sizeof(used_node));
    used_tmp = used_head->next;
    used_ptr pre_used = (used_ptr)malloc(sizeof(used_node));  //记录 used_tmp 的前驱结点
    pre_used = used_head;
    while(used_tmp != NULL){
        if(used_tmp->pid == pid){
            vis[used_tmp->address] = 1;
            pre_used->next = used_tmp->next; //删除 used_table 内存块
        }
        else pre_used = pre_used->next;  //只有内存块的 pid 不是要删除的 pid 时才让 pre_used 指向下一个，这样来保证pre_used一直是used_tmp的前驱结点
        
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
        //跳入 
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
        show_space(); //输出 free_table 和 used_table
    }
}
