//poj-1182
//https://blog.csdn.net/niushuai666/article/details/6981689  很好的博客
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 5e4+5;
int n,k;
int ans;
//此处ra有三种取值(假设节点x的父节点为rootx,即p[x].parent=rootx)：
//p[x].ra=0   ……表示节点x与其父节点rootx的关系是：同类
//p[x].ra=1   ……表示节点x与其父节点rootx的关系是：被根结点吃
//p[x].ra=2   ……表示节点x与其父节点rootx的关系是：吃根结点
/*
x->y 偏移量0时 x和y同类
x->y 偏移量1时 x被y吃
x->y 偏移量2时 x吃y

有了这个假设，我们就可以在并查集中完成任意两个元素之间的关系转换了。
不妨继续假设，x的当前集合根节点rootx，y的当前集合根节点rooty，x->y的偏移值为d-1（题中给出的询问已知条件）
(a->b) = -(b->a) + MOD （+MOD 避免出现负数)
(1)如果rootx和rooty不相同，那么我们把rooty合并到rootx上，并且更新ra关系域的值（注意：p[i].ra表示i的根结点到i的偏移量！！！！（向量方向性一定不能搞错））
	rootx -> rooty = rootx->x + x->y + y->rooty
				   = rootx->x + x->y + (3 - rooty->y)
				   = [ p[x].ra + (op-1) + (1 - p[y].ra) ] %3;  （模3是保证偏移量取值始终在[0,2]间）
				   = p[rooty].ra
		(注：这里的 op-1 是由题目决定的，x->y = p[y].ra = op-1 正好对应起来； 
			op = 1 的话 x->y = p[y].ra = op-1 = 0  表示 x 与 y 是同类
			op = 1 的话 x->y = p[y].ra = op-1 = 1  表示 y 被 x 吃即 x 吃 y)
(2)如果rootx和rooty相同(即x和y在已经在一个集合中，不需要合并操作了，根结点相同)，那么我们就验证x->y之间的偏移量是否与题中给出的op-1一致
	此时 x->y = x->rootx + rootx->y
	x->rootx = 3 - rootx->x = 3 - p[x].ra
	实际就是 x->rootx = -(rootx->x) +3 (+3 是为了避免出现负数)
    上式进一步转化为：x->y = [ (3 - p[x].ra) + p[y].ra] %3
    若一致则为真，否则为假。
*/
struct node{
	int fa;  //p[i].fa 表示结点 i 的父节点
	int ra;  //p[i].ra 表示结点 i 与其父节点(即 p[i].fa)的关系
};
node p[N];

void init() //初始化
{
	for(int i=1;i<=n;i++){
		p[i].fa = i;  //初始时集合编号就设置为自身
		p[i].ra = 0;  //因为p[i].parent=i,即节点i的父亲节点就是自身,所以此时节点i与其父亲节点的关系为同类(即p[i].ra=0)
	}
}

int find(int x)  //查找根结点
{
	if(x != p[x].fa){
		int tmp = p[x].fa;  //路径压缩
		p[x].fa = find(p[x].fa);
		//int tmp = p[x].fa; 在这里定义 tmp = p[x].fa 会错，因为此时的 p[x].fa 已经发生改变了
		p[x].ra = (p[x].ra + p[tmp].ra)%3;  //关系域更新
	}
	return p[x].fa;  //根结点
}
int main()
{
	cin>>n>>k;
	init();
	for(int i=1;i<=k;i++)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b); //用 cin 会 TLE
		int root_a = find(a);
		int root_b = find(b);
		if(a > n || b > n) ans++; //不符合条件 2
		else if(op == 2 && a == b) ans++;  //不符合条件 3
		else if(find(a) != find(b))
		{
			p[root_b].fa = root_a;
			p[root_b].ra = (p[a].ra + (op-1) + (3 - p[b].ra))%3;
		}
		else
		{
			if(op == 1 && p[a].ra != p[b].ra)
			{
				ans++;
				continue;
			}
			if(op == 2 && ((3-p[a].ra + p[b].ra)%3 != op-1))
			{
				ans++;
				continue;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
Sample Input
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
Sample Output
3
*/