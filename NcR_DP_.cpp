#include <bits/stdc++.h>

using namespace std;
typedef long long lng;

lng dp[60][60];

lng n_c_r(lng n, lng r)
{
    if(n==r || !r) return 1;
    if(dp[n][r]) return dp[n][r];
    else
        dp[n][r] = n_c_r(n-1,r) + n_c_r(n-1,r-1);
    return dp[n][r];
}
int main()
{
    lng ncr,N,R;
    while(1)
    {
        cout<<"Enter n and r:\n"<<endl;
        memset(dp, 0, sizeof(dp));
        cin>>N>>R;
        ncr = n_c_r(N,R);
        cout<<N<<"C"<<R<<" = "<<ncr<<endl;
    }

    return 0;
}

