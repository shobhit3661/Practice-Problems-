#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n;
	cin>>n;
	int ar[n];
	int dp[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		dp[i]=1;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(ar[i]>ar[j])
			{
			  dp[i]= max(dp[i],dp[j]+1);
			}
		}
	}
	
	
	cout<<*max_element(dp,dp+n);
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



