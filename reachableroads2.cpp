#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj_list;
vector<int> visited;

void dfs(int s) {
    visited[s] = 1;
    for (auto &i : adj_list[s]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int s) {
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        visited[v] = 1;
        for (auto &i : adj_list[v]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
}

int main() {
    int cities; cin >> cities;
    int endpoints; cin >> endpoints;
    int x; cin >> x;
    for (int i = 0; i < x; i++) {
        int y, z; cin >> y >> z;
        adj_list[y].insert(z);
        adj_list[z].insert(y);
    }
    visited.clear();
    visited.assign(endpoints, 0);
    int count = 0;
    for (int j = 0; j < endpoints; j++) {
        if (!visited[j]) {
            dfs(j);
            count++;
        }
    }
    cout << count -1 << endl;

}