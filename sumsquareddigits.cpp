#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string base_convert(int number, int base) {
    string result;
    string hex_chars[6] = {"A", "B", "C", "D", "E", "F"};
    while (number != 0) {
        if ((number % base) < 10) {
            result.insert(0, to_string(number % base));
        }
        else {
            result.insert(0, hex_chars[(number % base) % 10]);
        }
        number = number / base;
    }
    return result;
}

int main() {
    int length;
    int dustbin;
    cin >> length;
    int bases[length];
    int values[length];
    int converted[length];
    int result = 0;
    string converted_string;
    string hex_chars[6] = {"A", "B", "C", "D", "E", "F"};
    for (int i = 0; i < length; i++) {
        cin >> dustbin >> bases[i] >> values[i];
        converted_string = base_convert(values[i], bases[i]);
        for (int j = 0; j < converted_string.length(); j++) {
            if ((int)converted_string[j] - 48 < 10) {
                result += pow(((int)(converted_string[j]) - 48), 2);
            }
            else {
                for (int m = 0; m < 6; m++) {
                    if (converted_string[j] == hex_chars[m][0]) {
                        result += pow((m+10), 2);
                    }
                }
            }
        }
        converted[i] = result;
        result = 0;
    }
    for (int k = 0; k < length; k++) {
        cout << (k+1) << " " << converted[k] << endl;
    }
}