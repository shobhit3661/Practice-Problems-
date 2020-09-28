/*
	total numbers of Binary tree from the given total node used for the binary tree;
*/

#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	int tree_bt[n+1];
	memset(tree_bt,0,sizeof(tree_bt));
	
	tree_bt[0] = 1;
	tree_bt[1] = 1;
	
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			tree_bt[i] += tree_bt[j]*tree_bt[i-j-1];
		}	
	} 
	
	cout<<tree_bt[n];
		
}

int main()
{
	fast;
	ll t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}



