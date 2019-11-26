/*
A0181059A
Abhijit Ravichandran
(no lab group assigned yet)
(no TA)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> logs;
    vector<string> indiv_log;
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            indiv_log.push_back(line);
        }
        else if (line.empty()) {
            logs.push_back(indiv_log);
            indiv_log.clear();
        }
    }
    logs.push_back(indiv_log);

    vector<vector<int>> log_of_positions;
    for (int k = 0; k < logs.size(); k++) {
        vector<int> positions(logs.at(k).size(), 0);
        for (int i = 0; i < logs.at(k).size(); i++) {
            for (int j = 0; j < (logs.at(k).at(0).length()); j++) {
                if (logs.at(k).at(i).at(j) == '*') {
                    positions.at(i) += 1;
                }
            }
        }
        log_of_positions.push_back(positions);
    }
    for (int m = 0; m < log_of_positions.size(); m++) {
        int counter = logs.at(m).at(0).size();
        for (int n = 0; n < log_of_positions.at(m).size(); n++) {
            counter -= (log_of_positions.at(m).at(n));
            for (int p = 0; p <= logs.at(m).at(n).size(); p++) {
                if (p == counter) {
                    for (int q = 0; q < log_of_positions.at(m).at(n); q++) {
                        cout << "*";
                        p++;
                    }
                }
                else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}
