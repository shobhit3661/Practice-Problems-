#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
	
};



void tree_print(struct node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	
	tree_print(temp->left);
	cout<<temp->data<<" ";
	tree_print(temp->right);
}

void solve()
{
	
struct node *root;
	root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	tree_print(root);
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



