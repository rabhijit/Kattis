/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases; cin >> cases;
    vector<long> ans;
    for (int i = 0; i < cases; i++) {
        int guest_number; cin >> guest_number;
        unordered_set<int> guests;
        for (int j = 0; j < guest_number; j++) {
            long input; cin >> input;
            if (guests.find(input) == guests.end()) {
                guests.insert(input);
            }
            else {
                guests.erase(input);
            }
        }
        ans.push_back(*guests.begin());
    }
    for (int i = 1; i <= ans.size(); i++) {
        cout << "Case #" << i << ": " << ans[i-1] << endl;
    }
}
