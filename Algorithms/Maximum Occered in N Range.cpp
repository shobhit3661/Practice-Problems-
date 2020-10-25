#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	int l[n];
	int r[n];
	
	for(int i=0;i<n;i++)cin>>l[i];
	for(int i=0;i<n;i++)cin>>r[i];
	
	int freq[10000];
	memset(freq,0,sizeof(freq));
	
	for(int i=0;i<n;i++)
	{
		freq[l[i]]++;
		freq[r[i]]--;
	}
	int max = 0;
	int ans = 0;
	for(int i=0;i<10000;i++)
	{
		freq[i] = freq[i-1] + freq[i];
		if(max<=freq[i])
		{
			max = freq[i];
			ans = i;
		}
	}
	
	cout<<ans<<"\n";
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



