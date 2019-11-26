#include <iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    if (input <= 3) {
        cout << 1;
    }
    else {
        cout << input - 2 << endl;
    }

}