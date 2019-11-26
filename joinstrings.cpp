#include <bits/stdc++.h>
using namespace std;

// list splice fn

int main() {
    ios::sync_with_stdio();
    int n; cin >> n;
    map<int, list<char>> words;
    for (int i = 1; i <= n; i++) {
        string input; cin >> input;
        list<char> real_input;
        for (int k = 0; k < input.length(); k++) {
            real_input.push_back(input[k]);
        }   
        words[i] = real_input;
    }
    for (int j = 0; j < n-1; j++) {
        int no1, no2; cin >> no1 >> no2;
        words[no1].splice(words[no1].end(), words[no2]);
        words.erase(no2);
    }
    for (auto it = words.begin(); it != words.end(); it++) {
        for (auto it2 = (it->second).begin(); it2 != (it->second).end(); it2++)
            cout << *it2;
    }
}