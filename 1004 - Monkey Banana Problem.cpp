/// monkey banana //

#include <bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define get(x) scanf("%d",&x)
#define inf 1<<28

using namespace std;
typedef long long lng;
vector<int>v[200];
int dp[201][101],n,row;
bool vis[201][101];

int count_banana(int i,int j)
{
    if(i>=0 && i<row && j<v[i].size() && j>=0)
    {
        if(vis[i][j]) return dp[i][j];
        vis[i][j]=1;
        int ret = -inf;
        ret = max(ret,count_banana(i+1,j) + v[i][j]);
        if(i<n-1)
            ret = max(ret,count_banana(i+1,j+1) + v[i][j]);
        else
            ret = max(ret,count_banana(i+1,j-1) + v[i][j]);
        dp[i][j] = ret;
        return ret;
    }
    return 0;
}
int main()
{
    int tst,x,cs=1;
    get(tst);
    while(tst--)
    {
        mem(vis,0);
        get(n);
        for(int i=0; i<n; i++)
        {
            v[i].clear();
            for(int j=0; j<=i; j++)
            {
                get(x);
                v[i].push_back(x);
            }
        }
        row =2*n-1;
        for(int i=n; i<row; i++)
        {
            v[i].clear();
            for(int j=i; j<row; j++)
            {
                get(x);
                v[i].push_back(x);
            }
        }
        printf("Case %d: %d\n",cs++,count_banana(0,0));
    }
    return 0;
}

/// coin change ///

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

/// 11137Ingenuous Cubrency ///

#include <bits/stdc++.h>
#define get(x) scanf("%d",&x)
#define put(x) printf("%lld\n",x);

using namespace std;
typedef long long lng;

int coins[23];
lng dp[23][10002],make;
bool vis[23][10002];

lng way(int amount, int i)
{
    if(i==21)
    {
        if(amount==0) return 1;
        return 0;
    }
    if(vis[i][amount]) return dp[i][amount];
    vis[i][amount] = 1;
    lng ret1=0,ret2=0;
    if(amount - coins[i]>=0) ret1 = way(amount-coins[i],i);
    ret2 = way(amount,i+1);
    dp[i][amount] =  ret1+ret2;
    return dp[i][amount];
}
int main()
{
    for(int i=1,j=0; i<=21; i++,j++) coins[j]=i*i*i;
    while(get(make)!=EOF)
    {
        put(way(make,0));
    }
    return 0;
}


