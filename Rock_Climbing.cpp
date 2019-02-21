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
