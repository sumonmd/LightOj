#include <bits/stdc++.h>
#define mod 100000007
#define lng long long int
#define max_k 1001
#define max_n 51

using namespace std;
lng dp[max_n][max_k];
int coins[max_n],coin_num[max_n],n;
bool vis[max_n][max_k];

lng way(int index , int amount)
{
    if(index==n)
    {
        if(amount==0) return 1;
        return 0;
    }
    if(amount == 0) return 1;
    if(amount<0) return 0;
    if(vis[index][amount]) return dp[index][amount];
    vis[index][amount] = 1;
    lng result=0;
    for(int i=0; i<=coin_num[index]; i++)
        result = (result+way(index+1,amount-coins[index]*i))%mod;
    dp[index][amount]=result;
    return dp[index][amount];
}

int main()
{
    int cs=1,tst,make;
    scanf("%d",&tst);
    while(tst--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        scanf("%d",&make);
        for(int i=0; i<n; i++) scanf("%d",&coins[i]);
        for(int i=0; i<n; i++) scanf("%d",&coin_num[i]);
        printf("Case %d: %d\n",cs++,way(0,make));
    }
    return 0;
}
