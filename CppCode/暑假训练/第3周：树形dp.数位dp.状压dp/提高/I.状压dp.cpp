//HDU2809
// 状压dp，最多20个敌人，用0 1 表示这个敌人是否杀过，1杀过，0没杀。
// dp[i]=在i状态的最大hp。

// for(i=0;i<(1 << N)-1;i++)
//     for(当前状态再多杀一个)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 22;
int dp[1<<N];
int num;
struct person{
    int ati;
    int def;
    int hp;
    int exp;
}Lv,Enemy[N],Update;
int main()
{
    while(scanf("%d%d%d%d%d%d",&Lv.ati,&Lv.def,&Lv.hp,&Update.ati,&Update.def,&Update.hp)!=EOF){
        memset(dp,0,sizeof dp);
        cin>>num;
        string name;
        for(int i=0;i<num;i++){
            cin>>name;
            scanf("%d%d%d%d",&Enemy[i].ati,&Enemy[i].def,&Enemy[i].hp,&Enemy[i].exp);
        }
        dp[0] = Lv.hp;  //初始
        for(int st=0;st < (1<<num);st++){  //遍历所有状态
            if(dp[st]<=0) continue;  //如果当前状态吕布死亡
            int ati,def,hp,exp;
            exp = 0;
            for(int k=0;k<num;k++){  //遍历当前状态吕布已经击杀的敌人
                if(st & (1<<k)){
                    exp += Enemy[k].exp;  //将击杀每个敌人获取的经验累加
                }
            }
            ati = Lv.ati + (exp/100*Update.ati);  //更新攻击力
            def = Lv.def + (exp/100*Update.def);  //更新防御力
            hp = dp[st];   //当前状态吕布的血量记为 hp
            for(int j=0;j<num;j++){  //遍历当前状态下下一步要杀的敌人
                int tmp_st = 1<<j;
                int tmp_hp = hp;   //用 tmp_hp 暂存 hp
                if((st & tmp_st)==0){  //如果该敌人还没有击杀
                    tmp_st = st | tmp_st;  //更新状态为该敌人已击杀
                    int ehp = Enemy[j].hp;
                    while(ehp>0){
                        ehp -= max(1,ati-Enemy[j].def);  //吕布砍该敌人一刀
                        if(ehp>0)   //如果吕布砍完一刀后击杀了敌人，那么该敌人就不会再砍吕布一刀
                            tmp_hp -= max(1,Enemy[j].ati-def);  //如果该敌人没有死的话，才会砍吕布一刀
                    }
                    if(tmp_hp > 0){  //如果击杀敌人后，吕布血量值仍然大于 0 的话
                        if((exp+Enemy[j].exp)/100 > exp/100)  //看一下击杀该敌人获得的经验值够不够升一级
                            tmp_hp += Update.hp;  //如果够升一级则更新血量
                                                  //这里没必要更新攻击力，防御力，
                        dp[tmp_st] = max(dp[tmp_st],tmp_hp);  //相同状态下取一个最大值，
                        //要明白，相同状态下剩余的 hp 可能不同，因为虽然杀的敌人相同，但是杀敌顺序会影响剩余的hp,所以要从中选取最优的杀敌顺序，即剩余 hp 最大
                    }
                }
            }
        }
        if(dp[(1<<num)-1]>0) cout<<dp[(1<<num)-1]<<endl;
        else cout << "Poor LvBu,his period was gone."<<endl;
        
        
    }
    return 0;
}