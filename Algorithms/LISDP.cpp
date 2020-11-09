/*
	5
	3 10 2 1 20
	3
	
	Input: arr[] = {3, 10, 2, 1, 20}
	Output: Length of LIS = 3
	The longest increasing subsequence is 3, 10, 20

	Input: arr[] = {3, 2}
	Output: Length of LIS = 1
	The longest increasing subsequences are {3} and {2}

	Input: arr[] = {50, 3, 10, 7, 40, 80}
	Output: Length of LIS = 4
	The longest increasing subsequence is {3, 7, 40, 80}
*/

#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++)cin>>ar[i];
	
	int table[n];
	memset(table,0,sizeof(table));
	table[0] =1;
	
	for (int i = 1; i < n; i++ )  
    { 
        table[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( ar[i] > ar[j] && table[i]<table[j]+1)
			{
				table[i] = table[j] + 1;
				cout<<ar[j]<<"\n";
				for(int i=0;i<n;i++)
				{
					cout<<table[i]<<" ";
				}
				cout<<"\n";	
			}  
                  
    } 
	
	
	cout<<*max_element(table, table+n);
}

int main()
{
	fast;
	ll t=1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}



