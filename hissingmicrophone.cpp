#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    bool hiss = false;
    for (int i = 0; i < (input.length() - 1); i++) {
        if (input[i] == 's' && input[i+1] == 's') {
            hiss = true;
        }
    }
    if (hiss == true) {
        cout << "hiss" << endl;
    }
    else {
        cout << "no hiss" << endl;
    }
}