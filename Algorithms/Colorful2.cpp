#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

int res[10][10][2];
int n1,m1,k;
const int MOD = 100000007;
int count(int n1,int n2, int f)
{
	if (res[n1][n2][f] != -1)
	{
		return res[n1][n2][f];
	}
	if (n1 + n2 == 0)
	{
		res[n1][n2][f] = 1 % MOD;
		return 1;
	}
	int j;
	res[n1][n2][f] = 0;
	if (f == 0)
	{
		for (j = 1; j <= k; j++)
		{
			res[n1][n2][f] += count(n1 - j, n2, 1 - f);
		}
	}
	else
	{
		for (j = 1; j <=k; j++)
		{
			res[n1][n2][f] += count(n1, n2 - j, 1 - f);
		}
	}
	return res[n1][n2][f];
}

void solve()
{
	memset(res,-1,sizeof(res));
	cin>>n1>>m1>>k;
	cout<<(count(n1,m1,0)+count(n1,m1,1));
}

int main()
{
	fast;
	ll t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}



