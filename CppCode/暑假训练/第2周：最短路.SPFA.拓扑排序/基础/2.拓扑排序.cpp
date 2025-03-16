//POJ1904
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 30;
int n,m;
int map[N][N];
char s[5];
int d[N],tmp[N];
int sort_flag = 0;
int out_flag = 0;
queue<int>q;
queue<int>sort_q; 
void topsort(int d[])  //拓扑排序
{
    while(!q.empty()) q.pop();
    while(!sort_q.empty()) sort_q.pop();
    for(int i=1;i<=n;i++){
        if(d[i]==0) q.push(i);  //入度为0的点入队
    }
    while(!q.empty()){
        if(q.size()>1) sort_flag = 1; //如果当前队列中的元素个数大于1，说明初始或者去掉入度为0的边后 有多个入度为0的点，这些点无法排序
                                      //因此队列sort_q中的元素不是排好序的，可能存在相邻元素无法比较的情况
                                      //如果一个图满足拓扑排序，那么(如果队列不空)每时每刻队列中只能有一个元素
        int u = q.front();
        q.pop();
        sort_q.push(u);  //按照队列q的出队顺序存储，如果sort_flag==0说明该队列中的顺序就是拓扑排序的顺序
                         //如果sort_q.size() < n，说明图中存在 -----> 环
                         //如果图中没有环的话，所有的顶点都会进队的，只是可能不满足拓扑排序的顺序
        for(int i=1;i<=n;i++){
            if(map[u][i]==1) {    
                d[i]--; //删去 u-->i 这条边后，点 i 的入度减 1
                if(d[i]==0) q.push(i);  //如果点 i 的入度==0，入队
            }
        }
    }
}
void Copy(int d[],int tmp[])
{
    for(int i=1;i<=n;i++) tmp[i] = d[i];
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(map,0x3f,sizeof map);
        memset(d,0,sizeof d);
        memset(tmp,0,sizeof tmp);
        out_flag = 0;  //判断是否已经输出答案
        if(n==0 && m==0) break;
        for(int i=1;i<=m;i++){
            scanf("%s",&s);
            int u = s[0] - 'A'+1;
            int v = s[2] - 'A'+1;
            map[u][v] = 1;
            d[v]++; //入度加 1 
            Copy(d,tmp);  //用临时数组tmp来存储数组d，因为在进行拓扑排序是数组元素值会改变
            sort_flag = 0;  //代表队列sort_q中元素顺序是否满足拓扑排序
            if(out_flag==0) topsort(tmp);
            if(sort_q.size()<n && out_flag == 0){  //图中有环
                printf("Inconsistency found after %d relations.\n",i);
                out_flag = 1;
            }
            if(sort_flag==0 && out_flag == 0){
                printf("Sorted sequence determined after %d relations: ",i);
                while(!sort_q.empty()){
                    char ch = (sort_q.front()-1)+'A';
                    cout<<ch;
                    sort_q.pop();
                }
                printf(".\n");
                out_flag = 1;
            }
        }
        if(out_flag == 0) printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
/*
样例输入
4 6
A<B
A<C
B<C
C<D
B<D
A<B
3 2
A<B
B<A
26 1
A<Z
0 0

样例输出
Sorted sequence determined after 4 relations: ABCD.
Inconsistency found after 2 relations.
Sorted sequence cannot be determined.
*/