#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

#define MAXN 100005

using namespace std;

typedef pair<int, int> pii;

int n, pickup;
int arr[MAXN];
vector<pii> v;
set<int> covered;
int main() {
	// freopen("dishes.in", "r", stdin);
	// freopen("dishes.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max_int = -1, ohgod = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < ohgod) {
			// cout << arr[i] << " " << i << " " << ohgod << endl;
			cout << i << endl;
			return 0;
		}
		covered.insert(arr[i]);
		// cout << "dish label: " << arr[i] << endl;
		if (max_int < arr[i]) {
			max_int = arr[i];
			v.push_back(make_pair(arr[i], -1));
			// cout << "y" << endl;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), make_pair(arr[i], -1));
			// cout << it->first << endl;
			if (it->second == -1) {
				it->second = arr[i];
			}
			else {
				if (arr[i] > it->second) {
					// cout << it->second << endl;
					ohgod = *(--covered.lower_bound(arr[i]));
				}
				it->second = min(it->second, arr[i]); // the min that we can stack on here
			}
		}
	}
	cout << n << endl;
}