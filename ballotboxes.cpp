/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cities, boxes;
    vector<int> results;
    while (cin >> cities && cin >> boxes && (cities != -1 && boxes != -1)) {
        priority_queue<pair<float, int>> populations;
        for (int i = 0; i < cities; i++) {
            int input; cin >> input;
            populations.push(make_pair(input, 1));
        }
        boxes -= populations.size();
        while (boxes > 0) {
            pair<float, int> max_element = populations.top();
            max_element.first = (max_element.first * max_element.second) / (max_element.second + 1);
            max_element.second++;
            boxes--;
            populations.pop();
            populations.push(max_element);
        }
        results.push_back(ceil(populations.top().first));
    }
    for (int k = 0; k < results.size(); k++) {
        cout << results[k] << "\n";
    }
}
