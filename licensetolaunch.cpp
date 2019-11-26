#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int length;
    cin >> length;
    int days[length];
    for (int i = 0; i < length; i++) {
        cin >> days[i];
    }
    long long minimum = pow(10, 9);
    int location = 0;
    for (int j = 0; j < length; j++) {
        if (days[j] < minimum) {
            minimum = days[j];
            location = j;
        }
    }
    cout << location << endl;

}