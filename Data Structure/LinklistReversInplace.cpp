#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;
struct node
{
	int data;
	struct node *next;

	node(int val)
	{
		data = val;
		next = NULL;
	}
};


void print_linklist(struct node *head)
{
	struct node *temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<"\n";	
}

node* insert_data(struct node* head,int data)
{
	struct node *newnode = new node(data);
	
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	
	struct node *temp = head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = newnode;
	
	return head;	
	
}

void revers_linklist(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL;
	struct node *next;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head = prev;
}


void solve()
{
	int n;
	cin>>n;
	int ar[n];
	struct node *head = NULL;
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		head = insert_data(head,data);
	}
	print_linklist(head);
	revers_linklist(&head);
	print_linklist(head);
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



