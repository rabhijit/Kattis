#include <bits/stdc++.h>
using namespace std;




int main() {
    int n, k; cin >> n >> k;
    int count = 0;
    if (n < k) {
        cout << n - 1 << endl;
    }
    else {
        count += ((n-1) % k);
        cout << count + 1 + k << endl;
    }

}
