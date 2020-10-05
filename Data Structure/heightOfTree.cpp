/*
	input:-
	n =	9
	levelorder = 7 8 12 3 6 8 1 5 10
	inorder = 1 3 5 6 7 8 8 10 12
	Height = 4
		  7        
  	     / \       
  	    4   12      
  	   / \  /     
  	  3  6 8    
  	 /  /   \
  	1   5   10
*/

#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

struct node{
	int data;
	struct node *right;
	struct node *left;
	
	node(int val)
	{
		data = val;
		right = left = NULL;
	}
};

node* creatTree(struct node *root,int data)
{
	if(root==NULL)
	{
		root = new node(data);
		return root;
	}
	
	if(data <= root->data)
	{
		root->left = creatTree(root->left,data);
	}
	
	else
	{
		root->right = creatTree(root->right,data);
	}
	
	return root;
}

void printTree(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}


int heightofTree(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	else
	{
		int lh = heightofTree(root->left);
		int rh = heightofTree(root->right);
		
		if(lh>rh)
			return (lh+1);
		else
			return (rh+1);
	}
}
void solve()
{
	int n;
	cin>>n;
	
	//int ar[n];
	
	struct node *root = NULL;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		root = creatTree(root,temp);	
	}
	
	printTree(root);
	cout<<"\n";
	cout<<heightofTree(root);
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



