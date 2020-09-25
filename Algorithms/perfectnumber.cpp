#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	ll n;
	cin>>n;
	ll temp = 1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			temp +=i;
			temp +=(n/i);
		}
	}
	
	if(temp ==n)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
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



