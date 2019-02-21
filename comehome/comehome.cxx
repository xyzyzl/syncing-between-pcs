/**
ID: albert.28
LANG: C++14
PROB: comehome
**/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 55

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)

#define mp make_pair
#define pb push_back
#define	ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second

int p;
int adj_mat[MAXN][MAXN];
int main()
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	apple();
	cin >> p;
	FOR(0, i, 55)
	{
		FOR(0, j, 55)
			adj_mat[i][j] = INF;
		adj_mat[i][i] = 0;
	}
	FOR(0, i, p)
	{
		char a, b;
		int d;
		cin >> a >> b >> d;
		if(a >= 'a')
		{
			a = a-'a'+26;
		} else
		{
			a = a-'A';
		}
		if(b >= 'a')
		{
			b = b-'a'+26;
		} else
		{
			b = b-'A';
		}
		adj_mat[a][b] = adj_mat[b][a] = min(adj_mat[a][b], d);
	}
	FOR(0, k, 53)
	{
		FOR(0, i, 53)
		{
			FOR(0, j, 53)
			{
                if(adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j])
					adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
			}
		}
	}
	int mn = INT_MAX, minind = 0;
	FOR(0, i, 25)
	{
		if(mn > adj_mat[i][25])
			minind = i;
		mn = min(mn, adj_mat[i][25]);
	}
	cout << (char)(minind+'A') << " " << mn << '\n';
}
