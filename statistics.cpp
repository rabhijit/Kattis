#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases = 1;
    while (1) {
        int number, input;
        long maximum, minimum;
        maximum = -1000000;
        minimum = 1000000;
        cin >> number;
        if (cin.eof()) {
            break;
        }
        for (int i = 0; i < number; i++) {
            cin >> input;
            if (input > maximum) {
                maximum = input;
            }
            if (input < minimum) {
                minimum = input;
            }
        }
        cout << "Case " << cases << ": " << minimum << " " << maximum << " " << maximum - minimum << endl;
        cases++;
    }
}