#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, int> variables;
	vector<pair<string, string>> answers;
	string input;
	while (getline(cin, input)) {
		stringstream ss(input);
		string filtered_input;
		string command;
		string vars;
		string operate = "+";
		int operand1 = 0;
		int operand2 = 0;
		int answer;
		int counter = 0;
		while (getline(ss, filtered_input, ' ')) {
			if (counter == 0) {
				command = filtered_input;
				if (command == "clear") {
					variables.clear();
				}
			}
			else {
				if (command == "def") {
					if (counter == 1) {
						vars = filtered_input;
					}
					else {
						variables[vars] = stoi(filtered_input);
					}
				}
				else if (command == "calc") {
					vars += filtered_input;
					vars += " ";
					if (counter % 2 != 0) {
						if (operand1 == 0 && variables.find(filtered_input) != variables.end()) {
							operand1 = variables[filtered_input];
						}
						else if (operand2 == 0 && variables.find(filtered_input) != variables.end()) {
							operand2 = variables[filtered_input];
						}
						else if (variables.find(filtered_input) == variables.end()) {
							operand1 = -2000;
							operand2 = -10000;
						}
					}
					else {
						if (operate == "+") {
							answer = operand1 + operand2;
						}
						else if (operate == "-") {
							answer = operand1 - operand2;
						}
						operate = filtered_input;
						operand1 = answer;
						operand2 = 0;
					}
				}
			}
			counter++;		
		}
		if (command == "calc") {
			if (answer > 1000 || answer < -1000) {
				answers.push_back({vars, "unknown"});
			}
			else {
				string finally = "-1";
				for (auto it = variables.begin(); it != variables.end(); it++) {
					if (it->second == answer) {
						finally = it->first;
						break;
					}
				}
				if (finally != "-1") {
					answers.push_back({vars, finally});
				}
				else {
					answers.push_back({vars, "unknown"});
				}
			}
		}
		
	}
	for (auto it = answers.begin(); it != answers.end(); it++) {
		cout << it->first << it->second << "\n";
	}
}
