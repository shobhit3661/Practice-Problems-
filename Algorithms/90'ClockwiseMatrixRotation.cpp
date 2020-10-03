/*
	Given a N*N matrix Rotate the matrix Rotate the matrix in 90* ClockWise;
	Also a leetcode problem;
	intput:-	
	3
	1 2 3
	4 5 6
	7 8 9
	output:-
	7 4 1
	8 5 2
	9 6 3
	
	Algo:-
	first transpose the matrix;
	//m[i][j] = m[j][i];
	1 4 7
	2 5 8
	3 6 9
	
	then filp the martix;
	7 4 1 
	8 5 2
	9 6 3
		
*/

#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;

void print_matrix(int *m,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp = *((m+i*n) + j);
			cout<<temp<<" ";
		}
		cout<<"\n";
	}
	return;
}
void rotateMatrix(int *m,int n)
{
	//first Transpose the matrix 
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int temp = *((m+i*n)+j);
			*((m+i*n)+j) = *((m+j*n)+i);
			*((m+j*n)+i) = temp;	
		}		
	}
	
	int t = (int)n/2;
	int last = n-1;
	//flip matrix from Y axis;
	//cout<<*((m+0*n)+last)<<" "<<t<<"\n";
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp = *((m+j*n)+i);
			*((m+j*n)+i) = *((m+j*n)+last);
			*((m+j*n)+last) = temp;
		}
		last--;
	}
	//print_matrix(m,n);
}


void solve()
{
	int n;
	cin>>n;
	
	int m[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
//	print_matrix(&m[0][0],n);
	rotateMatrix(&m[0][0],n);
	print_matrix(&m[0][0],n);
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



