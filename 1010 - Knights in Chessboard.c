#include <stdio.h>

int kn_in_ch(int i, int j)
{
	int kn;
	kn=i*j;
	if(i==1 || j==1 || kn==4)	return kn;	//Case: 1Xj or iX1 or 2X2. All squares used.
	else if((1 & kn) || kn==6)	return (kn/2)+1;	//Case: 2X3 or odd.
	else return kn/2;	//Case: All evens except 2X3.
}

int main()
{
	int x, y, t, i;
	scanf("%d", &t);
	int ans[t];
	for(i=0; i<t; i++)	{
		scanf("%d %d", &x, &y);
		ans[i]=kn_in_ch(x, y);
	}
	for(i=0; i<t; i++)	{
		printf("Case %d: %d\n", i+1, ans[i]);
	}

	return 0;
}
