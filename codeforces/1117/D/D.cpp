// D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

#define ll long long

#define MOD (int)(1e9+7)
#define MAXM 105

using namespace std;

typedef vector<vector<ll> > matrix;

ll n;
int m;
vector<ll> coeff;

matrix mult(matrix a, matrix b) {
	matrix prod = matrix(m + 1, vector<ll>(m + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				prod[i][j] = (prod[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return prod;
}

matrix exp(matrix a, ll p) {
	if (p == 1) {
		return a;
	}
	if (p % 2) {
		return mult(a, exp(a, p - 1));
	}
	matrix x = exp(a, p / 2);
	return mult(x, x);
}

int main() {
	cin >> n >> m;
	coeff = vector<ll>(m + 1);
	coeff[1] = 1;
	coeff[m] = 1;
	if (n < m)
		cout << 1 << endl;
	else {
		matrix end = matrix(m + 1, vector<ll>(m + 1));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				end[i][j] = 0;
			}
		}
		for (int i = 2; i <= m; i++) {
			end[i][i - 1] = 1;
		}
		end[1][m] = end[m][m] = 1;
		end = exp(end, n);
		ll best = 0;
		for (int i = 1; i <= m; i++) {
			best = (best + end[1][i] * coeff[i]) % MOD;
		}
		cout << best << endl;
	}
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
