#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

int res;
bool BFS(int count,int rem)
{
	if(count>=res)
	{
		return false;
	}
	
	if(rem==0)
	{
		res = min(count,res);
		return false;
	}
	
	for(int i=sqrt(rem);i>0;i--)
	{
		int i2 = i*i;
		if(!BFS(count + rem/i2,rem%i2))break;
	}
	
	return true;
}
void solve()
{
	res =4;
	int n;
	cin>>n;
	BFS(0,n);
	cout<<res;
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



