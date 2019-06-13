/**
ID: albert.28
LANG: C++14
PROB: Gourmet Choice
**/

#include "pch.h" // comment when submitting
#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-%20Math%20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 2005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define ll long long
// #define int ll
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef set<int> si;
typedef map<int, int> mi;
#define ff first
#define ss second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;
typedef queue<int> qii;

namespace modOp
{
	int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
	int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
	int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }

	int AD(int& a, int b, int mod = MOD) { return a = ad(a, b, mod); }
	int SUB(int& a, int b, int mod = MOD) { return a = sub(a, b, mod); }
	int MUL(int& a, int b, int mod = MOD) { return a = mul(a, b, mod); }

	int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
	int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

	int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
		if (a == 0) return b == 1 ? 0 : -1;
		int x = invGeneral(b%a, a);
		return x == -1 ? -1 : ((1 - (ll)b*x) / a + b) % b;
	}
}

using namespace modOp;

int n, m, cc[MAXN], indeg[MAXN], ndeg[MAXN]; // cc is which connected component this node is in
// indeg is the indegree of each node
char mat[MAXN][MAXN];
vi v[MAXN], eq[MAXN];

void flood(int i, int id, int p) {
	if (cc[i] >= 0)
		return;
	cc[i] = id;
	for (int nx : eq[i]) {
		if (nx == p)
			continue;
		flood(nx, id, i);
	}
}

int main() {
	apple();
	hentai();
	// freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
	cin >> n >> m;
	fill(cc, cc + n + m, -1);
	FOR(0, i, n) {
		FOR(0, j, m) {
			cin >> mat[i][j];
			if (mat[i][j] == '=') {
				eq[i].pb(n + j);
				eq[n + j].pb(i);
			}
		}
	}
	int ct = 0;
	FOR(0, i, n+m) {
		if (!(cc[i] + 1)) {
			flood(i, i, -1);
			ct++;
		}
	}

	FOR(0, i, n) {
		FOR(0, j, m) {
			if (mat[i][j] == '=')
				continue;
			if (cc[i] == cc[n + j]) {
				// this is a contradiction
				cout << "No" << endl;
				return 0;
			}
			if (mat[i][j] == '<') {
				v[cc[i]].pb(cc[n + j]);
				indeg[cc[n + j]]++;
			} else {
				v[cc[n + j]].pb(cc[i]);
				indeg[cc[i]]++;
			}
		}
	}
	qi q;
	FOR(0, i, n + m) {
		if (indeg[i] == 0 && cc[i] == i)
			q.push(i);
	}
	int cur = 1;
	while (!q.empty()) {
		qi q2 = q;
		while (q.size()) {
			int x = q.front(); q.pop();
			ndeg[x] = cur;
		}
		cur++;
		while (q2.size()) {
			int x = q2.front(); q2.pop();
			for (int nx : v[x]) {
				indeg[nx]--;
				if (indeg[nx] == 0)
					q.push(nx);
			}
		}
	}
	FOR(0, i, n) {
		if (ndeg[i] == 0 && cc[i] == i) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	FOR(0, i, n) {
		cout << ndeg[cc[i]] << " ";
	}
	cout << endl;
	FOR(0, i, m) {
		cout << ndeg[cc[n + i]] << " ";
	}
	cout << endl;
}