#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    char area[r+7][c+7];
    for (int i = 0; i < r; i++) {
        cin >> area[i];
    }
    int r1, c1;
    r1 = 0;
    c1 = 0;
    int count = 0;
    bool fail = false;

    while (area[r1][c1] != 'T') {
        if ((r1 >= r) || (r1 < 0) || (c1 >= c) || (c1 < 0)) {
            cout << "Out" << endl;
            fail = true;
            break;
        }
        if (count >= ((r * c) - 1)) {
            cout << "Lost" << endl;
            fail = true;
            break;
        }
        count++;
        if (area[r1][c1] == 'N') {
            r1--;
        }
        else if (area[r1][c1] == 'S') {
            r1++;
        }
        else if (area[r1][c1] == 'W') {
            c1--;
        }
        else if (area[r1][c1] == 'E') {
            c1++;
        }
    }
    if (fail == false) {
        cout << count << endl;
    }

}