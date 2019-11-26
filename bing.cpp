#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	unordered_map<string, int> letters;
	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		bool flag = true;
		string new_input = input;
		int counter = input.length();
		for (int j = 0; j < counter; j++) {
			letters[new_input]++;
			new_input.pop_back();
		}
		cout << letters[input] - 1 << endl;
	}
}
