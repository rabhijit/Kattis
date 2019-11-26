#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj_list;
vector<int> original_degree;
vector<int> post_degree;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto &i : adj_list[v]) {
            adj_list[v].erase(i);
            adj_list[i].erase(v);
            post_degree[i]--;
            if (post_degree[i] <= original_degree[i] / 2) {
                q.push(i);
            }
        }
    }
}

int main() {
    int countries, pships, me, l; cin >> countries >> pships >> me >> l;
    original_degree.clear(); original_degree.assign(countries, 0);
    post_degree.clear(); post_degree.assign(countries, 0);
    for (int i = 0; i < pships; i++) {
        int x, y; cin >> x >> y;
        adj_list[x].insert(y); adj_list[y].insert(x);
        original_degree[x]++; original_degree[y]++;
        post_degree[x]++; post_degree[y]++;
    }
    post_degree[l] = 0;
    bfs(l);

    if (post_degree[me] <= original_degree[me] / 2) {
        cout << "leave" << endl;
    }
    else {
        cout << "stay" << endl;
    }

}