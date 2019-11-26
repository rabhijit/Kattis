#include <bits/stdc++.h>
using namespace std;

map<int, set<pair<int, int>>> adj_list;
vector<int> distances;

void dijkstra(int s, int nodes) {
    set<pair<int, int>> vertices;
    vertices.insert(make_pair(0, s));
    for (int i = 0; i < nodes; i++) {
        if (i != s) {
            vertices.insert(make_pair(1e9, i));
        }
    }
    while (!vertices.empty()) {
        int curr_w = (*vertices.begin()).first;
        int curr_v = (*vertices.begin()).second;
        vertices.erase(vertices.begin());
        for (auto &[v, d] : adj_list[curr_v]) {
            if (curr_w + d < distances[v]) {
                vertices.erase({distances[v], v});
                distances[v] = curr_w + d;
                vertices.insert({distances[v], v});
            }
        }
    }
}

int main() {
    int nodes, edges, queries, s; cin >> nodes >> edges >> queries >> s;
    distances.clear(); distances.assign(nodes, 1e9); distances[s] = 0;
    for (int i = 0; i < edges; i++) {
        int from, to, weight; cin >> from >> to >> weight;
        adj_list[from].insert(make_pair(to, weight));
    }
    dijkstra(s, nodes);
    for (int j = 0; j < queries; j++) {
        int x; cin >> x;
        if (distances[x] == 1e9) {
            cout << "Impossible" << endl;
        }
        else {
            cout << distances[x] << endl;
        }
    }
}
