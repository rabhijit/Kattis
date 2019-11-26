/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list;
vector<int> buttons;

void search() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : buttons) {
            int selected = u + v;
            selected = min(3600, max(0, selected));
            if (adj_list[selected] > adj_list[u] + 1) {
                adj_list[selected] = adj_list[u] + 1;
                q.push(selected);
            }
        }
    }
}

int main() {
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++) {
        buttons.clear();
        adj_list.assign(3601, 1e9);
        adj_list[0] = 0;
        int number;
        int duration;
        cin >> number >> duration;
        for (int j = 0; j < number; j++) {
            int input; cin >> input;
            buttons.push_back(input);
        }
        search();
        for (int j = duration; j < 3601; j++) {
            if (adj_list[j] != 1e9) {
                cout << adj_list[j] << " " << j - duration << "\n";
                break;
            }
        }
    }
}




