/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases; cin >> cases;
    vector<string> results;
    for (int i = 0; i < cases; i++) {
        string commands; cin >> commands;
        int number; cin >> number;
        deque<string> numbers;
        string input; cin >> input;
        string next_integer = "";
        for (int m = 0; m < input.length(); m++) {
            if (input[m] != '[' && input[m] != ']' && input[m] != ',') {
                while (input[m] != ',' && input[m] != ']') {
                    next_integer.push_back(input[m]);
                    m++;
                }
                numbers.push_back(next_integer);
                next_integer = "";
            }
        }
        int reverse = 0;
        bool error = false;
        for (int k = 0; k < commands.length(); k++) {
            if (commands[k] == 'D') {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    if (reverse == 0) {
                        numbers.pop_front();
                    }
                    else {
                        numbers.pop_back();
                    }
                }
            }
            else if (commands[k] == 'R') {
                reverse = 1 - reverse;
            }
        }
        string final_str;
        if (error) {
            final_str = "error";
        }
        else {
            final_str += '[';
            if (reverse == 0) {
                for (int l = 0; l < numbers.size(); l++) {
                    final_str += numbers[l];
                    if (l != numbers.size() - 1) {
                        final_str += ',';
                    }
                }
            }
            else {
                for (int l = numbers.size() - 1; l >= 0; l--) {
                    final_str += numbers[l];
                    if (l != 0) {
                        final_str += ',';
                    }
                }
            }
            final_str += ']';
        }
        results.push_back(final_str);
    }
    for (int n = 0; n < results.size(); n++) {
        cout << results[n] << endl;
    }
}