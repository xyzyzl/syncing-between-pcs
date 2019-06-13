// D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string s;
int n;

bool is_palindrome(string st) {
	for (int i = 0; i < n; i++) {
		if (st[i] != st[n - 1 - i])
			return false;
	}
	return true;
}

// call a string "boring" if all it does is repeat the same letter
// or, in the case of n%2==1, only one letter differs.
bool not_boring() {
	int num_different = 0; // from first char.
	for (int i = 1; i < n; i++) {
		num_different += (s[i] != s[0]);
	}
	return num_different > 1;
}

void shift_1(string &t) {
	t = t.back() + t;
	t.pop_back();
}

int main() {
	cin >> s;
	n = s.length();

	// decide whether you can one split or not
	bool one_split = 0;
	string t = s;
	for (int i = 0; i < n; i++) {
		shift_1(t);
		if (s != t && is_palindrome(t))
			one_split = 1;
	}

	if (!not_boring())
		cout << "Impossible" << endl;
	else
		cout << (one_split ? 1 : 2) << endl;
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
