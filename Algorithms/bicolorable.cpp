#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

bool is_safe(vector<int> adj[],int color[],int v,int clr)
{
    for(int i=0;i<adj[v].size();i++)
    {
        if(color[adj[v][i]]==clr)
        return 0;
    }
    return 1;
}
bool two_color(vector<int> adj[],int color[],int v,int V)
{
    if(v==V)
    return true;
    for(int clr=0;clr<2;clr++)
    {
        if(is_safe(adj,color,v,clr))
        {
            color[v]=clr;
            if(two_color(adj,color,v+1,V))
            return 1;
            color[v]=0;
        }
    }
    return 0;
}

void solve()
{
	int v,e;
	cin>>v>>e;
	
	vector<int> adj[v];
	int color[v];
	for(int i=0;i<e;i++)
	{
		int temp,temp1;
		cin>>temp;
		cin>>temp1;
		
		adj[temp].push_back(temp1);
		adj[temp1].push_back(temp);
	}
	
	if(two_color(adj,color,0,v))
	{
		cout<<"BICOLORABLE"<<"\n";
	}
	else
	{
		cout<<"NOT BICOLORABLE"<<'\n';
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



