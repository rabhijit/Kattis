#include <bits/stdc++.h>
using namespace std;

int main() {
	int sets; cin >> sets;
	for (int i = 0; i < sets; i++) {
		int teams; cin >> teams;
		priority_queue<int> scores;
		for (int j = 0; j < 3 * teams; j++) {
			int input; cin >> input;
			scores.push(input);
		}
		int sum;
		for (int k = 0; k < 2 * teams; k++) {
			if (k % 2 != 0) {
				sum += scores.top();
			}
			scores.pop();
		}
		cout << sum << "\n";
	}
}
