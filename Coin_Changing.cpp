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
