/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int trips; cin >> trips;
    map<string, vector<int>> travels;
    for (int i = 0; i < trips; i++) {
        string place;
        int year;
        cin >> place >> year;
        travels[place].push_back(year);
    }
    for (auto it = travels.begin(); it != travels.end(); it++) {
        sort((it->second).begin(), (it->second).end());
    }
    int queries; cin >> queries;
    for (int j = 0; j < queries; j++) {
        string country;
        int order;
        cin >> country >> order;
        cout << travels[country][order-1] << endl;
    }

}
