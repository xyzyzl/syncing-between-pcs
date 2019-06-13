// D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

const int MAXN = (int)(1e5+5);

using namespace std;

int n, m;
vector<int> adj_lst[MAXN];
priority_queue<int, vector<int>, greater<int> > pq; // sorted in increasing order

bool vis[MAXN];

void traverse() {
	while (!pq.empty()) {
		int t = pq.top();
		vis[0] = true;
		pq.pop();
		cout << (t + 1) << " ";
		for (int nx : adj_lst[t]) {
			if (!vis[nx]) {
				pq.push(nx);
				vis[nx] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		adj_lst[v1].push_back(v2);
		adj_lst[v2].push_back(v1);
	}
	pq.push(0);
	traverse();
	cout << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
