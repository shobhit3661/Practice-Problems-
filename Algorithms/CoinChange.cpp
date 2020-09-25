#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int amount;
	cin>>amount;
	
	int size;
	cin>>size;
	int coins[size];
	for(int i=0;i<size;i++)
	{
		cin>>coins[i];
	}
	
	int dp[amount+1];
            dp[0]=0;
            for(int i=1;i<=amount;i++)
            {
                dp[i] = INT_MAX;
            }
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(coins[j]<=i)
                {
                   int temp = dp[i-coins[j]];
                    if(temp != INT_MAX && temp+1<dp[i])
                    {
                        dp[i]=temp+1;
                    }
                }
            }
        }
    
	cout<<dp[amount];
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



