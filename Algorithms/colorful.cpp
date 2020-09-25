#include<bits/stdc++.h>

using namespace std;

#define NextLine() { char c = getchar(); while (c != 10 && c != EOF) { c = getchar(); } }

const int MOD = 100000007;

int n1, n2, k1, k2;

void Load()
{
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
}

int res[110][110][2];

int Count(int n1, int n2, int f)
{
	if (res[n1][n2][f] != -1)
	{
		return res[n1][n2][f];
	}
	if (n1 + n2 == 0)
	{
		res[n1][n2][f] = 1 % MOD;
		return res[n1][n2][f];
	}
	int j;
	res[n1][n2][f] = 0;
	if (f == 0)
	{
		for (j = 1; j <= min(n1, k1); j++)
		{
			res[n1][n2][f] += Count(n1 - j, n2, 1 - f);
			res[n1][n2][f] %= MOD;
		}
	}
	else
	{
		for (j = 1; j <= min(n2, k2); j++)
		{
			res[n1][n2][f] += Count(n1, n2 - j, 1 - f);
			res[n1][n2][f] %= MOD;
		}
	}
	return res[n1][n2][f];
}

void Solve()
{
	memset(res, 0xFF, sizeof(res));
	printf("%d", (Count(n1, n2, 0) + Count(n1, n2, 1)) % MOD);
}

int main()
{
	Load();
	Solve();
	return 0;
}
