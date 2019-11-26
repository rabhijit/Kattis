#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> adj_list;
map<string, bool> escape;
map<string, int> visited;

void dfs(string s) {
    visited[s] = 1;
    if (adj_list[s].empty()) {
        escape[s] = false;
    }
    for (auto &i : adj_list[s]) {
        if (visited[i] == 0) {
            dfs(i);
            if (escape[i] == true) {
                escape[s] = true;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    string from, to;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        escape[from] = true;
        escape[to] = true;
        visited[from] = 0;
        visited[to] = 0;
        adj_list[from].insert(to);
    }
    dfs(from);

}