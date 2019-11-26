#include <iostream>
#include <string>
using namespace std;

int main() {
    int capacity, booked;
    cin >> capacity >> booked;
    int booked_rooms[booked];
    for (int i = 0; i < booked; i++) {
        cin >> booked_rooms[i];
    }
    bool avail;
    for (int j = 1; j <= capacity; j++) {
        avail = true;
        for (int k = 0; k < booked; k++) {
            if (j == booked_rooms[k]) {
                avail = false;
            }
        }
        if (avail == true) {
            cout << j << endl;
            break;
        }
    }
    if (avail == false) {
        cout << "too late" << endl;
    }

}

