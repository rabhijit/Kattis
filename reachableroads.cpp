#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> al;
vector<int> visited;

void bfs(int i) {
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while (q.size() != 0) {
        int u = q.front(); q.pop();
        for (auto &k : al[u]) {
            if (!visited[k]) {
                q.push(k);
                visited[k] = 1;
            }
        }
    }
}

int main() {
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++) {
        int cities; cin >> cities;
        al.assign(cities, vector<int>());
        visited.assign(cities, 0);
        int endpoints; cin >> endpoints;
        for (int j = 0; j < endpoints; j++) {
            int x, y; cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        int additions = 0;
        for (int i = 0; i < cities; i++) {
            if (!visited[i]) {
                additions++;
                bfs(i);
            }
        }
        cout << additions - 1 << endl;
    }
}