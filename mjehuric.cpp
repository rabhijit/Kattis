#include <iostream>
#include <string>
using namespace std;

int main() {
    int piece1, piece2, piece3, piece4, piece5;
    cin >> piece1 >> piece2 >> piece3 >> piece4 >> piece5;
    int pieces[5] = {piece1, piece2, piece3, piece4, piece5};
    bool change = false;
    int counter = 1;
    while (counter != 0) {
        counter = 0;
        for (int i = 0; i < 4; i++) {
            if (pieces[i] > pieces[i+1]) {
                int temp = pieces[i];
                pieces[i] = pieces[i+1];
                pieces[i+1] = temp;
                counter++;
                change = true;
            }
            if (change == true) {
                for (int j = 0; j < 5; j++) {
                    cout << pieces[j];
                    if (j != 4) {
                        cout << " ";
                    }
                    else {
                        cout << endl;
                    }
                }
            }
            change = false;
        }
    }

}