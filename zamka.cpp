#include <iostream>
#include <string>
using namespace std;

int main() {
    int l, d, x, counter;
    cin >> l >> d >> x;
    int numbers[d-l];
    counter = 0;
    for (int i = l; i <= d; i++) {
        int sum = 0;
        string string_number = to_string(i);
        for (int j = 0; j < string_number.size(); j++) {
            sum += (int)(string_number[j]) - 48;
        }
        if (sum == x) {
            numbers[counter] = i;
            counter++;
        }
    }
    cout << numbers[0] << endl;
    cout << numbers[counter-1] << endl;

}