/*
USER: albert.28
LANG: C++14
PROB: heritage
*/

#include <bits/stdc++.h>

using namespace std;

int searchin(char n[], int x, int len)
{
	for(int i = 0; i < len; i++)
		if(n[i] == x)
			return i;
	return -1;
}

void print_po(char n[], char r[], int len)
{
	int root = searchin(n, r[0], len);
	if(root != 0)
	{
		print_po(n, r+1, root);
	}
	if(root != len-1)
	{
		print_po(n+root+1, r+root+1, len-root-1);
	}
	cout << r[0];
}

int main()
{
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);

	string _in, _pr;
	cin >> _in >> _pr;
	char in[_in.length()], pr[_pr.length()];
	for(int i = 0; i < _in.length(); i++)
	{
		in[i] = _in[i];
		pr[i] = _pr[i];
	}
	print_po(in, pr, _in.length());
	printf("\n");
}
