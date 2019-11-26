#include <bits/stdc++.h>
using namespace std;

int calculator(int start) {
    unordered_map<int, int> values;
    int count = 0;
    int x = start;
    while (values[x] == 0) {
        int new_val = (x * x) % 1000;
        cout << new_val << endl;
        values[x] = new_val;
        x = new_val;
        count++;
    }
    return count;
}

int main() {
    cout << calculator(2) << endl;
}