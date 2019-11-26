#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int number;
    cin >> number;
    int values[number];
    int results[number];
    for (int i = 0; i < number; i++) {
        cin >> values[i];
    }
    for (int j = 0; j < number; j++) {
        if (values[j] < 5) {
            results[j] = (factorial(values[j]) % 10);
        }
        else {
            results[j] = 0;
        }
    }
    for (int k = 0; k < number; k++) {
        cout << results[k] << endl;
    }

}