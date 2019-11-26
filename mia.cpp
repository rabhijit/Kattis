#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int mia(int s0, int s1, int r0, int r1) {
    int n0 = stoi(to_string(max(s0, s1)) + to_string(min(s0, s1)));
    int n1 = stoi(to_string(max(r0, r1)) + to_string(min(r0, r1)));
    if (n0 == 0 && n1 == 0) {
        return -1;
    }
    else if (n0 == n1) {
        return 0;
    }
    else if (n0 == 21 || n1 == 21) {
        if (n0 == 21) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if ((n0 % 11 == 0) || (n1 % 11 == 0)) {
        if ((n0 % 11 == 0) && (n1 % 11 == 0)) {
            if (n0 > n1) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (n0 % 11 == 0) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        if (n0 > n1) {
            return 1;
        }
        else {
            return 2;
        }
    }

}

int main() {
    int s0, s1, r0, r1;
    int result = 0;
    int *list;
    list = (int*)malloc(1000000 * sizeof(int));
    int i = 0;
    while (result != -1) {
        cin >> s0 >> s1 >> r0 >> r1;
        result = mia(s0, s1, r0, r1);
        list[i] = result;
        i++;
    }
    i = 0;
    while (list[i] != -1) {
        if (list[i] > 0) {
            cout << "Player " << list[i] << " wins." << endl;
        }
        else if (list[i] == 0) {
            cout << "Tie." << endl;
        }
        i++;
    }
}