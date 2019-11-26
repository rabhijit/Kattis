#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string initials;
    cin >> name;
    int initial_number = 0;
    for (int i = 0; i < name.size(); i++) {
        if ((int)(name[i]) >= 65 && (int)(name[i]) <= 90) {
            initials[initial_number] = name[i];
            initial_number++;
        }
    }
    for (int j = 0; j < initial_number; j++) {
        cout << initials[j];
    }
}