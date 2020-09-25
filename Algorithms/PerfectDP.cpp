#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n;
	
	cin>>n;
	vector<int> p;
	for(int i=1;i<=n;i++)
	{
		if(sqrt(i)==(int)sqrt(i))
		{
			p.push_back(i);
		}
	}
	
	int s = p.size();
	int dp[n+1];
	
	
	for(int i=0;i<=n;i++)
	{
		dp[i] = INT_MAX;
	}
	dp[0]=0;
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s;j++)
		{
			if(p[j] <= i)
			{
				int temp = dp[i-p[j]];
				if(temp != INT_MAX && temp+1 <dp[i])
				{
					dp[i] = temp+1;
				}
			}
		}
	}
	
	for(auto i : p)
	{
		cout<<i<<" ";
	}
	
	cout<<dp[n];
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



