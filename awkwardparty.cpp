/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int number; cin >> number;
    unordered_map<int, int> guests;
    int level = number;
    for (int i = 0; i < number; i++) {
        int input; cin >> input;
        if (guests.find(input) != guests.end()) {
            if ((i - guests[input]) < level) {
                level = i - guests[input];
            }
        }
        guests[input] = i;
    }
    cout << level << "\n";

}
