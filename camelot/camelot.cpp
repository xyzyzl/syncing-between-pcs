/*
ID: albert.28
LANG: C++14
PROB: camelot
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int C, R, c;
char r;
// bool vis[32][32][32][32];
int dist[32][32][32][32];
pii king;
vector<pii> knight;
int king_dist(int i, int j)
{
	return max(abs(king.f-i), abs(king.s-j));
}
int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	cin >> R >> C;
	cin >> r >> c;
	king.s = r-'A';
	king.f = c-1;

	while(cin >> r >> c)
	{
		r -= 'A';
		c--;
		knight.push_back(make_pair(c, r));
	}

	if(knight.size() == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	
	memset(dist, 1, sizeof(dist));

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
		{
			queue<pii> q;
			q.push(make_pair(i, j));
			dist[i][j][i][j] = 0;
			// vis[i][j][i][j] = 1;
			while(!q.empty())
			{
				pii p = q.front();
				q.pop();
				// vis[p.f][p.s][i][j] = 1;
				for(int e = 0; e < 8; e++)
				{
					int nf = p.f + dx[e];
					int ns = p.s + dy[e];
					if(nf >= 0 && nf < R && ns >= 0 && ns < C && dist[nf][ns][i][j] == 0x01010101)
					{
						dist[nf][ns][i][j] = dist[p.f][p.s][i][j]+1;
						q.push(make_pair(nf, ns));
					}
				}
			}
		}

	// cout << "here" << endl;
	int mn = (1 << 25);
	int sx = king.f - 1 < 0 ? 0 : king.f - 1;
	int sy = king.s - 1 < 0 ? 0 : king.s - 1;
	int ex = king.f + 1 >= R ? R-1 : king.f + 1;
	int ey = king.s + 1 >= C ? C-1 : king.s + 1;
	for(int i1 = 0; i1 < R; i1++)
	{
		for(int j1 = 0; j1 < C; j1++)
		{
			int sum = 0;
			for(pii k : knight)
			{
				int i = k.f, j = k.s;
				sum += dist[i][j][i1][j1];
			}
			int mi = max(abs(king.f-i1), abs(king.s-j1));
			for(int i2 = sx; i2 < ex; i2++)
			{
				for(int j2 = sy; j2 < ey; j2++)
				{
					for(pii k : knight)
					{
						int i = k.f, j = k.s;
						mi = min(mi, dist[i2][j2][i][j] + dist[i2][j2][i1][j1] + max(abs(king.f-i2), abs(king.s-j2)) - dist[i1][j1][i][j]);
					}
				}
			}
			mn = min(mn, sum + mi);
		}
	}
	cout << mn << endl;
}

