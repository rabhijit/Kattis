/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    while (cin >> cases) {
        if (cases == 0) {
            break;
        }
        vector<pair<string, string>> times;
        for (int i = 0; i < cases; i++) {
            string number, ampm;
            cin >> number >> ampm;
            stringstream ss1(number);
            string dummy, final_number;
            int counter = 0;
            while (getline(ss1, dummy, ':')) {
                if (!(dummy == "12" && counter == 0)) {
                    final_number += dummy;
                }
                counter++;
            }
            //cout << final_number << " " << ampm[0] << endl;
            if (ampm[0] == 'a') {
                times.push_back(make_pair(final_number, "am"));
            }
            else {
                times.push_back(make_pair(final_number, "pm"));
            }
        }
        sort(times.begin(), times.end(), [](pair<string, string> p1, pair<string, string> p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }
            else {
                return stoi(p1.first) < stoi(p2.first);
            }
        });
        for (int j = 0; j < times.size(); j++) {
            if (times[j].first.length() == 2) {
                cout << "12";
            }
            for (int k = 0; k < times[j].first.length(); k++) {
                if (k == times[j].first.length() - 2) {
                    cout << ":";
                }
                cout << times[j].first[k];
            }
            cout << " ";
            if (times[j].second == "am") {
                cout << "a.m.";
            }
            else {
                cout << "p.m.";
            }
            cout << endl;
        }
    }

}
