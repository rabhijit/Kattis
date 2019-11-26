#include <bits/stdc++.h>
using namespace std;

int main() {
	int lines, characters; cin >> lines >> characters;
	int counter = 0;
	for (int i = 0; i < lines; i++) {
		char input;
		bool head = false;
		for (int j = 0; j < characters; j++) {
			cin >> input;
			if (i == 0) {
				if (input == '$' && head == false) {
					head = true;
					counter++;
				}
				else if (input == '_' && head == true) {
					head = false;
				}
			}
		}
	}
	cout << counter << "\n";
}
