#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int companies, requests;
    cin >> companies >> requests;
    int locations[companies];
    for (int j = 0; j < companies; j++) {
        cin >> locations[j];
    }
    int answers[requests];
    int command, a, b;
    int requests_fulfilled = 0;
    for (int i = 0; i < requests; i++) {
        cin >> command >> a >> b;
        if (command == 1) {
            locations[a-1] = b;
        }
        else if (command == 2) {
            answers[requests_fulfilled] = abs(locations[a-1] - locations[b-1]);
            requests_fulfilled++;
        }
    }
    for (int k = 0; k < requests_fulfilled; k++) {
        cout << answers[k] << endl;
    }
}