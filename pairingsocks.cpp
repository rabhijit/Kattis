#include <bits/stdc++.h>
using namespace std;

int main() {
    int pairs; cin >> pairs;
    deque<int> original;
    deque<int> auxiliary;
    int resolved_pairs = 0;
    int counter = 0;
    for (int i = 0; i < 2 * pairs; i++) {
        int input; cin >> input;
        original.push_back(input);
    }
    for (int j = 0; j < 2 * pairs; j++) {
        if (auxiliary.size() == 0 || auxiliary[0] != original[0]) {
            auxiliary.push_front(original[0]);
            original.pop_front();
            counter++;
        }
        else if (auxiliary[0] == original[0]) {
            auxiliary.pop_front();
            original.pop_front();
            resolved_pairs++;
            counter++;
        }
    }
    if (resolved_pairs != pairs) {
        cout << "impossible" << "\n";
    }
    else {
        cout << counter << "\n";
    }
}
