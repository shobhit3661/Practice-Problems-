/*
	Tree Questions
*/

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


node* insert_node(struct node* root,int data,queue<node*>& q)
{
	struct node* new_node = new node(data);
	
	if(root==NULL)
	{
		root = new_node;	
	}	
	
	
	else if(q.front()->left==NULL)
		{
			q.front()->left = new_node;
		}
		
		else if(q.front()->right==NULL)
		{
			q.front()->right = new_node;
			q.pop();
		}
		
	q.push(new_node);
	return root;
}

node* create_tree(int ar[],int n)
{
	node *root = NULL;
	queue<node*> q;
	
	for(int i=0;i<n;i++)
	{
		root = insert_node(root,ar[i],q);
	}
	
	return root;
}

void print_inorder(struct node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	print_inorder(temp->left);
	cout<<temp->data<<" ";
	print_inorder(temp->right);
}

void solve()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	struct node *ans = create_tree(ar,n);
	
	print_inorder(ans);
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



