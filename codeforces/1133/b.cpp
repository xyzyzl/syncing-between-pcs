#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define MAX 105

int n, k, d[MAXN];
vector<int> compat[MAX];
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i];
		d[i] %= k;
		if(d[i] == 0)
			compat[0].push_back(d[i]);
		else
			compat[k-d[i]].push_back(d[i]);
	}
	int ct = 0;
	for(int i = 0; i <= k/2; i++)
	{
		ct += compat[i].size();
	}
	cout << ct << endl;
}