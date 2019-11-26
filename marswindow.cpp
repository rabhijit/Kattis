#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int year;
    cin >> year;
    int minimum = (year - 2018) * 12 - 4;
    int maximum = minimum + 12;
    bool check = false;
    for (int i = minimum + 1; i <= maximum; i++) {
        if (i % 26 == 0) {
            check = true;
        }
    }
    if (check == true && year >= 2018 && year <= 10000) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}

// 116 to 128
// take (year - 2018) * 12 - 4
// that is minimum no of months; max is that + 12
// if no mult. of 26 within min to max; none that year