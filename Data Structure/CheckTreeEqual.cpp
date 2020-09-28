/*
	How to Check equal trees and printing the inorder traversal of the tree and converting the in order traversal to tree
*/


#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

struct node
{
	int data;
	struct node* right;
	struct node* left;
	
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};


int find_max(int ar[],int start,int end)
{
	int max_index = start;
	int max_item = ar[start];
	
	for(int i=start;i<=end;i++)
	{
		if(max_item < ar[i])
		{
			max_item = ar[i];
			max_index = i;
		}
	}
	
	return max_index;
}

bool checkEqual(struct node *root1,struct node *root2)
{
	if(root1 == NULL && root2==NULL)
	{
		return true;
	}
	
	if(root1==NULL)
	{
		return false;
	}
	
	if(root2==NULL)
	{
		return false;
	}
	
	if(root1->data != root2->data)
	{
		return false;
	}
	
	return checkEqual(root1->left,root2->left) && checkEqual(root1->right,root2->right);	
}

void print_tree(struct node *temp)
{
	if(temp == NULL)
	{
		return;
	}
	
	print_tree(temp->left);
	
	cout<<temp->data<<" ";
	
	print_tree(temp->right);
}

node* insert_inorder(int ar[],int start,int end)
{
	if(start>end)
	{
		return NULL;
	}
	
	int i = find_max(ar,start,end);
	
	node *root = new node(ar[i]);
	
	if(start==end)
	{
		return root;
	}
	
	root->left = insert_inorder(ar,start,i-1);
	root->right = insert_inorder(ar,i+1,end);
	
	return root;
}




void solve()
{
	struct node *root1 = NULL;
	struct node *root2 = NULL;
	
	int n;
	cin>>n;
	
	int ar1[n];
	int ar2[n];
	for(int i=0;i<n;i++)cin>>ar1[i];
	
	for(int i=0;i<n;i++)cin>>ar2[i];
	
	root1 = insert_inorder(ar1,0,n-1);
	root2 = insert_inorder(ar2,0,n-1);
	
	print_tree(root1);
	cout<<"\n";
	print_tree(root2);
	cout<<"\n";
	
	if(checkEqual(root1,root2))
	{
		cout<<"Yes";
	}
	
	else
	{
		cout<<"No";
	}
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



