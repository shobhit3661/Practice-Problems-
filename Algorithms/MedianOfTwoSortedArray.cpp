#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void solve()
{
	int n1;
	int n2;
	
	cin>>n1>>n2;
	
	vector<int> nums1;
	vector<int> nums2;
	
	for(int i=0;i<n1;i++)
	{
		int temp;
		cin>>temp;
		nums1.push_back(temp);
	}
	
	for(int i=0;i<n2;i++)
	{
		int temp;
		cin>>temp;
		nums2.push_back(temp);
	}
	

	//bruteForceSolution
	/*int i=0,j=0;
	vector<int> m;
	while(n1>i && n2>j)
	{
		if(nums1[i]<=nums2[j])
		{
			m.push_back(nums1[i]);
			i++;
		}
		else
		{
			m.push_back(nums2[j]);
			j++;
		}
	}
	
	while(n1>i)
	{
		m.push_back(nums1[i]);
		i++;
	}
	while(n2>j)
	{
		m.push_back(nums2[j]);
		j++;
	}
	
	int mid = n1+n2;
	mid/=2;
	cout<<mid<<" "<<n1<<" "<<n2;
	if(mid%2==0)
	{
		cout<<(float)((m[mid]+m[mid-1])/2.0);
	}
	else
	{
		cout<<(float)(m[mid]/2.0);
	}*/	
	
	//Efficent Method
	//O(log(n+m)) Using Binary search
	
	
	
	
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



