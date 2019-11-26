#include <bits/stdc++.h>
using namespace std;

int main() {
	string command;
	unordered_map<string, int> variables;
	while (cin >> command) {
		if (command == "define") {
			int x;
			string var_name;
			cin >> x >> var_name;
			variables[var_name] = x;		
		}
		else if (command == "eval") {
			string var1, var2;
			char operate;
			cin >> var1 >> operate >> var2;
			if (variables.find(var1) == variables.end() || variables.find(var2) == variables.end()) {
				cout << "undefined" << "\n";
			}
			else if (operate == '<') {
				if (variables[var1] < variables[var2]) {
					cout << "true" << "\n";
				}
				else {
					cout << "false" << "\n";
				}
			}
			else if (operate == '=') {
				if (variables[var1] == variables[var2]) {
					cout << "true" << "\n";
				}
				else {
					cout << "false" << "\n";
				}
			}
			else if (operate == '>') {
				if (variables[var1] > variables[var2]) {
					cout << "true" << "\n";
				}
				else {
					cout << "false" << "\n";
				}
			}
		}
	}
}
