#include <bits/stdc++.h>

using namespace std;

int chessboard(int a, int b)
{
    int product = a*b;
    if(a==1 || b==1)
        return product;
    else if(1 & product)
        return (product/2)+1;
    else if(a==2 || b==2){
        int position=4,temp_position;
        product/=2;
        product-=2;
        temp_position = product/4;
        position+= (temp_position*4);
        if(product%4==3)
            position+=2;
        return position;
    }
    else
        return product/2;
}

int main()
{
    int tst,cs=1,n,m;
    scanf("%d",&tst);
    while(tst--){
        scanf("%d%d",&n,&m);
        printf("Case %d: %d\n",cs++,chessboard(n,m));
    }
    return 0;
}
