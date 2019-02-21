#include <bits/stdc++.h>
#define rt return
#define cin(x) scanf("%d",&x)
#define cinl(x) scanf("%lld",&x)
#define cout(x) printf("%d\n",x)
#define coutl(x) printf("%lld\n",x)
#define PB push_back
#define PPB pop_back
#define loop(x,y) for(x=0; x<y; x++)


using namespace std;
typedef long long int ll;
typedef vector<int> V;
typedef vector<ll> VL;

int main()
{
    VL fib;
    ll i,n=70,j;
    fib.PB(0);
    fib.PB(1);
    loop(j,n) i=fib[j]+fib[j+1],fib.PB(i);
    loop(j,fib.size()) cout<<fib[j]<<endl;
    fib.clear();
    rt 0;
}
