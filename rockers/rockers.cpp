/*
USER: albert.28
TASK: rockers
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;
#define MAXN 20

int n, t, m, dates[MAXN];
int main()
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	cin >> n >> t >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> dates[i];
	}
	int mx = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		int tot = 0, ct = 0, aa = 0, h = 0;
		bool flag = 0;
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				aa++;
				tot += dates[j];
				if(dates[j] > t)
				{
					flag = 1;
					break;
				}
				if(tot > t)
				{
					ct++;
					tot -= dates[j];
					if(ct == m)
					{
						flag = 1;
						break;
					}
					// switch disks
					tot = dates[j];
					// ct++;
				}
			}
		}
		if(!flag)
		{
			mx = max(mx, aa);
		}
	}
	cout << mx << endl;
}
