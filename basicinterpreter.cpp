/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

struct statement {
    int number;
    string command;
    string details;
};

struct comparator {
    bool operator()(struct statement &a, struct statement &b) {
        return a.number > b.number;
    }
};

template <typename T>
void parse_line(stringstream &ss, T &val) {
    string token;
    parse_line(ss, token);
    stringstream ss2(token);
    ss2 >> val;
}

template <>
void parse_line<string>(stringstream &ss, string &val) {
    getline(ss, val, 'x'); //Note the separator specification
}

int arithmetic_parser(string subcommand) {
    if (str.find("+") != string::npos) {
        if (subcommand.length() == 1) {
            return stoi(subcommand);
        }
        else {
            
        }
    }
}

// convert variable alphabet straight into integer

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> variables = {26, 0};
    priority_queue<statement, vector<statement>, comparator> all_statements;
    string input;
    while (getline(cin, input)) {
        int count = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ' ') {
                input[i] = 'x';
                count++;
            }
            if (count == 2) {
                break;
            }
        }
        int number; string command; string details;
        stringstream ss(input);
        parse_line(ss, number);
        parse_line(ss, command);
        parse_line(ss, details);
        statement x = {number, command, details};
        all_statements.push(x);
    }
    int counter = all_statements.size();
    vector<statement> finished_statements;
    while (counter > 0) {
        statement curr_statement = all_statements.top();
        finished_statements.push_back(curr_statement);
        if (curr_statement.command == 'LET') {
            char var = curr_statement.details[0];
            string subcommand = curr_statement.substr(4);
        }
    }


}
