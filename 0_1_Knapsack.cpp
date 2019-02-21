/// 0_1 Knapsack code ///

#include <bits/stdc++.h>

using namespace std;
typedef long long lng;

lng cap,weight[100],cost[100],item,dp[101][101];
bool vis[101][101];

lng profit(lng i, lng w)
{
    lng prof1,prof2;
    if(i==item+1) return 0;     ///সব কিছু নেয়া হয়ে গেছে
    if(vis[i][w]) return dp[i][w];  ///এই স্টেটটা আগেই হিসাব করে এসেছি
    vis[i][w]=1;
    if(w+weight[i]<=cap)    ///যদি i তম জিনিসটা নেয়া যায় তাহলে লাভের পরিমাণ profit1
        prof1 = cost[i] + profit(i+1,w+weight[i]);
    else
        prof1 = 0;
    prof2 = profit(i+1,w);   ///যদি জিনিসটা না নেই তাহলে লাভ profit2

    dp[i][w] = max(prof1,prof2);    ///বেশি লাভ যেটায় হবে সেটাই আমরা নিবো

    return dp[i][w];
}

int main()
{
    cin>>item>>cap;
    memset(vis,0,sizeof(vis));
    for(lng a=1; a<=item; a++)
        cin>>cost[a]>>weight[a];
    cout<<profit(1,0)<<endl;
    return 0;
}

/// coin changing code ///

#include <bits/stdc++.h>

using namespace std;

int dp[100][100],make,coin[100],coin_num;
bool vis[100][100];

int amount_make(int i, int amount)
{
    int ret1=0,ret2=0;
    if(i>=coin_num)
    {
        if(amount == make) return 1;
        else return 0;
    }
    if(vis[i][amount]) return dp[i][amount];
    vis[i][amount]=1;
    if(coin[i]+amount<=make) ret1 = amount_make(i,coin[i]+amount);
    ret2 = amount_make(i+1,amount);
    dp[i][amount] = ret1|ret2;
    return dp[i][amount];
}
int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        memset(vis,0,sizeof(vis));
        cout<<"Enter coin_number.\n";
        cin>>coin_num;
        cout<<"Enter coins.\n";
        for(int i=0; i<coin_num; i++) cin>>coin[i];
        cout<<"Enter the amount that you want to make.\n";
        cin>>make;
        cout<<amount_make(0,0)<<endl;
    }
    return 0;
}

/// Rock climbing code ///
#include <bits/stdc++.h>
#define inf 1 << 28

using namespace std;

int mat[][10] = { {-1,2,5}, {4,-2,3}, {1,2,10} };
int dp[10][10],row=3,colm=3;
bool vis[10][10];

int rock_climbing(int i, int j)
{
    if(i>=0 && i<row && j>=0 && j<colm)
    {
        if(vis[i][j]) return dp[i][j];
        vis[i][j]=1;
        int ret=-inf;
        ret = max(ret,rock_climbing(i+1,j) + mat[i][j]);
        ret = max(ret,rock_climbing(i+1,j+1) + mat[i][j]);
        ret = max(ret,rock_climbing(i+1,j-1) + mat[i][j]);
        dp[i][j]=ret;
        return dp[i][j];
    }

    return 0;
}
int main()
{
    cout<<rock_climbing(0,0)<<endl;
    return 0;
}
