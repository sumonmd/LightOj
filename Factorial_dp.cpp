#include <bits/stdc++.h>

using namespace std;
typedef long long lng;

int dp[100],vis[100];

lng solve(lng n)
{
    if(n==0) return 1;
    if(vis[n]) return dp[n];
    vis[n]=1;
    dp[n]=n*solve(n-1);
    return dp[n];
}
int main()
{
    solve(15);
    while(1)
    {
        lng a;
        cin>>a;
        cout<<dp[a]<<endl;
    }
    return 0;
}
