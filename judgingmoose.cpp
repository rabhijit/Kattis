#include <iostream>
#include <algorithm>
using namespace std;

int judgingmoose(int l, int r) {
    if (l == r) {
        return l + r;
    }
    else {
        return 2 * max(l, r);
    }
}

int main() {
    int l, r;
    cin >> l >> r;
    if ((l == 0) && (r == 0)) {
        cout << "Not a moose" << endl;
    }
    else if (l != r) {
        cout << "Odd " << judgingmoose(l, r) << endl;
    }
    else {
        cout << "Even " << judgingmoose(l, r) << endl;
    }
}