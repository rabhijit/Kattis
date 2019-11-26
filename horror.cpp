#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj_list;
vector<int> dist;
vector<int> horrors;

void bfs(int s) {
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto &i : adj_list[v]) {
            if (dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int no_movies, horror_movies, no_similar; cin >> no_movies >> horror_movies >> no_similar;
    dist.clear(); dist.assign(no_movies, 1e9);
    for (int i = 0; i < horror_movies; i++) {
        int x; cin >> x; dist[x] = 0;
        horrors.push_back(x);
    }
    for (int j = 0; j < no_similar; j++) {
        int y, z; cin >> y >> z;
        adj_list[y].insert(z); adj_list[z].insert(y);
    }
    for (int k = 0; k < horrors.size(); k++) {
        bfs(horrors[k]);
    }
    cout << (max_element(dist.begin(), dist.end()) - dist.begin()) << endl;

}