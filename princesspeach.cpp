#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int number, found;
    cin >> number >> found;
    int found_obstacles[found];
    for (int i = 0; i < found; i++) {
        cin >> found_obstacles[i];
    }
    bool check = false;
    int true_found = 0;
    for (int j = 0; j < number; j++) {
        for (int k = 0; k < found; k++) {
            if (j == found_obstacles[k]) {
                check = true;
            }
        }
        if (check != true) {
            cout << j << endl;
        }
        else {
            check = false;
            true_found++;
        }
    }
    cout << "Mario got " << true_found << " of the dangerous obstacles." << endl;
}