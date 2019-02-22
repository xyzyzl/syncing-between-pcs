/**
ID: albert.28
LANG: C++14
PROB: jongmah
**/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;

void fileio(char* in, char* out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}

/**
Modded operations
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-%20Math%20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/
namespace modOp
{
	int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
	int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
	int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }

	int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
	int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
	int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }

	int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
	int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }

	int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
		if (a == 0) return b == 1 ? 0 : -1;
		int x = invGeneral(b%a,a);
		return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
	}
}

using namespace modOp;

int n,m,cnt[MAXN];
ll mx,dp[2][3][3];

void subst()
{
	FOR(0, a, 3)
		FOR(0, b, 3)
		{
			dp[0][a][b] = dp[1][a][b];
			mx = max(mx, dp[0][a][b]);
			dp[1][a][b] = -LL_INF;
		}
}

int main()
{
	apple();
	hentai();
	cin >> n >> m;
	FOR(0, i, n)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	FOR(1, a, 2)
		FOR(0, i, 3)
			FOR(0, j, 3)
				dp[a][i][j] = -LL_INF;
	dp[0][0][0] = 0;
	FOR(1, a, m+1)
	{
		FOR(0, i, 3)
			FOR(0, j, 3)
				FOR(0, k, 3)
				{
					if(cnt[a] < i+j+k || cnt[a+1] < j+k || cnt[a+2] < k)
						continue;
					dp[1][j][k] = max(dp[1][j][k], dp[0][i][j] + k + (cnt[a]-i-j-k) / 3)	;
				}
		subst();
	}
	cout << mx << endl;
}