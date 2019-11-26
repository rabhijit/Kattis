#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    int number;
    cin >> number;
    string answers[number];
    float no1, no2, no3;
    for (int i = 0; i < number; i++) {
        cin >> no1 >> no2 >> no3;
        if ((no1 + no2 == no3) || (abs(no1 - no2) == no3) || (no1 / no2 == no3) || (no2 / no1 == no3) || (no1 * no2 == no3)) {
            answers[i] = "Possible";
        }
        else {
            answers[i] = "Impossible";
        }
    }
    for (int j = 0; j < number; j++) {
        cout << answers[j] << endl;
    }


}