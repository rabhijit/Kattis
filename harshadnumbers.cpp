#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sum_of_digits(int number) {
    string str_number = to_string(number);
    int sum_digits = 0;
    for (int i = 0; i < str_number.length(); i++) {
        sum_digits += ((int)str_number[i] - 48);
    }
    return sum_digits;
}

int main() {
    int limit;
    cin >> limit;
    while (1) {
        if (limit % sum_of_digits(limit) == 0) {
            cout << limit << endl;
            break;
        }
        else {
            limit++;
        }
    }
}