/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>

using namespace std;

struct comparator {
    bool operator()(pair<string, int> x, pair<string, int> y) {
        if (x.second == y.second) {
            return (x.first > y.first);
        }
        else {
            return (y.second > x.second);
        }
    }
};

int main() {
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++) {
        int lines; cin >> lines;
        unordered_map<string, int> inventory;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator > sorted;
        for (int j = 0; j < lines; j++) {
            string toy;
            int amount;
            cin >> toy >> amount;
            inventory[toy] += amount;
        }
        for (auto it = inventory.begin(); it != inventory.end(); it++) {
            sorted.push(make_pair(it->first, it->second));
        }
        for (int k = 0; k < inventory.size(); k++) {
            if (k == 0) {
                cout << inventory.size() << endl;
            }
            cout << sorted.top().first << " " << sorted.top().second << "\n";
            sorted.pop();
        }

    }

}
