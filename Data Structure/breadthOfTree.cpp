/*
		10
	   /   \
	  5     40
	    \      \
	     7      50
	     
	given BST find Distance B/W leftmost and right most element from the root 
	
	left is 5 distance = 1;
	rigth is 50 distance = 2;
	
	total distance = 1+2;
*/

#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

set<int> sol;

struct node{
	int data;
	struct node *right;
	struct node *left;
	
	node(int val)
	{
		data = val;
		right = NULL;
		left = NULL;
	}
};

node* creatBST(int ar[],int *last,int key,int min,int max)
{
		if(*last<0)
		{
			return NULL;
		}
		
		struct node *root = NULL;
		
		if(key>min && key <max)
		{
			root = new node(key);
			*last = *last -1;
			
			if(last >= 0)
			{
				root->right = creatBST(ar,last,ar[*last],key,max);
				root->left = creatBST(ar,last,ar[*last],min,key);
			}
		}
		
		return root;
}

void findBreadth(struct node *root,int dis)
{
	if(root == NULL)
	{
		return;
	}
	
	findBreadth(root->left,dis-1);
	sol.insert(dis);
	findBreadth(root->right,dis+1);
}

void printTree(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
	
}

void solve()
{
	int n=5;
	//cin>>n;
	
	int ar[n] = {7, 5, 50, 40, 10};
	//BST form post order;
	//for(int i=0;i<n;i++)cin>>ar[i];
	int lastindex = n-1;
	//int lastvalue = a[n-1];x
		
	struct node *root;
	root = creatBST(ar,&lastindex,ar[n-1],INT_MIN,INT_MAX);
	printTree(root);
	findBreadth(root,0);
	cout<<"\n";
//	int max = findMax(sol);
//	int min = findMin(sol);
	
	cout<<"Breadth = "<<abs(*sol.begin())+abs(*sol.rbegin())<<"\n";
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



